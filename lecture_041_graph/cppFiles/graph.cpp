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
    
    Edge(int v) {
        this->v = v;
        this->w = 0;
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

void display(vector<vector<Edge*>> &graph_) {
    for (int i = 0; i < graph_.size(); i++) {
        cout << i << " -> ";
        for (Edge* e : graph_[i]) {
            cout << "(" << e->v << ", " << e->w<< ") ";
        }
        cout << endl;
    }
    cout << endl;
}

//  ---------- add edges ------------

//  for undirected weighted
void addEdge(int u, int v, int w) {
    if (u < 0 || u >= graph.size() || v < 0 || v >= graph.size()) {
        return;
    }
    graph[u].push_back(new Edge(v, w));
    graph[v].push_back(new Edge(u, w));
}

//  for undirected non-weighted
void addEdge(int u, int v) {
    if (u < 0 || u >= graph.size() || v < 0 || v >= graph.size()) {
        return;
    }
    graph[u].push_back(new Edge(v, 0));
    graph[v].push_back(new Edge(u, 0));
}

//  for unidirectional weighted
void addEdge_uni(int u, int v, int w) {
    if (u < 0 || u >= graph.size() || v < 0 || v >= graph.size()) {
        return;
    }
    graph[u].push_back(new Edge(v, w));
}

//  for unidirectional non-weighted
void addEdge_uni(int u, int v) {
    if (u < 0 || u >= graph.size() || v < 0 || v >= graph.size()) {
        return;
    }
    graph[u].push_back(new Edge(v, 0));
}

//  for mixed weighted
void addEdge(int u, int v, int w, bool isDir_) {
    if (u < 0 || u >= graph.size() || v < 0 || v >= graph.size()) {
        return;
    }
    graph[u].push_back(new Edge(v, w));
    if (!isDir_) {
        graph[v].push_back(new Edge(u, w));
    }
}


//  ---------- end ------------

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

void bfs_allInfo(int src, int dest) {
    /*
    * here this algo is a little wrong.
    * we are checking the -1 presence after adding elements in que
    * if there are repeated elements in que at same level and just before -1
    * then it will continue at that repeated element and won't give -1 the chance of poping 
    * out of the que.
    * in next iteration of loop vis[rvtx] have -1 as rvtx and give exception
    */
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
        //  this should be placed before detecting cycle and increasing cycle count
        //  it should have continue with itself when placed at right place
        if (que.front() == -1) {
            lvl++;
            que.pop();
            que.push(-1);
        }
    }
}

void bfs_allInfo_corrected(int src, int dest) {
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
        ans += " " + to_string(start);
        for (Edge* e : graph[start]) {
            if (e->v == head) {
                ans += " " + to_string(e->v);
                cout << "cycle : " << ans << endl;
                return 1;
            }
        }
        cout << "path : " << ans << endl;
        return 1;
    }
    vis[start] = true;
    int count = 0;
    for (Edge* e : graph[start]) {
        if (!vis[e->v]) {
            count += hamiltonianPath(e->v, head, size + 1, vis, ans + " " + to_string(start));
        }
    }
    vis[start] = false;
    return count;
}

//  class for coloring of vertexes
class ColorPair {
    public:
        int vtx;
        int color;
        ColorPair(int vtx, int color) {
            this->color = color;
            this->vtx = vtx;
        }
        ColorPair() {
            //  default
        }
};

bool isBipartite_util_01(int src, vector<int> &vis) {
    queue<ColorPair*> que;
    ColorPair* cp = new ColorPair(src, 0);
    que.push(cp);
    bool flag = true;
    while (que.size() != 0) {
        ColorPair* front = que.front();
        que.pop();
        if (vis[front->vtx] != -1) {
            if (front->color != vis[front->vtx]) {
                cout << "conflict : " << endl;
                flag = false;
            }
            continue;
        }
        vis[front->vtx] = front->color;
        for (Edge* e : graph[front->vtx]) {
            if (vis[e->v] == -1) {
                que.push(new ColorPair(e->v, (front->color + 1) % 2));
            }
        }
    }
    return flag;
}

bool isBipartite_util_02(int src, vector<int> &vis) {
    queue<pair<int, int>> que;
    que.push({src, 0});
    bool flag = true;
    while (que.size() != 0) {
        pair<int, int> front = que.front();
        que.pop();
        if (vis[front.first] != -1) {
            if (front.second != vis[front.first]) {
                cout << "conflict : " << endl;           //  used to check no. of conflicts
                flag = false;
            }
            continue;
        }
        vis[front.first] = front.second;
        for (Edge* e : graph[front.first]) {
            if (vis[e->v] == -1) {
                que.push({e->v, (front.second + 1) % 2});
            }
        }
    }
    return flag;
}

bool isBipartite() {
    vector<int> vis(graph.size(), -1);
    int count = 0;
    bool flag = false;
    for (int i = 0; i < graph.size(); i++) {
        if (vis[i] == -1) {
            bool ans = isBipartite_util_01(i, vis);
                    // bool ans = isBipartite_util_02(i, vis);
            flag = flag || ans;
            cout << count << " " << (boolalpha) << ans << endl;
            count++;
        }
    }
    return flag;
}

//  --------------- topological sort by DFS ------------------
//  topological sort cycle not handled
void topologicalSort_util_(int src, vector<bool> &vis, vector<int> &stack) {
    vis[src] = true;
    for (Edge* e : graph[src]) {
        if (!vis[e->v]) {
            topologicalSort_util_(e->v, vis, stack);
        }
    }
    stack.push_back(src);
}

void topologicalSort_() {
    vector<bool> vis(graph.size(), false);
    vector<int> stack;
    for (int i = 0; i < graph.size(); i++) {
        if (!vis[i]) {
            topologicalSort_util_(i, vis, stack);
        }
    }
    while (stack.size() != 0) {
        cout << stack.back() << " ";
        stack.pop_back();
    }
    cout << endl;
}

//  topological sort cycle handled
bool topologicalSort_util_btr(int src, vector<bool> &vis, vector<bool> &cycleDetector, vector<int> &stack) {
    vis[src] = true;
    cycleDetector[src] = true;
    bool res = false;
    for (Edge* e : graph[src]) {
        if (!vis[e->v]) {
            res = res || topologicalSort_util_btr(e->v, vis, cycleDetector, stack);
        } else if (cycleDetector[e->v]) {
            return true;
        }
    }
    cycleDetector[src] = false;
    stack.push_back(src);
    return res;
}

void topologicalSort_btr() {
    vector<bool> vis(graph.size(), false);
    vector<bool> cycleDetector(graph.size(), false);
    vector<int> stack;
    bool isCycle = false;
    for (int i = 0; i < graph.size(); i++) {
        if (!vis[i]) {
            isCycle = isCycle || topologicalSort_util_btr(i, vis, cycleDetector, stack);
        }
    }
    if (isCycle) {
        cout << "invalid cycle present" << endl;
        return;
    }
    while (stack.size() != 0) {
        cout << stack.back() << " ";
        stack.pop_back();
    }
    cout << endl;
}

//  --------------- topological sort by BFS ------------------
//  Khan's Algo
void topologicalSort_bfs() {
    vector<int> inDegree(graph.size(), 0);
    for (int i = 0; i < inDegree.size(); i++) {
        for (Edge* e : graph[i]) {
            inDegree[e->v]++;
        }
    }
    queue<int> que;
    for (int i = 0; i < inDegree.size(); i++) {
        // cout<<inDegree[i]<<" ";
        if (inDegree[i] == 0) {
            // cout<<"i"<< i<<endl;
            que.push(i);
        }
    }
    vector<int> ans;
    while (que.size() != 0) {
        int rvtx = que.front();
        que.pop();
        ans.push_back(rvtx);
        for (Edge* e : graph[rvtx]) {
            inDegree[e->v]--;
            if (inDegree[e->v] == 0) {
                que.push(e->v);
            }
        }
    }

    //  checking ans covers all vertex or not
    if (ans.size() != graph.size()) {
        cout << "invalid cycle present" << endl;
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    cout << endl;
}

//  ---------- Kosa Raju Algo  for strongly connected components ------------
vector<vector<Edge*>> inverseGraph() {
    vector<vector<Edge*>> invGraph(graph.size(), vector<Edge*>());
    for (int i = 0; i < graph.size(); i++) {
        for (Edge* e : graph[i]) {
            invGraph[e->v].push_back(new Edge(i));
        }
    }
    // display(invGraph);
    return invGraph;
}

void dfs_kosaRaju(int src, vector<bool> &vis, vector<int> &stack) {
    vis[src] = true;
    for (Edge* e : graph[src]) {
        if (!vis[e->v]) {
            dfs_kosaRaju(e->v, vis, stack);
        }
    }
    stack.push_back(src);
}

//  simple dfs traversal
void dfs_for_SCC(int src, vector<vector<Edge*>> &invGraph, vector<bool> &vis) {
    vis[src] = true;
    // cout << src << " ";
    for (Edge* e : invGraph[src]) {
        if (!vis[e->v]) {
            dfs_for_SCC(e->v, invGraph, vis);
        }
    }
}
//  strongly connected components count
int SCC_count() {
    vector<bool> vis(graph.size(), false);
    vector<int> stack;
    for (int i = 0; i < graph.size(); i++) {
        if (!vis[i]) {
            dfs_kosaRaju(i, vis, stack);
        }
    }
    vector<vector<Edge*>> invGraph = inverseGraph();
    for (int i = 0; i < vis.size(); i++) {
        vis[i] = false;
    }
    int count = 0;
    while (stack.size() != 0) {
        int vtx = stack.back();
        if (!vis[vtx]) {
            dfs_for_SCC(vtx, invGraph, vis);
            count++;
        }
        stack.pop_back();
    }
    return count;
}


/* ========================================================== */

//  ----------- main -------------
void constructGraph() {
    int tot_vert = 10;
    for (int i = 0; i < tot_vert; i++) {
        graph.push_back(vector<Edge*>());
    }

    //  graph 1
    // addEdge(0, 1, 10);
    // addEdge(0, 3, 10);
    // addEdge(1, 2, 10);
    // addEdge(2, 3, 40);
    // addEdge(3, 4, 2);
    // addEdge(4, 5, 2);
    // addEdge(4, 6, 3);
    // addEdge(5, 6, 8);
           // extra
    // addEdge(6, 0, 100);
    // addEdge(2, 5, 100);

    //  graph 2
    // addEdge(1, 2, 6);
    // addEdge(1, 3, 6);
    // addEdge(0, 2, 6);
    // addEdge(0, 3, 6);
    
    //  graph 3                 /* uni directional */
    // addEdge_uni(0, 1);
    // addEdge_uni(1, 2);
    // addEdge_uni(2, 3);
    // addEdge_uni(0, 4);
    // addEdge_uni(7, 4);
    // addEdge_uni(7, 6);
    // addEdge_uni(6, 5);
    // addEdge_uni(5, 3);

    // graph 4
    // addEdge_uni(0, 1);
    // addEdge_uni(1, 2);
    // addEdge_uni(2, 3);
    // addEdge_uni(2, 4);
    // addEdge_uni(4, 6);
    // addEdge_uni(6, 7);
    // addEdge_uni(7, 4);
    // addEdge_uni(1, 3);
    // addEdge_uni(3, 4);
    // addEdge_uni(3, 5);

    // graph 5
    addEdge_uni(0, 1);
    addEdge_uni(1, 3);
    addEdge_uni(3, 8);
    addEdge_uni(8, 9);
    addEdge_uni(9, 8);
    addEdge_uni(2, 0);
    addEdge_uni(1, 2);
    addEdge_uni(2, 4);
    addEdge_uni(4, 3);
    addEdge_uni(2, 5);
    addEdge_uni(6, 4);
    addEdge_uni(5, 6);
    addEdge_uni(5, 7);
    addEdge_uni(3, 7);
    addEdge_uni(7, 6);
    addEdge_uni(7, 9);
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

    bfs_allInfo(0, 6);
    // bfs_allInfo_corrected(0, 6);
    // bfs2(0, 6);

    // vector<bool> vis4(graph.size(), false);
    // cout << hamiltonianPath(0, 0, 0, vis4, "");

    // cout << isBipartite() << endl;

    // topologicalSort_();
    // topologicalSort_btr();
    // topologicalSort_bfs();

    // inverseGraph();
    // cout << SCC_count();
    
    return 0;
}