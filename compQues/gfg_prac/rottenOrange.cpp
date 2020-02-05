#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs2(vector<vector<int>>& fruits, queue<int>& que) {
    while ( )
}

int rottenOrange(vector<vector<int>>& fruits) {
    queue<pair<int, int>> que;
    for (int i = 0; i < fruits.size(); i++) {
        for (int j = 0; j < fruits[0].size(); j++) {
            if (fruits[i][j] == 2) {
                que.push({i, j});
            }
        }
    }
    bfs2(fruits, que);
    int count = 0;
    for (int i = 0; i < fruits.size(); i++) {
        for (int j = 0; fruits[0].size(); j++) {
            if (fruits[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

int main(int args, char**argv) {
    vector<vector<int>> arr = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}
    };
    return 0;
}