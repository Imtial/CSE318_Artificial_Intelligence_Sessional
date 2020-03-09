import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        
        // int [] s = {0,1,2,3,5,6,7,4,9,10,11,8,13,14,15,12};
        // int [] s = {6, 13, 7, 10, 8, 9, 11, 0, 15, 2, 12, 5, 14, 3, 1, 4};
        Scanner scanner = new Scanner(new File("input.txt"));
        int [] s = new int [16];
        int n = 0;
        if(scanner.hasNextInt()) n = scanner.nextInt();
        for(int j=1; j<=n; j++) {
            System.out.println("CASE #"+j);
            for(int i=0; i<16; i++) {
                if(scanner.hasNextInt()) s[i] = scanner.nextInt();
            }
            Node start = new Node();
            start.setBoard(s);
            // start.printBoard();
            Heuristic.t = Heuristic.MANHATTAN;
            System.out.println("USING MANHATTAN DISTANCE");
            if(start.isSolvable()) new AStar(start).search();
            else System.out.println("NOT SOLVABLE");

            // start = new Node();
            // start.setBoard(s);
            // Heuristic.t = Heuristic.HAMMING;
            // System.out.println("USING HAMMING DISTANCE");
            // if(start.isSolvable()) new AStar(start).search();
            // else System.out.println("NOT SOLVABLE");
        }
        
        // if(start.isSolvable()) new AStar(start).search();

        scanner.close();
    }
}