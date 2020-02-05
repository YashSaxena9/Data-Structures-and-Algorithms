/**
 * Kruskal's algo
 * Union find
 * Disjoint Sets Union (DSU)
*/

#include<iostream>
#include<vector>
#include<algorithm>             //  for using __std::sort()__ method
#define pii pair<int, int>
#define piii pair<int, pair<int, int>>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display_mst(vector<vector<pii>>& mst) {
    for (int i = 0; i < mst.size(); i++) {
        cout << i << " -> ";
        for (pii e : mst[i]) {
            cout << "(" << e.first << ", w: " << e.second << ")";
        }
        cout << endl;
    }
}

vector<vector<pii>> graph(7, vector<pii>());        //  first = vtx, second = weight of edge
int compCount = graph.size();

int findPar(int vtx, vi& par) {
    if (par[vtx] == vtx)    return vtx;
    par[vtx] = findPar(par[vtx], par);              //  path compression
    return par[vtx];
}

void merge(int p1, int p2, vi& par, vi& size) {
    if (size[p1] < size[p2]) {
        par[p1] = p2;
        size[p2] += size[p1];
    } else {
        par[p2] = p1;
        size[p1] += size[p2];
    }
    compCount--;
}

void kruskalTreeMaker(vi& par, vi& size, vector<piii>& arr) {
    vector<vector<pii>> newGraph_mst(graph.size(), vector<pii>());          //  for MST
    for (int i = 0; i < arr.size(); i++) {
        piii rp = arr[i];
        int p1 = findPar(rp.second.first, par);
        int p2 = findPar(rp.second.second, par);
        if (p1 != p2) {
            merge(p1, p2, par, size);
            newGraph_mst[rp.second.first].push_back({rp.second.second, rp.first});
            newGraph_mst[rp.second.second].push_back({rp.second.first, rp.first});
        }
        else {
            //  cycle detected
        }
    }
    display_mst(newGraph_mst);
}

void solve() {
    vector<piii> arr;           //  can also use priority queue
    //  in a pair, heap sorts on the basis of first
    //  _______ for bi-directional graph _______
    arr.push_back({10, {0, 1}});
    arr.push_back({10, {0, 3}});
    arr.push_back({10, {1, 2}});
    arr.push_back({40, {2, 3}});
    // arr.push_back({2, {3, 4}});
    arr.push_back({2, {4, 5}});
    arr.push_back({3, {4, 6}});
    arr.push_back({8, {5, 6}});
    vi par(graph.size());
    for (int i = 0; i < graph.size(); i++)      par[i] = i;
    vi size(graph.size(), 1);
    sort(arr.begin(), arr.end());
    kruskalTreeMaker(par, size, arr);
}

void pair_sorting_by_heap() {
    vector<piii> arr;
    arr.push_back({10, {0, 1}});
    arr.push_back({10, {0, 3}});
    arr.push_back({10, {1, 2}});
    arr.push_back({40, {2, 3}});
    arr.push_back({2, {3, 4}});
    arr.push_back({2, {4, 5}});
    arr.push_back({3, {4, 6}});
    arr.push_back({8, {5, 6}});
    /**
     *  to sort vector(arr) on the basis of pair.first
     * we will use lambda function while calling std::sort for vector sorting 
     * third argument can be used to change behaviour of max heap
    */
    sort(arr.begin(), arr.end(), [](piii a, piii b) {
        return a.first < b.first;   // for decreasing order sorting
    });

    //  display
    for (piii a : arr) {
        cout << a.first << " @ " << a.second.first << "->" << a.second.second << endl;
    }
    
    sort(arr.begin(), arr.end(), [](piii a, piii b) {
        return a.first > b.first;   // for increasing order sorting
    });
    /* equivalent to ------> sort(arr.begin(), arr.end()) <------ */

    //  display
    for (piii a : arr) {
        cout << a.first << " @ " << a.second.first << "->" << a.second.second << endl;
    }
}

int main(int args, char**argv) {
    solve();
    cout << "total connected components : " << compCount << endl;
    return 0;
}