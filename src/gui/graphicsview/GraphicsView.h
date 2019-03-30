//
// Created by Agilex-tack on 2018/8/2.
//

#ifndef PROJECT_MAPVIEWINGROUP_H
#define PROJECT_MAPVIEWINGROUP_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QResizeEvent>

/**
 * 地图控件类
 * 用于显示地图、AMR等元素
 * 实时刷新
 */
class GraphicsView : public QGraphicsView {
Q_OBJECT
public:
    explicit GraphicsView(QWidget *parent = Q_NULLPTR);

    ~GraphicsView();

    void addGraphicsItem(QGraphicsItem *item);

    void zoomIn();

    void zoomOut();

    void zoom(float scaleFactor);

    void updateView();

    void clear();
signals:
    void itemMapLoad(int x);

    void itemMapLoad(bool x);

    void itemMapUnLoad(int x);

    void itemMapUnLoad(bool x);

public slots:

    void itemMapInit();

    void defaultMap();

public:
    bool m_mapOn;
    QGraphicsScene *m_scene;

    int m_mapHeight;
    int m_mapWidth;

private:
    int m_viewHeight;
    int m_viewWidth;
    int m_zValue = 0;
    qreal m_scale;
    qreal m_zoomDelta;
    qreal m_translateSpeed;  // 平移速度
    QPoint m_lastMousePos;
    bool m_bMouseTranslate;
    Qt::MouseButton m_translateButton;
protected:
    void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;

    void wheelEvent(QWheelEvent *event) Q_DECL_OVERRIDE;

    void resizeEvent(QResizeEvent *event);

    void translate(QPointF delta);
};


#endif //PROJECT_MAPVIEWINGROUP_H
