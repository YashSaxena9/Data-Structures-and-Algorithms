#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* --------------- edge class for vertices -------------- */
class Edge {
    private:
    public:
        int vertex = 0;
        int weight = 0;
        Edge(int vertex, int weight) {
            this->vertex = vertex;
            this->weight = weight;
        }
        Edge() {
            //  default
        }
};

//  required graph storage
vector<vector<Edge*>> graph(7, vector<Edge*>());

/* --------------- functions for graphs -------------- */
void addEdge(int u, int v, int w) {
    if (u < 0 || v < 0 || u >= graph.size() || v >= graph.size()) {
        return;
    }
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

void display() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << " => [";
        for (int j = 0 ; j < graph[i].size(); j++) {
            cout << "( " << graph[i][j]->vertex << ", " << graph[i][j]->weight << " )";
        }
        cout << endl;
    }
}

void removeEdge(int u , int v) {
    //  for u side links
    int i = -1;
    for (int k = 0; k < graph[u].size(); k++) {
        if (graph[u][k]->vertex == v) {
            i = k;
            break;
        }
    }
    graph[u].erase(graph[u].begin() + i);
    //  for v side links
    int j = -1;
    for (int k = 0; k < graph[v].size(); k++) {
        if (graph[v][k]->vertex == u) {
            j = k;
            break;
        }
    }
    graph[v].erase(graph[v].begin() + j);
}

void removeVtx(int u) {
    for (int i = graph[u].size() - 1; i >= 0; i--) {
        removeEdge(u, graph[u][i]->vertex);
    }
}

bool hasPath(int src, int des, vector<bool> &vis, string ans) {
    if (src == des) {
        cout<<ans + to_string(des) <<endl;
        return true;
    }
    vis[src] = true;
    bool res = false;
    for (int i = 0; i < graph[src].size(); i++) {
        int nbr = graph[src][i]->vertex;   // neighbour
        if (!vis[nbr]) {
            res = res || hasPath(nbr, des, vis, ans + to_string(src) + " -> ");
        }
    }
    return res;
}

int allPath(int src, int des, vector<bool> &vis, string ans) {
    if (src == des) {
        cout<<ans + to_string(des) <<endl;
        return 1;
    }
    vis[src] = true;
    int count = 0;
    for (int i = 0; i < graph[src].size(); i++) {
        int nbr = graph[src][i]->vertex;   // neighbour
        if (!vis[nbr]) {
            count += allPath(nbr, des, vis, ans + to_string(src) + " -> ");
        }
    }
    vis[src] = false;
    return count;
}

void preOrderGraph(int src, vector<bool> &vis, string ans) {
    cout<<to_string(src) + " -> " + ans + to_string(src)<<endl;
    vis[src] = true;
    for (int i = 0; i < graph[src].size(); i++) {
        int nbr = graph[src][i]->vertex;   // neighbour
        if (!vis[nbr]) {
            preOrderGraph(nbr, vis, ans + to_string(src) + " ");
        }
    }
    vis[src] = false;
}

void postOrderGraph(int src, vector<bool> &vis, string ans) {
    vis[src] = true;
    for (int i = 0; i < graph[src].size(); i++) {
        int nbr = graph[src][i]->vertex;   // neighbour
        if (!vis[nbr]) {
            postOrderGraph(nbr, vis, ans + to_string(src) + " ");
        }
    }
    vis[src] = false;
    cout<<to_string(src) + " -> " + ans + to_string(src)<<endl;
}

        // -------------- pairv class for weight and path
class pairPath {
    private:
    public:
        int wt = (2147483647 >> 1);
        string path = "";

        pairPath() {
            // default;
        }

        pairPath(int wt, string path) {
            this->wt = wt;
            this->path = path;
        }
};

/*
int lightweight = INT_MAX >> 1;
string lightpath = "";

void lightestPath_(int src, int wt, int des, vector<bool> &vis, string ans) {
    if (src == des) {
        if (wt < lightweight) {
            lightpath = ans + to_string(src);
            lightweight = wt;
        }
        return;
    }
    vis[src] = true;
    for (Edge* e : graph[src]) {
        int w = e->weight;
        int v = e->vertex;
        if (!vis[v]) {
            lightestPath_(v, wt + w, des, vis, ans + to_string(src) + " ");
        }
    }
    vis[src] = false;
}
*/

pairPath* lightestPath(int src, int des, vector<bool> &vis) {
    if (src == des) {
        pairPath* base = new pairPath(0, to_string(src) + "");
        cout<<base->wt<<endl;
        return base;
    }
    vis[src] = true;
    pairPath* myAns = new pairPath();
    for (Edge* e : graph[src]) {
        int nbr = e->vertex;
        int w = e->weight;
        if (!vis[nbr]) {
            pairPath* recAns = lightestPath(nbr, des, vis);
            if (recAns->wt + w < myAns->wt) {
                myAns->path = to_string(src) + " -> " + recAns->path;
                myAns->wt = w + recAns->wt;
            }
        }
    }
    vis[src] = false;
    return myAns;
}

pairPath* heaviestPath(int src, int des, vector<bool> &vis) {
    if (src == des) {
        pairPath* base = new pairPath(0, to_string(src) + "");
        cout<<base->wt<<endl;
        return base;
    }
    vis[src] = true;
    pairPath* myAns = new pairPath(0, "");
    for (Edge* e : graph[src]) {
        int nbr = e->vertex;
        int w = e->weight;
        if (!vis[nbr]) {
            pairPath* recAns = heaviestPath(nbr, des, vis);
            if (recAns->wt + w > myAns->wt) {
                myAns->path = to_string(src) + " -> " + recAns->path;
                myAns->wt = w + recAns->wt;
            }
        }
    }
    vis[src] = false;
    return myAns;
}

/* -------------- main function --------------- */
int main(int args, char**argv) {
    addEdge(1,0,10);
    addEdge(0,3,10);
    addEdge(1,2,10);
    addEdge(2,3,40);
    addEdge(3,4,2);
    addEdge(4,5,2);
    addEdge(4,6,8);
    addEdge(5,6,3);
    cout<<endl;
    display();
    // cout<<endl;
    // removeEdge(5,6);
    // display();
    // cout<<endl;
    // removeVtx(3);
    // display();
    // cout<<endl;

    vector<bool> vis(graph.size(), false);
    // cout<<boolalpha<<hasPath(0, 6, vis, "")<<endl;
    // cout<<allPath(0, 6, vis, "")<<endl;

    // preOrderGraph(0, vis, "");
    // cout<<endl;
    // postOrderGraph(0, vis, "");

    lightestPath_(0, 0, 6, vis, "");
    cout<<lightpath<< " @ "<<lightweight<<endl;

    // pairPath* lightPath = lightestPath(0, 6, vis);
    // cout<<lightPath->wt<<" @ "<<lightPath->path<<endl;
    
    // pairPath* heavyPath = heaviestPath(0, 6, vis);
    // cout<<heavyPath->wt<<" @ "<<heavyPath->path<<endl;
    
    return 0;
}
