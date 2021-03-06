#include<iostream>
#include<vector>
#include<string>
#include<queue>
/* import java.util.LinkedList  //  in java
#include<list>               //  in cpp */
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
vector<vector<Edge*>> graph;
vector<vector<Edge*>> dgraph(7, vector<Edge*>());
vector<int> minAccWei(7, 0);

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

void addEdge(vector<vector<Edge*>> &graph, int u, int v, int w) {
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

int totalEdges(bool isUniDir) {
    int tot = 0;
    for (int i = 0; i < graph.size(); i++) {
        tot += graph[i].size();
    }
    if (isUniDir)   return tot;
    return tot / 2;
}

void preOderPath(int src, int w, vector<bool> &vis, string ans) {
    vis[src] = true; //mark.
    cout << to_string(src) + " -> " + ans + to_string(src) + " @ " + to_string(w) << endl;

    for (int i = 0; i < graph[src].size(); i++) {
        int nbr = graph[src][i]->v;
        int wt = graph[src][i]->w;
        if (!vis[nbr])                                           //chek for vis
            preOderPath(nbr, w + wt, vis, ans + to_string(src)); //call
    }

    vis[src] = false; //unmark.
}

void postOderPath(int src, int w, vector<bool> &vis, string ans) {
    vis[src] = true; //mark.

    for (int i = 0; i < graph[src].size(); i++) {
        int nbr = graph[src][i]->v;
        int wt = graph[src][i]->w;
        if (!vis[nbr])                                           //chek for vis
            postOderPath(nbr, w + wt, vis, ans + to_string(src)); //call
    }

    cout << to_string(src) + " -> " + ans + to_string(src) + " @ " + to_string(w) << endl;
    vis[src] = false; //unmark.
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

//  for lightest and heaviest path by weight
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

class WeiPath {
    private :
    public :
        int weight = 0;
        string path = "";

        WeiPath(int weight, string path) {
            this->weight = weight;
            this->path = path;
        }
        
        WeiPath(int weight) {
            this->weight = weight;
        }

        WeiPath() {
            //  default
        }
};

WeiPath* lightestPath(int src, int des, vector<bool> &vis) {
    if (src == des) {
        WeiPath* base = new WeiPath(0, to_string(src));
        return base;
    }
    vis[src] = true;
    WeiPath* lp = new WeiPath(1e8);
    for (Edge* e : graph[src]) {
        if (!vis[e->v]) {
            WeiPath* recLp = lightestPath(e->v, des, vis);
            if (recLp->weight + e->w < lp->weight) {
                lp->weight = recLp->weight + e->w;
                lp->path = to_string(src) + " " + recLp->path;
            }
        }
    }
    vis[src] = false;
    return lp;
}

WeiPath* heavyestPath(int src, int des, vector<bool> &vis) {
    if (src == des) {
        WeiPath* base = new WeiPath(0, to_string(src) + " ");
        return base;
    }
    vis[src] = true;
    WeiPath* hp = new WeiPath();
    for (Edge* e : graph[src]) {
        if (!vis[e->v]) {
            WeiPath* rechp = heavyestPath(e->v, des, vis);
            if (rechp->weight + e->w > hp->weight) {
                hp->weight = rechp->weight + e->w;
                hp->path = to_string(src) + " " + rechp->path;
            }
        }
    }
    vis[src] = false;
    return hp;
}
//  simple dfs with recursion
void dfs(int src, vector<bool> &vis) {
    // cout << src << " ";          //  print ans
    vis[src] = true;
    for (Edge* e : graph[src]) {
        if (!vis[e->v]) {
            dfs(e->v, vis);
        }
    }
}

//  simple dfs without recursion
void dfs_noRec(int src) {
    vector<bool> vis(graph.size(), false);
    vector<int> stack;
    stack.push_back(src);
    while (stack.size() != 0) {
        int top = stack.back();
        stack.pop_back();
        if (vis[top]) {
            continue;       //  vtx already added in stack
        }
        // cout << top << " ";          //  print ans
        vis[top] = true;
        for (Edge* e : graph[top]) {
            if (!vis[e->v]) {
                stack.push_back(e->v);
            }
        }
        
        /*
        // to get output same as after using dfs by recursion
        for (int i = graph[top].size() - 1; i >= 0; i--) {
            Edge* e = graph[top][i];
            if (!vis[e->v]) {
                stack.push_back(e->v);
            }
        }
        */
    }
}

bool isConnectedGraph() {
    vector<bool> vis(graph.size(), false);
    dfs(0, vis);
    for (bool flag : vis) {
        if (!flag) {
            return false;
        }
    }
    return true;
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

//  simple bfs method 1
void bfs1(int src) {
    queue<int> que;
    vector<bool> vis(graph.size(), false);
    que.push(src);
    while (que.size() != 0){
        int front = que.front();
        que.pop();
        if (vis[front]) {
            continue;       //  cycle encountered
        }
        cout << front << " ";
        vis[front] = true;
        for (Edge* e : graph[front]) {
            if (!vis[e->v]) {
                que.push(e->v);
            }
        }
    }
}

//  simple bfs method 2
void bfs2(int src) {
    queue<int> que;
    vector<bool> vis(graph.size(), false);
    que.push(src);
    while (que.size() != 0){
        int size = que.size();
        while (size-- > 0) {            //  can be used to detect _ Level _ of bfs traversal
            int front = que.front();
            que.pop();
            if (vis[front]) {
                continue;       //  cycle encountered
            }
            cout << front << " ";
            vis[front] = true;
            for (Edge* e : graph[front]) {
                if (!vis[e->v]) {
                    que.push(e->v);
                }
            }
        }
    }
}

void bfs_allInfo_1(int src, int dest) {
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

void bfs_allInfo_1_corr(int src, int dest) {
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

void bfs_allInfo_2(int src, int dest) {
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

bool hasCycle(int src) {
    vector<bool> vis(graph.size(), false);
    queue<int> que;
    que.push(src);
    while (que.size() != 0) {
        int front = que.front();
        que.pop();
        if (vis[front]) {
            return true;        //  cycle encountered
        }
        vis[front] = true;
        for (Edge* e : graph[front]) {
            if (!vis[e->v]) {
                que.push(e->v);
            }
        }
    }
    return false;
}

int countCycles(int src) {
    vector<bool> vis(graph.size(), false);
    queue<int> que;
    que.push(src);
    int countCycle = 0;
    while (que.size() != 0) {
        int front = que.front();
        que.pop();
        if (vis[front]) {
            countCycle++;        //  cycle encountered
            continue;
        }
        vis[front] = true;
        for (Edge* e : graph[front]) {
            if (!vis[e->v]) {
                que.push(e->v);
            }
        }
    }
    return countCycle;
}

//  ------------------ checking for tree -----------------
bool isTree() {
    return !hasCycle(0) && isConnectedGraph();
}
//  ----------------------- end --------------------------

void bfs_with_ansLvl(int src, int dest) {
    vector<bool> vis(graph.size(), false);
    queue<int> que;
    que.push(src);
    int countLvl = 0;
    while (que.size() != 0) {
        int size = que.size();
        while (size-- > 0) {
            /*
            * we can also use the method of adding null point in queue initialy
            * and then adding null in queue after every encounter of null 
            * ... null denotes change of level
            */
            int front = que.front();
            que.pop();
            if (vis[front]) {
                continue;       //  cycle
            }
            if (front == dest) {
                cout << "found at lvl : " << countLvl << endl;
                return;
            }
            vis[front] = true;
            for (Edge* e : graph[front]) {
                if (!vis[e->v]) {
                    que.push(e->v);
                }
            }
        }
        countLvl++;
    }
    cout << "not found" << endl;
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

//  euler's path
int eulerPath() {
    //  to be solved
    return 0;
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

//  queue of self made ColorPair obj
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

//  queue of pair obj
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

bool isBipartite_withInfo() {
    vector<int> vis(graph.size(), -1);
    int count = 0;
    bool flag = false;
    for (int i = 0; i < graph.size(); i++) {
        if (vis[i] == -1) {
            bool ans = isBipartite_util_01(i, vis);
                    // bool ans = isBipartite_util_02(i, vis);
            flag = flag || ans;
            if (!flag)   count++;
            cout << count << " " << (boolalpha) << ans << endl;
        }
    }
    return flag;
}

bool isBipartite() {
    vector<short> vis(graph.size(), -1);
    for (int i = 0; i < graph.size(); i++) {
        if (vis[i] != -1) {
            continue;
        }

        queue<pair<int, short>> que;    //  first == vtx and second == color
        que.push({i, 0});
        while (que.size() != 0) {
            pair<int, short> front = que.front();
            que.pop();
            if (vis[front.first] != -1) {
                if (vis[front.first] != front.second) {
                    return false;
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
    }
    return true;
}

void shortestPath_withBFS(int src, int des) {
    queue<int> que;
    queue<string> quePath;
    vector<int> vis(graph.size(), false);
    que.push(src);
    quePath.push(to_string(src) + " ");
    while (que.size() != 0) {
        int front = que.front();
        string frontPath = quePath.front();
        que.pop();
        quePath.pop();
        if (vis[front]) {
            continue;       //  cycle encountered
        }
        if (front == des) {
            cout << frontPath << endl;
            break;
        }
        vis[front] = true;
        for (Edge* e : graph[front]) {
            if (!vis[e->v]) {
                que.push(e->v);
                quePath.push(frontPath + to_string(e->v) + " ");
            }
        }
    }
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

//  ------------------ dijikstra ------------------
/* dpair object for dijikstra algo,
*  it is used to carry vertex , its parent 
*  and weight so far for the path in between
*/
class dpair {
    public:
        int vtx;
        int parent;
        int wt;      //  weight
        int wsf;    //  weight so far

        dpair(int vts, int parent, int wt, int wsf) {
            this->vtx = vts;
            this->parent = parent;
            this->wt = wt;
            this->wsf = wsf;
        }

        //  overriding minHeap behind 2 interfaces
        //  minHeap with 2 interfaces act as maxHeap
        //  overloaded < to trick maxHeap interface
        bool operator < (dpair const &o) const {
            return this->wsf > o.wsf;       //  self = strong -> other is weak so subtraction is +ve
            //  +ve = make heap look I'm strong
            //  strong element at bottom of heap in minHeap
        }
};

//  bfs with wsf and priority queue
//  "weight so far" and "priority queue" plays the important role
void dijikstra(int src) {
    /* 
    // priority_queue<int, vector<int>, greater<int>> que;
                            this method can be used for
                            converting max heap to min heap
                            for primitive datatype priority queues
    */
    priority_queue<dpair> que; 
    vector<bool> vis(graph.size(), false);
    que.push(dpair(src, -1, 0, 0));
    while (que.size() != 0) {
        dpair front = que.top();
        que.pop();
        if (vis[front.vtx]) {
            continue;       //  cycle encountered
        }
        if (front.parent != -1) {
            addEdge(dgraph, front.parent, front.vtx, front.wt);     //  to create a spanning tree(not msp)
            minAccWei[front.vtx] = front.wsf;
        }
        /** if (front.vtx == des) {
         *      cout << front.wsf << endl;
         * }
        */
        vis[front.vtx] = true;
        for (Edge* e : graph[front.vtx]) {
            if (!vis[e->v]) {
                que.push(dpair(e->v, front.vtx, e->w, front.wsf + e->w));
            }
        }
    }

    //  to display spanning tree formed and weight to visit each vtx
    display(dgraph);
    for (int a : minAccWei) {
        cout << a << " ";
    } cout << endl;
}

//  ------------------ Prims Algo ------------------
/* Primpair object for Prims algo,
*  it is used to carry vertex , its parent 
*  and weight for them
*/
class Primpair {
    public:
        int vtx;
        int parent;
        int wt;      //  weight

        Primpair(int vts, int parent, int wt) {
            this->vtx = vts;
            this->parent = parent;
            this->wt = wt;
        }

        //  overriding minHeap behind 2 interfaces
        //  minHeap with 2 interfaces act as maxHeap
        //  overloaded < to trick maxHeap interface
        bool operator < (Primpair const &o) const {
            return this->wt > o.wt;       //  self = strong -> other is weak so subtraction is +ve
            //  +ve = make heap look I'm strong
            //  strong element at bottom of heap in minHeap
        }
};

//  bfs with wt between 2 vtxs and priority queue
//  "weight" and "priority queue" plays the important role
void primsAlgo(int src) {
    vector<vector<Edge*>> PrimGraph(graph.size(), vector<Edge*>());
    /* 
    // priority_queue<int, vector<int>, greater<int>> que;
                            this method can be used for
                            converting max heap to min heap
                            for primitive datatype priority queues
    */
    priority_queue<Primpair> que; 
    vector<bool> vis(graph.size(), false);
    que.push(Primpair(src, -1, 0));
    while (que.size() != 0) {
        Primpair front = que.top();
        que.pop();
        if (vis[front.vtx]) {
            continue;       //  cycle encountered
        }
        if (front.parent != -1) {
            addEdge(PrimGraph, front.parent, front.vtx, front.wt);     //  to create a minimum spanning tree
        }
        /** if (front.vtx == des) {
         *      cout << front.wsf << endl;
         * }
        */
        vis[front.vtx] = true;
        for (Edge* e : graph[front.vtx]) {
            if (!vis[e->v]) {
                que.push(Primpair(e->v, front.vtx, e->w));
            }
        }
    }

    //  to display spanning tree formed and weight to visit each vtx
    display(PrimGraph);
}

//  ------------------ Union find Algo ------------------
/* ============= in file kruskal_dsu.cpp ============= */
//  DSU (disjoint set union)
//  in krusal_dsu.cpp file
void merge(int p1, int p2, vector<int>& par, vector<int>& size) {
    if (size[p1] < size[p2]) {
        par[p1] = p2;
        size[p2] += size[p1];
    } else {
        par[p2] = p1;
        size[p1] += size[p2];
    }
}

int findPar(int vtx, vector<int>& par) {
    if (par[vtx] == vtx)        return vtx;
    par[vtx] = findPar(par[vtx], par);              //  path compression call
    return par[vtx];
}

/* ========================================================== */

//  ------------------ Articulation point and bridge Algo ------------------
//  points from where the graph will make most number of components if
//  those points/vertexes disappear are called articulation point
/** 
 * can be found in articulaion.cpp
*/

/* ========================================================== */

//  ----------- main -------------
void constructGraph() {
    int tot_vert = 7;
    for (int i = 0; i < tot_vert; i++) {
        graph.push_back(vector<Edge*>());
    }

    //  graph 1
    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 3);
    addEdge(5, 6, 8);
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
    // addEdge_uni(0, 1);
    // addEdge_uni(1, 3);
    // addEdge_uni(3, 8);
    // addEdge_uni(8, 9);
    // addEdge_uni(9, 8);
    // addEdge_uni(2, 0);
    // addEdge_uni(1, 2);
    // addEdge_uni(2, 4);
    // addEdge_uni(4, 3);
    // addEdge_uni(2, 5);
    // addEdge_uni(6, 4);
    // addEdge_uni(5, 6);
    // addEdge_uni(5, 7);
    // addEdge_uni(3, 7);
    // addEdge_uni(7, 6);
    // addEdge_uni(7, 9);

    // graph 6
    // addEdge(graph, 0, 1, 11);
    // addEdge(graph, 0, 3, 10);
    // addEdge(graph, 1, 2, 20);
    // addEdge(graph, 2, 3, 40);
    // addEdge(graph, 3, 4, 2);
    // addEdge(graph, 4, 5, 2);
    // addEdge(graph, 4, 6, 3);
    // addEdge(graph, 5, 6, 8);
}

int main(int args, char**argv) {
    constructGraph();
    // display();
    // removeEdge(4, 5);
    // removeVertex(3);
    // display();

    // vector<bool> vis1(graph.size(), false);
    // preOderPath(0, 0, vis1, "");
    // cout << endl;
    // postOderPath(0, 0, vis1, "");
    // cout << totalEdges(false) << endl;
    // dfs(0, vis1);
    // cout << endl;
    // dfs_noRec(0);
    // hasPath(0, 6, vis1, 0, to_string(0) + " -> ");

    // vector<bool> vis2(graph.size(), false);
    // cout << "\n" << allPath(0, 6, vis2, 0, to_string(0)) << endl;
    
    // vector<bool> vis3(graph.size(), false);
    // allSolutions(0, 6, vis3, 0, to_string(0));
    // cout << lightPath << " @ " << swsf << endl;
    // cout << heavyPath << " @ " << lwsf << endl;

    // WeiPath* lp = lightestPath(0, 6, vis3);
    // cout << lp->path << " @ " << lp->weight << endl;
    
    // WeiPath* hp = heavyestPath(0, 6, vis3);
    // cout << hp->path << " @ " << hp->weight << endl;

    // removeEdge(3, 4);        //  for testing connecting graph property
    // cout << boolalpha << isConnectedGraph() << endl;
    // cout << getConnectedComp() << endl;

    // bfs1(0);
    // bfs2(0);
    // bfs_allInfo_1(0, 6);
    // bfs_allInfo_1_corr(0, 6);
    // bfs_allInfo_2(0, 6);

    // cout << (boolalpha) << hasCycle(0) << endl;
    // cout << countCycles(0) << endl;
    // bfs_with_ansLvl(0, 5);

    // vector<bool> vis4(graph.size(), false);
    // cout << hamiltonianPath(0, 0, 0, vis4, "");

    // cout << (boolalpha) << isBipartite() << endl;
    // cout << (boolalpha) << isBipartite_withInfo() << endl;

    // shortestPath_withBFS(0, 6);

    // topologicalSort_();
    // topologicalSort_btr();
    // topologicalSort_bfs();

    // inverseGraph();
    // cout << SCC_count();

    // cout << (boolalpha) << isTree() << endl;

    // dijikstra(0);
    // primsAlgo(4);
    return 0;
}