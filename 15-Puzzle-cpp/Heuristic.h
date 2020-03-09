#ifndef HEURISTIC_H
#define HEURISTIC_H

#include <cstdio>
#include <cmath>

#define HAMMING     1
#define MANHATTAN   2
#define ERROR   -420

class Node;

namespace Heuristic
{
    extern int htype;
    int hamming(Node &node);
    int manhattan(Node &node);
    int getDistance(Node &node);
};

#endif //HEURISTIC_H