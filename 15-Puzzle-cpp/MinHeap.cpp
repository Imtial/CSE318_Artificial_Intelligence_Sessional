#include "MinHeap.h"

MinHeap::MinHeap()
{
    make_heap(heap.begin(), heap.end(), cb);
}

void MinHeap::push(Node * node)
{
    heap.push_back(node);
    push_heap(heap.begin(), heap.end(), cb);
}

void MinHeap::pop()
{
    pop_heap(heap.begin(), heap.end(), cb);
    heap.pop_back();
}

Node* MinHeap::top()
{
    return heap.front();
}

bool MinHeap::empty()
{
    return heap.empty();
}

size_t MinHeap::size()
{
    return heap.size();
}

size_t MinHeap::count(Node * node)
{
    size_t count = 0;
    for(vector<Node*>::iterator it=heap.begin(); it!=heap.end(); ++it)
    {
        if(*(*it) == *node) count++;
    }
    return count;
}

bool MinHeap::adjust(Node * node)
{
    bool isAdjusted = false;
    bool nodeFound = false;

    Node * actual_node;
    for(vector<Node*>::iterator it=heap.begin(); it!=heap.end(); ++it)
    {
        if(*node == *(*it))
        {
            actual_node = *it;
            nodeFound = true;
        }
    }
    
    if(!nodeFound) push(node);
    else
    {
        if(node->g < actual_node->g)
        {
            actual_node->g = node->g;
            actual_node->f = node->f;
            actual_node->parent = node->parent;

            make_heap(heap.begin(), heap.end(), cb);
            isAdjusted = true;
        }
    }
    return isAdjusted;
}

void MinHeap::printHeap()
{
    for(vector<Node*>::iterator it=heap.begin(); it!=heap.end(); ++it)
    {
        cout<<(*it)->f<<" ";
    }
    cout<<endl;
}
