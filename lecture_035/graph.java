// package lecture_035;
import java.util.Scanner;
import java.util.ArrayList;
/**
 * graph
 */
public class graph {
    public static Scanner scn = new Scanner(System.in);
    @SuppressWarnings("unchecked")              //  remove XLint warning
    public static ArrayList<Edge>[] graph = new ArrayList[7];                               //  static graph for all
    // public static ArrayList<ArrayList<Edge>> graph = new List<ArrayList<Edge>>();           //  dynamic graph for all

    //  ----------------------------------- main -----------------------------------
    public static void main(String[] args) {
        case1();
        addEdge(0,3,10);
        addEdge(0, 0, 10);
        addEdge(1,0,10);
        addEdge(1,2,10);
        addEdge(2,3,40);
        addEdge(3,4,2);
        addEdge(4,5,2);
        addEdge(4,6,8);
        addEdge(5,6,3);
        display();
        System.out.println();
        // System.out.println(hasSinglePath(0, 6, new boolean[graph.length], 0 + ""));
        System.out.println(hasMultiPath(0, 6, new boolean[graph.length], 0 + ""));
        // removeEdge(3, 4);
        // display();
        // removeVtx(6);
        // display();
    }

    //  -------------------------------- edge class --------------------------------
    public static class Edge {
        int vertex = 0;
        int weight = 0;
        Edge(int vertex, int weight) {
            this.vertex = vertex;
            this.weight = weight;
        }
        // Edge(int vertex) {
        //     this.vertex = vertex;
        // }
        Edge() {
            //  default
        }
    }

    public static void addEdge(int u, int v, int w) {
        if (u < 0 || v < 0 || u >= graph.length || v >= graph.length) {
            return;
        }
        if (u == v) {
            graph[u].add(new Edge(v, w));
            return;
        }
        graph[u].add(new Edge(v, w));
        graph[v].add(new Edge(u, w));
    }

    public static void case1() {        //  initialising arraylist for fixed number of vertices case (using array)
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Edge>();
        }
    }

    /*
    //  initialising arraylist of arraylist for dynamic number of vertices case (using arraylist)
    public static void case2() {
        for (int i =0; i < 7; i++) {
            graph.add(new ArrayList<Edge>());
        }
    }
    */

    public static void display() {
        for (int i = 0; i < graph.length; i++) {
            System.out.print(i + " => [ ");
            for (int j = 0; j < graph[i].size(); j++) {
                System.out.print("(" + graph[i].get(j).vertex + ", " + graph[i].get(j).weight + ")");
            }
            System.out.println(" ]");
        }
    }

    public static void removeEdge(int u , int v) {
        //  for u side links
        int i = -1;
        for (int k = 0; k < graph[u].size(); k++) {
            if (graph[u].get(k).vertex == v) {
                i = k;
                break;
            }
        }
        graph[u].remove(i);
        //  for v side links
        int j = -1;
        for (int k = 0; k < graph[v].size(); k++) {
            if (graph[v].get(k).vertex == u) {
                j = k;
                break;
            }
        }
        graph[v].remove(j);
    }

    public static void removeVtx(int u) {
        for (int i = graph[u].size() - 1; i >= 0; i--) {
            removeEdge(u, graph[u].get(i).vertex);
        }
    }

    public static boolean hasSinglePath(int src, int des, boolean[] visited, String ans) {
        if (src == des) {
            System.out.println(ans);
            return true;
        }
        boolean flag = false;
        for (Edge ed : graph[src]) {
            if (!visited[ed.vertex]) {
                visited[ed.vertex] = true;
                flag = flag || hasSinglePath(ed.vertex, des, visited, ans + "->" + ed.vertex);
            }
        }
        return flag;
    }

    public static boolean hasMultiPath(int src, int des, boolean[] visited, String ans) {
        if (visited[src]) {
            return false;
        }
        if (src == des) {
            System.out.println(ans);
            return true;
        }
        visited[src] = true;
        boolean flag = false;
        // boolean toReturn = false;
        for (Edge ed : graph[src]) {
            flag = hasMultiPath(ed.vertex, des, visited, ans + "->" + ed.vertex);
            // if (flag) {
            //     toReturn = flag;
            // }
        }
        visited[src] = false;
        // return toReturn;
        return flag;
    }
}