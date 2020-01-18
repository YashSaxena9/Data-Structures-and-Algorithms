#include<iostream>
#include<vector>
#include<string>
#include<queue>
//  import java.util.LinkedList  //  in java
//  #include<list>               //  in cpp
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

bool hasPath(int src, int dest, vector<bool> &vis, int wsf, string path) {
    if (src == dest) {
        cout << path << " @ " << wsf << endl;       //  wsf = weight so far
        return true;
    }
    vis[src] = true;
    bool flag = false;
    for (Edge* e : graph[src]) {
        if (!vis[e->v])
        flag = flag || hasPath(e->v, dest, vis, wsf + e->w, path + " -> " + to_string(e->v));
    }
    return flag;
}

int allPath(int src, int dest, vector<bool> &vis, int wsf, string path) {
    if (src == dest) {
        cout << path << " @ " << wsf << endl;       //  wsf = weight so far
        return 1;
    }
    vis[src] = true;
    int count = 0;
    for (Edge* e : graph[src]) {
        if (!vis[e->v])
        count += allPath(e->v, dest, vis, wsf + e->w, path + " -> " + to_string(e->v));
    }
    vis[src] = false;
    return count;
}

int swsf = 1e8;
string lightPath = "";

int lwsf = 0;
string heavyPath = "";

void allSolutions(int src, int des, vector<bool> &vis, int wsf, string path) {
    if (src == des) {
        if (wsf < swsf) {
            swsf = wsf;
            lightPath = path;
        }
        if (wsf > lwsf) {
            lwsf = wsf;
            heavyPath = path;
        }
        return;
    }
    vis[src] = true;
    for (Edge* e : graph[src]) {
        if (!vis[e->v]) {
            allSolutions(e->v, des, vis, wsf + e->w, path + " -> " + to_string(e->v));
        }
    }
    vis[src] = false;
}

void dfs(int src, vector<bool> &vis) {
    vis[src] = true;
    for (Edge* e : graph[src]) {
        if (!vis[e->v]) {
            dfs(e->v, vis);
        }
    }
}

//  tell about all connected graphs present in one graph
int getConnectedComp() {
    int comp = 0;
    vector<bool> vis(graph.size(), false);
    for (int i = 0; i < graph.size(); i++) {
        if (!vis[i]) {
            comp++;
            dfs(i, vis);
        }
    }
    return comp;
}

void bfs1(int src, int dest) {
    queue<int> que;
    que.push(src);
    que.push(-1);
    vector<bool> vis(graph.size(), false);
    int lvl = 0, cycles = 0;
    while (que.size() != 1) {
        int rvtx = que.front();
        que.pop();
        if (vis[rvtx]) {
            cout << "cycles : " << ++cycles << " @ " << rvtx << endl;
            continue;
        }
        if (rvtx == dest) {
            cout << "goal(no. of verteces to dest) : " << lvl << endl;
        }
        vis[rvtx] = true;
        for (Edge* e : graph[rvtx]) {
            if (!vis[e->v]) {
                que.push(e->v);
            }
        }
        if (que.front() == -1) {
            lvl++;
            que.pop();
            que.push(-1);
        }
    }
}

void bfs1_corrected(int src, int dest) {
    queue<int> que;
    que.push(src);
    que.push(-1);
    vector<bool> vis(graph.size(), false);
    int lvl = 0, cycles = 0;
    while (que.size() > 1) {
        int rvtx = que.front();
        que.pop();
        if (rvtx == -1) {
            lvl++;
            que.push(-1);
            continue;
        }
        if (vis[rvtx]) {
            cout << "cycles : " << ++cycles << " @ " << rvtx << endl;
            continue;
        }
        if (rvtx == dest) {
            cout << "goal(no. of vertices to dest) : " << lvl << endl;
        }
        vis[rvtx] = true;
        for (Edge* e : graph[rvtx]) {
            if (!vis[e->v]) {
                que.push(e->v);
            }
        }
    }
}

void bfs2(int src, int dest) {
    queue<int> que;
    vector<bool> vis(graph.size(), false);
    que.push(src);
    bool isDest = false;
    int cycle = 0, level = 0;
    while (que.size() != 0) {
        int size = que.size();
        while (size-- > 0) {
            int rvtx = que.front();
            que.pop();
            if (vis[rvtx]) {
                cout << "cycle: " << ++cycle << " @ " << rvtx << endl;
                continue;
            }
            if (rvtx == dest && !isDest) {
                cout << "goal(no. of vertices to dest) : " << level << endl;
                isDest = true;
            }
            vis[rvtx] = true;
            for (Edge *e : graph[rvtx])
                if (!vis[e->v]) {
                    que.push(e->v);
                }
        }
        level++;
    }
}

//  hamiltonian path
int hamiltonianPath(int start, int head, int size, vector<bool> &vis, string ans) {
    if (size == graph.size() - 1) {
        for (Edge* e : graph[start]) {
            if (e->v == head) {
                ans += " " + to_string(e->v);
                cout << "cycle" << endl;
            }
        }
        cout << ans << endl;
        return 1;
    }
    vis[start] = true;
    int count = 0;
    for (Edge* e : graph[start]) {
        if (!vis[e->v]) {
            count += hamiltonianPath(e->v, head, size + 1, vis, ans + " " + to_string(e->v));
        }
    }
    vis[start] = false;
    return count;
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
    addEdge(6, 0, 100);
    addEdge(2, 5, 100);
}

int main(int args, char**argv) {
    constructGraph();
    display();
    // removeEdge(4, 5);
    // removeVertex(3);
    // display();

    // vector<bool> vis1(graph.size(), false);
    // hasPath(0, 6, vis1, 0, to_string(0) + " -> ");

    // vector<bool> vis2(graph.size(), false);
    // cout << "\n" << allPath(0, 6, vis2, 0, to_string(0)) << endl;
    
    // vector<bool> vis3(graph.size(), false);
    // allSolutions(0, 6, vis3, 0, to_string(0));
    // cout << lightPath << " @ " << swsf << endl;
    // cout << heavyPath << " @ " << lwsf << endl;

    // cout << getConnectedComp() << endl;

    // bfs1(0, 6);
    // bfs1_corrected(0, 6);
    // bfs2(0, 6);
    vector<bool> vis4(graph.size(), false);
    cout << hamiltonianPath(0, 0, 0, vis4, to_string(0) + "");
    return 0;
}