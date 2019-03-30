//
// Created by Agilex-tack on 2018/8/2.
//
#include "GraphicsView.h"

#define VIEW_CENTER viewport()->rect().center()
#define VIEW_WIDTH  viewport()->rect().width()
#define VIEW_HEIGHT viewport()->rect().height()

void GraphicsView::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == m_translateButton)
    {
        // 当光标底下没有 item 时，才能移动
        QPointF point = mapToScene(event->pos());
//        if (scene()->itemAt(point, transform()) == NULL)  {
            m_bMouseTranslate = true;
            m_lastMousePos = event->pos();
//        }
    }

    QGraphicsView::mousePressEvent(event);
}

void GraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bMouseTranslate)
    {
        QPointF mouseDelta = mapToScene(event->pos()) - mapToScene(m_lastMousePos);
        translate(mouseDelta);
    }

    m_lastMousePos = event->pos();

    QGraphicsView::mouseMoveEvent(event);
}

void GraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == m_translateButton)
        m_bMouseTranslate = false;

    QGraphicsView::mouseReleaseEvent(event);
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
    if (event->modifiers() & Qt::ControlModifier)
    {
        // 滚轮的滚动量
        QPoint scrollAmount = event->angleDelta();
        // 正值表示滚轮远离使用者（放大），负值表示朝向使用者（缩小）
        scrollAmount.y() > 0 ? zoomIn() : zoomOut();
    }
}

GraphicsView::GraphicsView(QWidget *parent) :
    QGraphicsView(parent),
    m_scene(NULL)
{
    // 初始化参数
    m_mapHeight = 0;
    m_mapWidth = 0;
    m_viewHeight = 0;
    m_viewWidth = 0;
    m_mapOn = false;
    m_scale = 1.0;
    m_zoomDelta = 0.1;
    m_bMouseTranslate =false;
    m_translateSpeed = 1.0;
    m_scene = new QGraphicsScene;
    m_scene->setBackgroundBrush(QBrush(Qt::black));
    m_translateButton = Qt::RightButton;
    this->setScene(m_scene);

    setCursor(Qt::PointingHandCursor);
    setRenderHint(QPainter::Antialiasing);

    setSceneRect(INT_MIN/2, INT_MIN/2, INT_MAX, INT_MAX);
    centerOn(0, 0);
}

GraphicsView::~GraphicsView()
{
    if (m_mapOn == true)
    {
        m_mapOn = false;
    }

}


void GraphicsView::itemMapInit()
{

}

void GraphicsView::defaultMap()
{
    if (m_mapOn)
    {
        m_viewHeight = this->geometry().height();
        m_viewWidth = this->geometry().width();
        m_scale = 0.2;

        updateView();
    }
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    //    m_viewHeight = this->geometry().height();                                //获取新的尺寸
    //    m_viewWidth = this->geometry().width();
    //    this->setSceneRect(QRect(0, 0, m_viewWidth - 4, m_viewHeight - 4));    //修改比例和scene尺寸
    //    event->accept();
}

void GraphicsView::translate(QPointF delta)
{
    // 根据当前 zoom 缩放平移数
    delta *= m_scale;
    delta *= m_translateSpeed;

    // view 根据鼠标下的点作为锚点来定位 scene
    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    QPoint newCenter(VIEW_WIDTH / 2 - delta.x(),  VIEW_HEIGHT / 2 - delta.y());
    centerOn(mapToScene(newCenter));

    // scene 在 view 的中心点作为锚点
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
}

void GraphicsView::addGraphicsItem(QGraphicsItem *item)
{
    if (item != NULL)
    {
        m_zValue += 2;
        item->setZValue(m_zValue);
        m_scene->addItem(item);
    }
}

void GraphicsView::zoomIn()
{
    zoom(1 + m_zoomDelta);
}

void GraphicsView::zoomOut()
{
    zoom(1 - m_zoomDelta);
}

void GraphicsView::zoom(float scaleFactor)
{
    // 防止过小或过大
    qreal factor = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();
    if (factor < 0.07 || factor > 100)
        return;

    scale(scaleFactor, scaleFactor);
    m_scale *= scaleFactor;
}

void GraphicsView::updateView()
{
    m_scene->update();
}

void GraphicsView::clear()
{
    m_scene->clear();
}
