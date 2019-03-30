#include "AStar.h"
#include "MainWindow.h"
#include <math.h>
#include <windows.h>
#include <QStack>
#include <algorithm>
#include <QCoreApplication>
#include <QTime>

AStar::AStar(int edge, int row, int column, int timeout, QVector<Node*> *nodeList, QObject *parent)
    : m_timeout(timeout), m_nodeList(nodeList), m_row(row), m_column(column), m_edge(edge), QObject(parent)
{
    m_bevelEdge = sqrt(m_edge*m_edge*2);
    m_openList = new QVector<Node*>();
    m_closeList = new QVector<Node*>();
    connect(&m_timer, SIGNAL(timeout()), this, SLOT(timer_slots()));
}

AStar::~AStar()
{
    if (m_timer.isActive())
    {
        m_timer.stop();
    }
    if (m_openList)
    {
        m_openList->clear();
        delete m_openList;
        m_openList = 0;
    }
    if (m_closeList)
    {
        m_closeList->clear();
        delete m_closeList;
        m_closeList = 0;
    }
}

int AStar::findPathBetweenTwoPos(int x1, int y1, int x2, int y2)
{
    Node* startPos = getNodeByXAndYInList(x1, y1);
    Node* endPos = getNodeByXAndYInList(x2, y2);

    m_heuristicType = gUiService->getHeuristicType();
    QStringList qsl = {"曼哈顿距离", "对角线距离", "欧几里得距离", "平方欧几里得距离", "Dijkstra", "Breaking ties"};
    gUiService->showLog(qsl[m_heuristicType]);
    gUiService->showLog("get start pos and end pos finished.");

    if (!startPos || !endPos) return 0;
    this->startPos = startPos;
    this->endPos = endPos;
    startPos->status = Node::START;
    endPos->status = Node::END;
    m_openList->append(startPos);

    if (m_timer.isActive())
    {
        m_timer.stop();
    }
    m_timer.start(m_timeout);
}

Node *AStar::getNodeByXAndYInList(int x, int y)
{
    QVector<Node*>::iterator it = m_nodeList->begin();
    while (it != m_nodeList->end()) {
        if ((*it)->x == x && (*it)->y == y) {
            return *it;
        }
        it++;
    }
    return 0;
}

Node *AStar::getMinF(QVector<Node *> *list)
{
    if (list->count() == 0) return 0;
    if (list->count() == 1) return (*list)[0];
    int min = 0;
    for (int i = 0; i < list->count() - 1; i++)
    {
        if ((*list)[i]->f < (*list)[min]->f)
        {
            min = i;
        }
    }
    return (*list)[min];
}

void AStar::check(Node *cur)
{
    /*检测相邻点*/
    checkNodeWithXAndY(cur->x - 1, cur->y - 1, cur, m_bevelEdge);
    checkNodeWithXAndY(cur->x, cur->y - 1, cur, m_edge);
    checkNodeWithXAndY(cur->x + 1, cur->y - 1, cur, m_bevelEdge);
    checkNodeWithXAndY(cur->x - 1, cur->y, cur, m_edge);
    checkNodeWithXAndY(cur->x + 1, cur->y, cur, m_edge);
    checkNodeWithXAndY(cur->x - 1, cur->y + 1, cur, m_bevelEdge);
    checkNodeWithXAndY(cur->x, cur->y + 1, cur, m_edge);
    checkNodeWithXAndY(cur->x + 1, cur->y + 1, cur, m_bevelEdge);
}

void AStar::checkNodeWithXAndY(int x, int y, Node *parent, int weight)
{
    Node* node = getNodeByXAndYInList(x, y);
    if (!node || !node->isNode) return;
    if (m_closeList->indexOf(node) != -1) return;
    node->status = Node::CACULATED;
    if (m_openList->indexOf(node) != -1) /*node已存在open列表中*/
    {
        if (node->g > parent->g + weight) /*判断parent路径经过node的花费是否缩短，缩短则node纳入路径，更新ghf*/
        {
            node->parent = parent;
            node->g = parent->g + weight;
            node->f = node->g + node->h;
        }
    }
    else /*node不存在于open列表中*/
    {
        node->parent = parent;
        countGHF(node, weight);
        m_openList->append(node);
    }
}

bool AStar::compare(Node *n1, Node *n2)
{
    if (n1->f == n2->f) /*f相同时判断h*/
    {
        return n1->h < n2->h;
    }
    else
        return n1->f < n2->f;
}

int AStar::countGHF(Node *node, int weight)
{
    /*计算node到endPos的预算距离*/
    float h = 0;
    h = this->HeuristicFunc(node, m_heuristicType);  /*指定启发函数类型*/
    int dx1 = node->x - endPos->x;
    int dy1 = node->y - endPos->y;
    int dx2 = startPos->x - endPos->x;
    int dy2 = startPos->y - endPos->y;
    h += abs(dx1*dy2 - dx2*dy1)*0.001;  /*加上尾部，精确f*/

    /*父节点到node的花费，即当前计算节点到node的花费*/
    float cuurentg = node->parent->g + weight;
    float f = cuurentg + h;
    node->f = f;
    node->h = h;
    node->g = cuurentg;
}

void AStar::showPath(Node *node)
{
    QStack<Node*> path;
    int dis = node->g;
    while (node)
    {
        node->status = Node::Path;
        path.push(node);
        node = node->parent;
    }
    QString qsPath = "路径:";
    while (!path.empty()) {
        qsPath += QString("->(%1,%2)").arg(path.top()->x).arg(path.top()->y);
        path.pop();
    }
    qsPath += QString("距离:(%1)").arg(dis);
    gUiService->updateView();
    gUiService->showLog(qsPath);
}

float AStar::getTies(Node *node)
{
    int dx1 = node->x - endPos->x;
    int dy1 = node->y - endPos->y;
    int dx2 = startPos->x - endPos->x;
    int dy2 = startPos->y - endPos->y;
    float  cross = abs(dx1*dy2-dx2*dy1);
    return cross*0.001;
}

int AStar::HeuristicFunc(Node *node, int flag)
{
    int dx = abs(node->x - endPos->x);
    int dy = abs(node->y - endPos->y);

    if (flag == HeuristicFuncType::ManhattanDistance)
    {
        return (dx + dy)*m_edge;
    }
    if (flag == HeuristicFuncType::DiagonalDistance)
    {
        return m_edge*(dx + dy) + (m_bevelEdge - 2*m_edge)*std::min(dx, dy);
    }
    if (flag == HeuristicFuncType::EuclidDistance)
    {
        return m_edge*std::sqrt(dx*dx + dy*dy);
    }
    if (flag == HeuristicFuncType::SquareEuclidDistance)
    {
        return m_edge*(dx*dx + dy*dy);
    }
    if (flag == HeuristicFuncType::Dijkstra)
    {
        return 0;
    }

    return 0;
}


void AStar::timer_slots()
{
    if (m_openList->count() == 0)
    {
        m_timer.stop();
        gUiService->showLog("无法找到终点");
        return;
    }

    Node* cur = (*m_openList)[0];
    cur->status = Node::CURRENT;

    if (cur->x == endPos->x && cur->y == endPos->y)
    {
        gUiService->showLog("已找到路径");
        showPath(cur);
        m_openList->clear();
        m_closeList->clear();
        m_timer.stop();
        return;
    }
    gUiService->updateView();
    QTime dieTime = QTime::currentTime().addMSecs(m_timeout);

    while( QTime::currentTime() < dieTime )

        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

    check(cur);
    cur->status = Node::INClose;
    m_closeList->push_back(cur);
    m_openList->removeOne(cur);
    qSort(m_openList->begin(), m_openList->end(), compare); /*每次结束时按照f从大到小排序*/
    gUiService->updateView();
}
