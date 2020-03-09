#include "Node.h"
#include "Heuristic.h"
#include "AStar.h"

int main()
{
    printf("15-Puzzle using A* algorithm\n");
    // int b[] = {6, 13, 7, 10, 8, 9, 11, 0, 15, 2, 12, 5, 14, 3, 1, 4};
    int b[] = {0, 1, 2, 3, 5, 6, 7, 4, 9, 10, 11, 8, 13, 14, 15, 12};
    AStar * astar;
    Node * start;
    
    Heuristic::htype = MANHATTAN;
    start = new Node(b);
    astar = new AStar();
    astar->open_list.push(*start);
    astar->search();
    // delete astar;
    // delete start;

    // Heuristic::htype = HAMMING;
    // start = new Node(b);
    // astar = new AStar();
    // astar->open_list.push(*start);
    // astar->search();
    // delete astar;
    // delete start;
}