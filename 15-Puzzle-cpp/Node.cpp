#include "Node.h"
#include "Heuristic.h"

Node::Node(int * init_board)
{
    for(int i=0; i<N_SQR; i++)
    {
        board[i] = init_board[i];
        if(init_board[i] == 0) blank = i;
    }
    
    parent = NULL;
    g = 0;
    h = Heuristic::getDistance(*this);
    f = g + h;
}

Node::Node(uint8_t * init_board)
{
    for(int i=0; i<N_SQR; i++)
    {
        board[i] = init_board[i];
        if(init_board[i] == 0) blank = i;
    }
    
    parent = NULL;
    g = 0;
    h = Heuristic::getDistance(*this);
    f = g + h;
}

bool Node::isSolvable()
{
    if(blank == -1)
    {
        cout<<"Uninitialized Board"<<endl;
        return false;
    }

    int x_b = blank/N;

    // Count number of inversions
    int count_inv = 0;
    for(int i=0; i<N_SQR-1; i++)
    {
        for(int j=i+1; j<N_SQR; j++)
        {
            if(board[i] > board[j] && !(board[i]==0 || board[j]==0)) count_inv++;
        }
    }
    // cout<<count_inv<<endl;
    if((N-x_b)%2==0 && count_inv%2!=0) return true;
    if((N-x_b)%2!=0 && count_inv%2==0) return true;

    return false;
}

Node* Node::moveBlank(int move)
{   
    int x_b = blank/N;
    int y_b = blank%N;

    int indx;

    if(move == L)
    {
        if(y_b == 0) return this;
        indx = N * x_b + (y_b - 1);
    }
    else if(move == R)
    {
        if(y_b == N-1) return this;
        indx = N * x_b + (y_b + 1);
    }
    else if(move == U)
    {
        if(x_b == 0) return this;
        indx = N * (x_b - 1) + y_b;
    }
    else if(move == D)
    {
        if(x_b == N-1) return this;
        indx = N * (x_b + 1) + y_b;
    }
    else
    {
        cout<<"Invalid move"<<endl;
        return this;
    }

    Node * newNode = new Node(this->board);

    newNode->board[blank] = board[indx];
    newNode->board[indx] = 0;
    newNode->blank = indx;

    newNode->parent = this;
    newNode->g = newNode->parent->g + 1;
    // newNode->h already calculated in the constructor
    newNode->f = newNode->g + newNode->h;

    return newNode;
}

void Node::generateNodes()
{
    Node * tmp = moveBlank(L);
    if(tmp != this)
    {
        nextNodes.push_back(*tmp);
        // delete tmp;
    }

    tmp = moveBlank(R);
    if(tmp != this)
    {
        nextNodes.push_back(*tmp);
        // delete tmp;
    }

    tmp = moveBlank(U);
    if(tmp != this)
    {
        nextNodes.push_back(*tmp);
        // delete tmp;
    }

    tmp = moveBlank(D);
    if(tmp != this)
    {
        nextNodes.push_back(*tmp);
        // delete tmp;
    }
}

bool Node::operator==(const Node &rhs) const
{
    uint8_t const *lp, *rp, *end=this->board+N_SQR;

    for(lp=this->board, rp=rhs.board; lp!=end; ++lp, ++rp)
    {
        if(lp == NULL || rp == NULL) return false;
        if(*lp != *rp) return false;
    }
    return true;
}

bool Node::operator!=(const Node &rhs) const
{
    uint8_t const *lp, *rp, *end=this->board+N_SQR;

    for(lp=this->board, rp=rhs.board; lp!=end; ++lp, ++rp)
    {
        if(lp == NULL || rp == NULL) return true;
        if(*lp != *rp) return true;
    }
    return false;
}

ostream & operator<<(ostream &out, const Node &node)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            int indx = i * N + j;
            if(node.board[indx] != 0) out<<std::setw(PADDING)<<to_string(node.board[indx]);
            out<<std::setw(PADDING);
        }
        out<<endl;
    }
    return out;
}