#ifndef ASTAR_H
#define ASTAR_H

#include "DataType.h"
#include <QVector>
#include <QTimer>
/**
 * @brief The AStar class
 * a star path finding.
 */
class AStar : public QObject
{
    Q_OBJECT
public:
    AStar(int edge, int row, int column, int timeout, QVector<Node*> *nodeList, QObject* parent= Q_NULLPTR);
    ~AStar();
    int findPathBetweenTwoPos(int x1, int y1, int x2, int y2);
private:
    QVector<Node*> *m_nodeList;
    QVector<Node*> *m_openList;
    QVector<Node*> *m_closeList;
    int m_timeout;
    int **graph;
    int m_row, m_column;
    int m_edge;
    int m_bevelEdge;
    Node* startPos;
    Node* endPos;
    QTimer m_timer;
    int m_heuristicType;
private:
    Node* getNodeByXAndYInList(int x, int y);
    Node* getMinF(QVector<Node*> *list);
    void check(Node* cur);
    void checkNodeWithXAndY(int x, int y, Node* parent, int weight);
    static bool compare(Node* n1, Node* n2);
    int countGHF(Node* node, int weight);
    void showPath(Node* node);

    float getTies(Node* node);
    int HeuristicFunc(Node* node, int flag);

private slots:
    void timer_slots();
private:
    enum HeuristicFuncType {
        ManhattanDistance = 0,
        DiagonalDistance,
        EuclidDistance,
        SquareEuclidDistance,
        Dijkstra,
        BreakingTies,
    };
};

#endif // ASTAR_H
