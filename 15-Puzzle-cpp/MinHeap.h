#ifndef MINHEAP_H
#define MINHEAP_H

#include "Node.h"
#include <vector>
#include <algorithm>

class CompareNode
{
    public:
    CompareNode(){}
    bool operator() (const Node &lhs, const Node &rhs) const
    {
        return (lhs.f > rhs.f);
    }
};

class MinHeap
{
    private:
        vector<Node> heap;
        CompareNode cb;
    public:
        MinHeap();
        void push(Node &b);
        void pop();
        Node& top();
        bool empty();
        size_t size();
        size_t count(Node &b);
        vector<Node>::iterator find(const Node &b);
        bool adjust(Node &node);
};

#endif // MINHEAP_H