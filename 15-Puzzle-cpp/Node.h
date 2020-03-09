#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <iomanip>  /*std::set(int n)*/
#include <cstdio>
#include <vector>
using namespace std;

#define N   4
#define N_SQR   16
#define L   -1
#define R   1
#define U   2
#define D   -2
#define PADDING 3

class Node
{
    public:
        uint8_t board[N_SQR];
        Node * parent;
        int f, g, h;
        uint8_t blank;
        vector<Node> nextNodes;

        Node(int * init_board);
        Node(uint8_t * init_board);
        bool isSolvable();
        Node * moveBlank(int move);
        void generateNodes();
        bool operator==(const Node &rhs) const;
        bool operator!=(const Node &rhs) const;
        friend ostream & operator<<(ostream &out, const Node &node);

};

#endif //NODE_H