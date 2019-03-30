#ifndef DATATYPE_H
#define DATATYPE_H

/*
数据类型，封装地图元素
*/

struct Node
{
    enum STATUS
    {
        SELECTED = 0,
        CURRENT,
        CACULATED,
        INClose,
        START,
        END,
        NORMAOL,
        Path
    };

    float f = 0;
    float g = 0;
    float h = 0;
    int status = STATUS::NORMAOL;
    int isNode = 1;
    int x, y;
    Node* next = 0;
    Node* parent = 0;

    void reset()
    {
        f = 0;
        g = 0;
        h = 0;
        status = STATUS::NORMAOL;
        next = 0;
        parent = 0;
    }
};

#endif // DATATYPE_H
