#include <iostream>
#include <vector>
#include <string>
using namespace std;

//  ------------ Edge Class -------------
class Edge {
private:
protected:
public:
    int v = 0;
    int w = 0;
    
    Edge(int v, int w) {
        this->v = v;
        this->w = w;
    }
    
    Edge(int v) {
        this->v = v;
        this->w = 0;
    }

    Edge() {
        //  default
    }
};

//  ----------------- graph -------------------
vector<vector<Edge*>> graph(23);

//  for undirected weighted
void addEdge(int u, int v, int w) {
    if (u < 0 || u >= graph.size() || v < 0 || v >= graph.size()) {
        return;
    }
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

//  ==============================================================================================
/** 
 * Articulaion points and brides
*/
// ** pair = [low(changes if powerful found) / disc(never change)]
vector<int> low(graph.size(), -1);      //  low time
vector<int> disc(graph.size(), -1);     //  discovery time
vector<bool> AP_points(graph.size(), false);
vector<pair<int, int>> AP_Edges;
// vector<bool> visited(graph.size(), false);  //  discovery time (disc) can be used to check the same thing as default is -1
int time_ = 0;    //  for starting point
int callForRoot = 0;        //  root might give wrong ans, so if root is called for more than once, its an Articulation point

//  we take parent(par) as this is not a unidirectional graph, so we need to not include parent for visited check for comparing low
//  osrc is original source for root checking
void dfs_AP(int src, int par, int osrc) {
    disc[src] = time_;
    low[src] = time_;
    time_++;
    for (Edge* e : graph[src]) {
        if (disc[e->v] == -1) {     //  not visited
            //  checking for root
            if (src == osrc) {
                callForRoot++;      //  root called
            }
            //  simple dfs call
            dfs_AP(e->v, src, osrc);
            if (disc[src] <= low[e->v]) {       //  AP point check
                AP_points[src] = true;      //  AP points
            }
            if (disc[src] < low[e->v]) {        //  AP Edge check
                AP_Edges.push_back({src, e->v});      // AP edges
            }
            //  comparing ans copying step after recursion backtracking
            low[src] = min(low[src], low[e->v]);        //  src copying low of its childs if have smaller low
        } else if (e->v != par) {       //  visited vtx ..is / is not.. parent
            //  visited ( and is not parent)
            low[src] = min(low[src], disc[e->v]);
            //  region of backedge
        }
    }
}

void AP_driver() {
    dfs_AP(0, -1, 0);
    cout << "articulation points are : ";
    if (callForRoot > 1) {
        cout << 0 << " ";
    }
    for (int i = 1; i < AP_points.size(); i++) {
        if (AP_points[i]) {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << "articulation bridges are : " << endl;
    for (pair<int, int> p : AP_Edges) {
        cout << p.first << "--" << p.second << endl;
    }
}

//  ==============================================================================================

//  ----------- main -------------
void constructGraph() {
    int tot_vert = 23;
    for (int i = 0; i < tot_vert; i++) {
        graph[i] = vector<Edge*>();
    }

    //  graph 1
    addEdge(0, 2, 0);
    addEdge(1, 3, 0);
    addEdge(0, 1, 0);
    addEdge(1, 2, 0);
    addEdge(2, 3, 0);
    addEdge(0, 3, 0);
    addEdge(3, 6, 0);
    addEdge(4, 6, 0);
    addEdge(4, 5, 0);
    addEdge(5, 6, 0);
    addEdge(6, 7, 0);
    addEdge(6, 8, 0);
    addEdge(8, 7, 0);
    addEdge(8, 9, 0);
    addEdge(6, 10, 0);
    addEdge(10, 11, 0);
    addEdge(10, 13, 0);
    addEdge(11, 12, 0);
    addEdge(13, 12, 0);
    addEdge(12, 14, 0);
    addEdge(14, 16, 0);
    addEdge(14, 18, 0);
    addEdge(16, 15, 0);
    addEdge(16, 17, 0);
    addEdge(15, 17, 0);
    addEdge(15, 18, 0);
    addEdge(16, 18, 0);
    addEdge(18, 22, 0);
    addEdge(18, 19, 0);
    addEdge(22, 20, 0);
    addEdge(22, 21, 0);
    addEdge(20, 21, 0);

    //  graph 2
    // addEdge(0, 1, 11);
    // addEdge(0, 3, 10);
    // addEdge(1, 2, 20);
    // addEdge(2, 3, 40);
    // addEdge(3, 4, 2);
    // addEdge(4, 5, 2);
    // addEdge(4, 6, 3);
    // addEdge(5, 6, 8);
}

void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " -> ";
        for (Edge* e : graph[i]) {
            cout << "(" << e->v << ", " << e->w<< ") ";
        }
        cout << endl;
    }
    cout << endl;
}

int main(int args, char**argv) {
    constructGraph();
    display();
    AP_driver();
    return 0;
}