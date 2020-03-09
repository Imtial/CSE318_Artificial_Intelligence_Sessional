#include "Node.h"
#include "Heuristic.h"

namespace Heuristic
{
    int htype;

    int hamming(Node &node)
    {
        if(htype != HAMMING)
        {
            printf("ERROR: TYPE MISMATCH INSIDE hamming()\n");
            return ERROR;
        }

        int misplaced_tiles = 0;
        for(int i=0; i<N_SQR; i++)
        {
            if(node.board[i]!=i+1 && node.board[i]!=0) misplaced_tiles++;
        }
        return misplaced_tiles;
    }

    int manhattan(Node &node)
    {
        if(htype != MANHATTAN)
        {
            printf("ERROR: TYPE MISMATCH INSIDE manhattan()\n");
            return ERROR;
        }
        int dist = 0;
        for(int i=0; i<N_SQR; i++)
        {
            if(node.board[i]!=i+1 && node.board[i]!=0)
            {
                // int x = (b.board[i]-1)/N;
                // int y = (b.board[i]-1)%N;
                // int tar_x = i/N;
                // int tar_y = i%N;
                dist += abs((node.board[i]-1)/N - i/N) + abs((node.board[i]-1)%N - i%N);
            }
        }
        return dist;
    }

    int getDistance(Node &node)
    {
        if(htype == HAMMING) return hamming(node);
        else if(htype == MANHATTAN) return manhattan(node);
        else
        {
            printf("ERROR: UNKNOWN TYPE\n");
            return ERROR;
        }
    }
};
