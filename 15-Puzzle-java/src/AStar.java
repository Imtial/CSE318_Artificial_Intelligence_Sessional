import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class AStar {
    private List<Node> openList;
    private List<Node> closedList;

    public AStar(Node start) {
        this.openList = new ArrayList<>();
        this.closedList = new ArrayList<>();

        start.g = 0;
        start.h = Heuristic.getDistance(start);
        start.f = start.g + start.h;

        openList.add(start);
    }

    public void search() {
        // long beforeUsedMem = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
        while(!openList.isEmpty()) {
            Node process = Collections.min(openList, Comparator.comparing((Node node) -> node.f));

            // System.out.println("f="+process.f+" g="+process.g+" h="+process.h);
            // System.out.println("Mem: "+(openList.size()+closedList.size())+ "["+process.h+"]");

            if(process.isGoal()) {
                System.out.println("Total node explored: "+closedList.size());
                System.out.println("Path Cost: "+process.g);
                path(process);
                return;
            }

            openList.remove(process);
            closedList.add(process);

            process.generateNodes();

            for (Node node : process.nextNodes) {
                if(closedList.contains(node)) continue; else System.out.println("FOUND");
                if(!openList.contains(node)) openList.add(node);
                else {
                    Node actualNode = openList.get(openList.indexOf(node));
                    if(node.g < actualNode.g) {
                        // System.out.println("NOT DUMB");
                        actualNode.g = node.g;
                        actualNode.f = node.f;
                        actualNode.parent = node.parent;
                    }
                }
            }
            // long afterUsedMem = Runtime.getRuntime().totalMemory() - Runtime.getRuntime().freeMemory();
            // System.out.println("MEMORY USED: "+(afterUsedMem-beforeUsedMem));
        }
    }

    public void path(Node node) {
        if(node == null) return;

        path(node.parent);
        node.printBoard();
    }
}