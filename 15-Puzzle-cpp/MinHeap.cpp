#include "MinHeap.h"

MinHeap::MinHeap()
{
    make_heap(heap.begin(), heap.end(), cb);
}

void MinHeap::push(Node &b)
{
    heap.push_back(b);
    push_heap(heap.begin(), heap.end(), cb);
}

void MinHeap::pop()
{
    pop_heap(heap.begin(), heap.end(), cb);
    heap.pop_back();
}

Node& MinHeap::top()
{
    return heap[heap.size()-1];
}

bool MinHeap::empty()
{
    return heap.empty();
}

size_t MinHeap::size()
{
    return heap.size();
}

size_t MinHeap::count(Node &b)
{
    size_t count = 0;
    for(vector<Node>::iterator it=heap.begin(); it!=heap.end(); ++it)
    {
        if(*it == b) count++;
    }
    return count;
}

vector<Node>::iterator MinHeap::find(const Node &b)
{
    for(vector<Node>::iterator it=heap.begin(); it!=heap.end(); ++it)
    {
        if(*it == b) return it;
    }
    return heap.end();
}

bool MinHeap::adjust(Node &node)
{
    bool isAdjusted = false;
    bool nodeFound = false;

    Node * actual_node;
    for(vector<Node>::iterator it=heap.begin(); it!=heap.end(); ++it)
    {
        if(node == *it)
        {
            actual_node = &(*it);
            nodeFound = true;
        }
    }
    
    if(!nodeFound) push(node);
    else
    {
        if(node.g < actual_node->g)
        {
            actual_node->g = node.g;
            actual_node->f = node.f;
            actual_node->parent = node.parent;

            make_heap(heap.begin(), heap.end(), cb);
            isAdjusted = true;
        }
    }
    return isAdjusted;
}
