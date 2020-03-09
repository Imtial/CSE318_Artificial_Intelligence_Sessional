public class Heuristic {

    public static final int HAMMING = 1;
    public static final int MANHATTAN = 2;

    public static int t;

    public static int manhattan(Node node)
    {
        int dist = 0;
        for(int i=0; i<node.N_SIZE; i++)
        {
            if(node.board[i]!=i+1 && node.board[i]!=0)
            {
                // int x = (b.board[i]-1)/N;
                // int y = (b.board[i]-1)%N;
                // int tar_x = i/N;
                // int tar_y = i%N;
                dist += Math.abs((node.board[i]-1)/node.N - i/node.N) + Math.abs((node.board[i]-1)%node.N - i%node.N);
            }
        }
        return dist;
    }

    public static int hamming(Node node) {
        int misplaced_tiles = 0;
        for(int i=0; i<node.N_SIZE; i++)
        {
            if(node.board[i]!=i+1 && node.board[i]!=0) misplaced_tiles++;
        }
        return misplaced_tiles;
    }

    public static int getDistance(Node node) {
        if(t == HAMMING) return hamming(node);
        else if(t == MANHATTAN) return manhattan(node);
        return -1000;
    }
}