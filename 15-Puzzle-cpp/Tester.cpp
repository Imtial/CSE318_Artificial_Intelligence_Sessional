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
    Node start(b);
    CompareNode cn;
    list<Node> clist;
    clist.push_back(start);
    
    list<Node>::iterator it = find(clist.begin(), clist.end(), start);
}