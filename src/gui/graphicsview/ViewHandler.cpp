#include "ViewHandler.h"
#include "GraphicsView.h"
#include "Chip.h"
#include "MainWindow.h"
#include "AStar.h"

ViewHandler::ViewHandler(GraphicsView *view)
{
    m_pGraphicsView = view;
    m_pGraphicsView->itemMapInit();
    m_AStar = 0;
    m_nodeList = 0;
}

ViewHandler::~ViewHandler()
{
    if (m_pGraphicsView)
    {
        delete m_pGraphicsView;
        m_pGraphicsView = 0;
    }
}

GraphicsView *ViewHandler::getGraphicsView()
{
    return m_pGraphicsView;
}

void ViewHandler::updateView()
{
    m_pGraphicsView->updateView();
}

void ViewHandler::newRanMap(int row, int column, int width, int percent, int time)
{
    clear();
    m_nodeList = new QVector<Node*>();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            Node *node = new Node;
            node->x = i;
            node->y = j;
            node->isNode = percent == 0 ? 1 : (percent < (rand()%100) ? 1 : 0);

            QGraphicsItem* item = new Chip(node, width);
            item->setPos(i*width, j*width);
            m_nodeList->append(node);
            m_pGraphicsView->addGraphicsItem(item);
        }
    }
    m_AStar = new AStar(width, row, column, time, m_nodeList);
}

void ViewHandler::clear()
{
    if (m_nodeList)
    {
        qDeleteAll(*m_nodeList);
        delete m_nodeList;
        m_nodeList = 0;
    }
    if (m_pGraphicsView)
    {
        m_pGraphicsView->clear();
    }

    if (m_AStar)
    {
        delete m_AStar;
        m_AStar = 0;
    }
    Chip::clear();
}

void ViewHandler::clearPath()
{
    if (!m_nodeList) return;
    for (int i = 0; i < m_nodeList->count(); i++)
    {
        (*m_nodeList)[i]->reset();
        Chip::clear();
        updateView();
    }
}

void ViewHandler::findPath()
{
    Node* startNode = Chip::getStartNode();
    Node* endNode = Chip::getEndNode();
    if (!startNode)
    {
        gUiService->showLog("起点获取失败");
        return;
    }
    if (!endNode)
    {
        gUiService->showLog("终点获取失败");
        return;
    }

    gUiService->showLog(QString("已选择 起点:(%1, %2) 终点(%3, %4)").arg(startNode->x).arg(startNode->y).arg(endNode->x).arg(endNode->y));
    if (m_AStar)
    {
        m_AStar->findPathBetweenTwoPos(startNode->x, startNode->y, endNode->x, endNode->y);
    }
}
