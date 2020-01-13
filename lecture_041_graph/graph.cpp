#include<iostream>
#include<vector>
#include<string>
using namespace std;

//  ------------ Edge Class -------------
class Edge {
private:
public:
    int v = 0;
    int w = 0;
    
    Edge(int v, int w) {
        this->v = v;
        this->w = w;
    }

    Edge() {
        //  default
    }
};

//  ----------------- graph -------------------
vector<vector<Edge*>> graph;

//  --------------------- methods ----------------------
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

void addEdge(int u, int v, int w) {
    if (u < 0 || u >= graph.size() || v < 0 || v >= graph.size()) {
        return;
    }
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

void removeEdge(int u, int v) {
    //  method 1
    int i = 0;
    while (i < graph[u].size()) {
        Edge* e = graph[u][i];
        if (e->v == v) {
            break;
        }
        i++;
    }
    // graph[u].remove(i);
    graph[u].erase(graph[u].begin() + i);
    
    //  method 2
    for (int j = graph[v].size() - 1; j >= 0; j--) {
        if (graph[v][j]->v == u) {
            graph[v].erase(graph[v].begin() + j);
            break;
        }
    }
}

void removeVertex(int u) {
    int size = graph[u].size();
    /* 
    while (graph[u].size() != 0) {
        int i = graph[u].size() - 1;
        Edge* e = graph[u][i];
        removeEdge(u, e->v);
    }
    */
    for (int i = size - 1; i >= 0; i--) {
        removeEdge(u, graph[u][i]->v);
    }
    // graph.remove(u);                      //  in java
    // graph.erase(graph.begin() + u);         //  in c++
}

//  ----------- main -------------
void constructGraph() {
    int tot_vert = 7;
    for (int i = 0; i < tot_vert; i++) {
        graph.push_back(vector<Edge*>());
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

int main(int args, char**argv) {
    constructGraph();
    display();
    removeEdge(4, 5);
    // removeVertex(3);
    display();
    return 0;
}