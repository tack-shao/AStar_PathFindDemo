#ifndef CHIP_H
#define CHIP_H

#include <QGraphicsItem>
#include "DataType.h"


class Chip : public QGraphicsItem
{
public:
    Chip(Node* node, int edge, QGraphicsItem* parent = Q_NULLPTR);

    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    static Node* getStartNode();
    static Node* getEndNode();
    static void clear();
private:
    int m_edge;
    Node* m_node = NULL;
    int m_clickNum;
    static int selectedNum;
    static QVector<Node*> selectNodes;
};

#endif // CHIP_H
