#include "AStar.h"

AStar::AStar()
{
    int init_goal [] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0};
    goal = new Node(init_goal);
}

AStar::AStar(int * init_goal)
{
    goal = new Node(init_goal);
}

void AStar::search()
{
    while(!open_list.empty())
    {
        Node * process = open_list.top();
        // cout<<"***********************"<<endl;
        // cout<<"f="<<process->f<<",g="<<process->g<<",h="<<process->h<<endl;
        // cout<<*process;
        // cout<<"["<<open_list.size()<<","<<closed_list.size()<<"] ";
        if(*process == *goal)
        {
            cout<<"PATH COST: "<<process->g<<endl;
            cout<<"NODE EXPLORED: "<<closed_list.size()<<endl;
            // path(process);
            return;
        }
        closed_list.push_back(*process);
        process->generateNodes();
        open_list.pop();

        for(vector<Node>::iterator node=process->nextNodes.begin(); node!=process->nextNodes.end(); ++node)
        {   
            list<Node>::iterator it = find(closed_list.begin(), closed_list.end(), (Node&)node);
            if(it != closed_list.end()) continue;

            open_list.adjust(&(*node));
        }
    }
}

// FIXME - Wrong output
void AStar::path(Node * node)
{
    if(node == NULL) return;
    
    path(node->parent);
    cout<<*node<<endl;
}
