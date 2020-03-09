import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Node {
    public int N;
    public int N_SIZE;
    
    public int [] board;
    public int f;
    public int g;
    public int h;
    public int blank;
    public Node parent;
    public List<Node> nextNodes;

    public Node() {
        this.N = 4;
        this.N_SIZE = this.N * this.N;
        board = new int[N_SIZE];
        nextNodes = new ArrayList<>();
    }

    public void setBoard(int [] initBoard) {
        this.board = initBoard.clone();
          
        for(int i=0; i<N_SIZE; i++) {
            if(board[i] == 0) {
                blank = i;
                break;
            }
        }
    }

    public Node moveBlank(String move) {
        Node newNode = new Node();
        newNode.setBoard(this.board);
        
        int x_b = blank/N;
        int y_b = blank%N;
        int indx;

        if(move.equals("L")) {
            if(y_b == 0) return this;
            indx = N * x_b + (y_b - 1);
        }
        else if(move.equals("R")) {
            if(y_b == N-1) return this;
            indx = N * x_b + (y_b + 1);
        }
        else if(move.equals("U")) {
            if(x_b == 0) return this;
            indx = N * (x_b - 1) + y_b;
        }
        else if(move.equals("D")) {
            if(x_b == N-1) return this;
            indx = N * (x_b + 1) + y_b;
        }
        else return this;

        newNode.board[blank] = this.board[indx];
        newNode.board[indx] = 0;
        newNode.blank = indx;

        newNode.parent = this;
        newNode.g = this.g + 1;
        newNode.h = Heuristic.getDistance(newNode);
        newNode.f = newNode.g + newNode.h;

        return newNode;
    }

    public void generateNodes() {
        Node tmp = moveBlank("L");
        if(tmp!=this) nextNodes.add(tmp);

        tmp = moveBlank("R");
        if(tmp!=this) nextNodes.add(tmp);

        tmp = moveBlank("U");
        if(tmp!=this) nextNodes.add(tmp);

        tmp = moveBlank("D");
        if(tmp!=this) nextNodes.add(tmp);

    }

    public boolean isSameConfig(Node node) {
        return Arrays.equals(this.board, node.board);
    }

    public boolean isGoal() {
        int [] goal = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
        return Arrays.equals(this.board, goal);
    }

    public boolean isSolvable() {

        int x_b = blank/N;

        // Count number of inversions
        int count_inv = 0;
        for(int i=0; i<N_SIZE-1; i++)
        {
            for(int j=i+1; j<N_SIZE; j++)
            {
                if(board[i] > board[j] && !(board[i]==0 || board[j]==0)) count_inv++;
            }
        }
        // cout<<count_inv<<endl;
        if((N-x_b)%2==0 && count_inv%2!=0) return true;
        if((N-x_b)%2!=0 && count_inv%2==0) return true;

        return false;
    }

    public void printBoard()
    {
        for(int i=0; i<this.N; i++)
        {
            for(int j=0; j<this.N; j++)
            {
                int indx = i*this.N+j;
                
                if(board[indx]!=0) System.out.print(String.format("%3s", Integer.toString(board[indx]))+" ");
                else System.out.print(String.format("%3s", " ")+" ");
            }
            System.out.println();
        }
        System.out.println();
    }

    @Override
    public boolean equals(Object obj) {
        boolean ret = false;

        if(obj == this) return true;

        if(obj instanceof Node) {
            Node temp = (Node) obj;
            ret = this.isSameConfig(temp);
        }
        return ret;
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 17 * hash + this.board.hashCode();
        return hash;
    }

}