/* #include <iostream>
#include <vector>
using namespace std;

class Node
{
    public:
        int id;
        Node * next;

        Node(int id)
        {
            this->id = id;
        }
};

int main()
{
    vector<Node*> ptrList;

    Node n1(1), n2(2), n3(3);

    ptrList.push_back(&n1);
    ptrList.push_back(&n2);
    ptrList.push_back(&n3);
    ptrList.push_back(NULL);

    for(vector<Node*>::iterator it=ptrList.begin(); it!=ptrList.end(); ++it)
    {
        if((*it) == NULL) cout<<"NULL"<<endl;
        else cout<<(*it)->id<<endl;
    }
    return 0;
} */

#include "Heuristic.h"
#include "Node.h"
#include "MinHeap.h"
#include <list>
#include <algorithm>

int main()
{
    int b[] = {6, 13, 7, 10, 8, 9, 11, 0, 15, 2, 12, 5, 14, 3, 1, 4};
    int c[] = {6, 13, 7, 10, 8, 9, 11, 14, 15, 2, 12, 5, 0, 3, 1, 4};
    int d[] = {5, 1, 3, 12, 0, 7, 9, 2, 6, 10, 15, 4, 13, 14, 8, 11};
    int e[] = {5, 3, 9, 11, 7, 10, 15, 4, 2, 14, 12, 1, 6, 13, 8, 0};
    
    MinHeap open;
    Heuristic::htype = MANHATTAN;
    Node * n1 = new Node(b);
    Node * n2 = new Node(c);
    Node * n3 = new Node(d);
    Node * n4 = new Node(e);

    cout<<n1->f<<" "<<n2->f<<" "<<n3->f<<" "<<n4->f<<endl;

    open.push(n1);
    open.push(n2);
    open.push(n3);
    open.push(n4);

    open.printHeap();

    while(!open.empty()) 
    {
        cout<<open.top()->f<<endl;
        open.pop();
    }
}