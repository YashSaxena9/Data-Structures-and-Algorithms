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

bool isSafe_vec(vector<vector<int>> &board, int r, int c) {
    if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size() || board[r][c] != 0) {
        return false;
    }
    return true;
}

void display(vector<vector<int>> &arr) {
    for (vector<int> ar : arr) {
        for (int a : ar) {
            cout << a << " ";
        }
        cout << endl;
    }
}

int calls1 = 0;
bool nKnight_vec(vector<vector<int>> &dir, vector<vector<int>> &board, int row, int col, int fillCount) {
    calls1++;
    if (fillCount == board.size() * board[0].size()) {
        display(board);
        return true;
    }
    bool flag = false;
    // cout << fillCount << endl;
    for (int i = 0; i < dir.size(); i++) {
        int r = row + dir[i][0];
        int c = col + dir[i][1];
        if (isSafe_vec(board, r, c)) {
            board[row][col] = fillCount;
            flag = flag || nKnight_vec(dir, board, r, c, fillCount + 1);
            board[row][col] = 0;
        }
    }
    return flag;
}
int calls2 = 0;
bool nKnight_bit(vector<vector<int>> &dir, long board, int rSize, int cSize, int row, int col, int fillCount, string ans) {
    calls2++;
    if (fillCount == rSize * cSize) {
        cout << ans << endl;
        return true;
    }
    bool flag = false;
    // cout << fillCount << endl;
    for (int i = 0; i < dir.size(); i++) {
        int r = row + dir[i][0];
        int c = col + dir[i][1];
        if (isSafe(board, rSize, cSize, r, c)) {
            board |= (1 << ((row * cSize) + col));
            flag = flag || nKnight_bit(dir, board, rSize, cSize, r, c, fillCount + 1, ans + " (" + to_string(r) + ", "+ to_string(c) + ")");
            board &= (~(1 << ((row * cSize) + col)));
        }
    }
    return flag;
}

int main(int args, char**argv) {
    // vector<vector<bool>> board(8, vector<bool>(8, false));
    vector<vector<int>> dir = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};
    // vector<vector<int>> board(8, vector<int> (8, 0));
    // board[0][0] = 1;
    cout << nKnight_bit(dir, 1L , 6, 6, 0, 0, 1, "(0, 0)") << endl;
    // cout << nKnight_vec(dir, board, 0, 0, 1) << endl;
    // cout << nKnight(0L, 0, 0, 1, "(0, 0)");
    cout << calls1 << ", " << calls2 << endl;
    return 0;
}