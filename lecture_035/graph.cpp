#include<iostream>
#include<vector>
#include<string>
using namespace std;

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

vector<vector<Edge*>> graph(7, vector<Edge*>());

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

int main(int args, char**argv) {
    addEdge(0,3,10);
    addEdge(1,0,10);
    addEdge(1,2,10);
    addEdge(2,3,40);
    addEdge(3,4,2);
    addEdge(4,5,2);
    addEdge(4,6,8);
    addEdge(5,6,3);
    cout<<endl;

    display();
    return 0;
}
