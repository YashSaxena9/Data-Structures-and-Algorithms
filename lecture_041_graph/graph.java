import java.util.ArrayList;
import java.util.LinkedList;
/**
 * graph
 */
public class graph {
    
    //  ----------------- graph -------------------
    public static ArrayList<ArrayList<Edge>> graph = new ArrayList<>();
    
    public static void main(String[] args) {
        constructGraph();
        display();
        // removeEdge(4, 5);
        removeVertex(3);
        display();
        queue<Edge> arr = new LinkedList<>();
    }
    public static void constructGraph() {
        int tot_vert = 7;       //  size of graph
        //  initialising graph as it points to null
        for (int i = 0; i < tot_vert; i++) {
            graph.add(new ArrayList<>());
        }
        addEdge(0, 1, 10);
        addEdge(0, 3, 10);
        addEdge(1, 2, 10);
        addEdge(2, 3, 40);
        addEdge(3, 4, 2);
        addEdge(4, 5, 2);
        addEdge(4, 6, 3);
        addEdge(5, 6, 8);
    }

    //  -------------------- Edge Class ----------------------

    public static class Edge {
        int v = 0;      //  vertex
        int w = 0;      //  weight

        Edge(int v, int w) {
            this.v = v;
            this.w = w;
        }
        Edge() {
            //  default
        }
    }

    //  --------------------- methods ----------------------
    public static void display() {
        for (int i = 0; i < graph.size(); i++) {
            System.out.print(i + " -> ");
            for (Edge e : graph.get(i)) {
                System.out.print("(" + e.v + ", " + e.w + ") ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public static void addEdge(int u, int v, int w) {
        if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size()) {
            return;
        }
        graph.get(u).add(new Edge(v, w));
        graph.get(v).add(new Edge(u, w));
    }

    public static void removeEdge(int u, int v) {
        //  method 1
        int i = 0;
        while (i < graph.get(u).size()) {
            Edge e = graph.get(u).get(i);
            if (e.v == v) {
                break;
            }
            i++;
        }
        graph.get(u).remove(i);
        
        //  method 2
        for (int j = graph.get(v).size() - 1; j >= 0; j--) {
            if (graph.get(v).get(j).v == u) {
                graph.get(v).remove(j);
                break;
            }
        }
    }

    public static void removeVertex(int u) {
        int size = graph.get(u).size();
        /* 
        while (graph.get(u).size() != 0) {
            int i = graph.get(u).size() - 1;
            Edge e = graph.get(u).get(i);
            removeEdge(u, e.v);
        }
        */
        for (int i = size - 1; i >= 0; i--) {
            removeEdge(u, graph.get(u).get(i).v);
        }
        // graph.remove(u);                      //  in java
        // graph.erase(graph.begin() + u);         //  in c++
    }
}