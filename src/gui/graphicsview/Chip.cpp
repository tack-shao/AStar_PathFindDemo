#include "Chip.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

int Chip::selectedNum = 0;
QVector<Node*> Chip::selectNodes;
Chip::Chip(Node* node, int edge, QGraphicsItem *parent) : QGraphicsItem(parent)
{
    m_edge = edge;
    m_node = node;
    m_clickNum = 0;
}

QRectF Chip::boundingRect() const
{
    return QRect(0, 0, m_edge, m_edge);
}

void Chip::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    if (!m_node->isNode)
    {
        return;
    }

    QColor color;
    switch (m_node->status)
    {
    case Node::SELECTED:
        color = Qt::green;
        break;
    case Node::CURRENT:
        color = Qt::yellow;
        break;
    case Node::CACULATED:
        color = Qt::blue;
        break;
    case Node::INClose:
        color = Qt::darkGreen;
        break;
    case Node::START:
        color = Qt::red;
        break;
    case Node::END:
        color = Qt::red;
        break;
    case Node::NORMAOL:
        color = QColor::fromRgb(123, 104, 238);
        break;
    case Node::Path:
        color = Qt::red;
        break;
    default:
        break;
    }

    QPen pen;
    pen.setWidth(1);
    pen.setColor(color);
    painter->setPen(pen);
    painter->drawRect(0, 0, m_edge, m_edge);
    if (m_node->status != Node::NORMAOL)
        painter->drawRect(m_edge/20, m_edge/20, m_edge/10*9, m_edge/10*9);

    QPen penOfText;
    penOfText.setWidth(1);
    penOfText.setColor(Qt::white);
    painter->setPen(penOfText);
    QFont font;
    font.setPixelSize(10);
    painter->setFont(font);
    //左上角的F
    painter->drawText(m_edge/10, m_edge/5, QString("%1").arg(m_node->f));
    //左下角的G
    painter->drawText(m_edge/10, m_edge/5*4, QString("%1").arg(m_node->g));
    //右上角的H
    painter->drawText(m_edge/2, m_edge/5*4, QString("%1").arg(m_node->h));
}

void Chip::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->buttons() == Qt::LeftButton )
    {
        if (m_node->isNode)
        {
            m_clickNum++;
            if (m_clickNum == 2)
            {
                m_node->status = Node::NORMAOL;
                m_clickNum = 0;
                selectNodes.removeOne(m_node);
            }
            else
            {
                m_node->status = Node::SELECTED;
                selectNodes.append(m_node);
            }
            update();
        }
    }
}

Node *Chip::getStartNode()
{
    if (selectNodes.count() != 2 && selectNodes.count() != 1)
        return 0;
    return selectNodes[0];
}

Node *Chip::getEndNode()
{
    if (selectNodes.count() != 2)
        return 0;
    return selectNodes[1];
}

void Chip::clear()
{
    selectNodes.clear();
    selectedNum = 0;
}
