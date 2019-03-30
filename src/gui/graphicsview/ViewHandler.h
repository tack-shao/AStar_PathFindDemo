#ifndef VIEWHANDLER_H
#define VIEWHANDLER_H

#include "DataType.h"
#include <QVector>

class GraphicsView;
class AStar;

class ViewHandler
{
public:
    ViewHandler(GraphicsView* view = Q_NULLPTR);
    ~ViewHandler();

    GraphicsView* getGraphicsView();

    void updateView();

    void newRanMap(int row, int column, int width, int percent, int time);

    void clear();

    void clearPath();

    void findPath();
private:
    GraphicsView* m_pGraphicsView;
    QVector<Node*>* m_nodeList;
    AStar* m_AStar;
};

#endif // VIEWHANDLER_H
