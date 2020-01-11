#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe(long board, int rSize, int cSize, int r, int c) {
    if (r < 0 || c < 0 || r >= rSize || c >= cSize || (board & (1 << ((r * cSize) + c)))) {
        return false;
    }
    return true;
}
int calls = 0;
bool nKnight(long board, int rSize, int cSize, int row, int col, int fillCount) {
    calls++;
    if (fillCount == rSize * cSize) {
        cout << fillCount << endl;
        return true;
    }
    // int count = 0;
    // cout << calls << endl;
    // vector<int> dir1 = {2, 2, -2, -2, 1, -1, 1, -1};
    // vector<int> dir2 = {1, -1, 1, -1, 2, 2, -2, -2};
    
    vector<int> dir1 = {2, 1, -1, -2, -2, -1, 1, 2}; 
    vector<int> dir2 = {1, 2, 2, 1, -1, -2, -2, -1}; 
    for (int i = 0; i < dir1.size(); i++) {
        int r = row + dir1[i];
        int c = col + dir2[i];
        if (isSafe(board, rSize, cSize, r, c)) {
            board |= (1 << ((row * cSize) + col));
            if (nKnight(board, rSize, cSize, r, c, fillCount + 1)) {
                return true;
            }
            // flag = flag || nKnight(board, r, c, fillCount + 1, ans + " (" + to_string(r) + ", "+ to_string(c) + ")");
            board &= (~(1 << ((row * cSize) + col)));
        }
    }
    return false;
}

int main(int args, char**argv) {
    // vector<vector<bool>> board(8, vector<bool>(8, false));
    cout << nKnight(0L, 8, 8, 0, 0, 1);
    // cout << nKnight(0L, 0, 0, 1, "(0, 0)");
    cout << calls << endl;
    return 0;
}