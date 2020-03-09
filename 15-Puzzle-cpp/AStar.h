#ifndef ASTAR_H
#define ASTAR_H

#include "MinHeap.h"
#include <list>

class AStar
{
    private:
        Node * goal;
        list<Node> closed_list;
    public:

        MinHeap open_list;
        AStar();
        AStar(int * init_goal);
        void search();
        void path(Node * node);
};

#endif