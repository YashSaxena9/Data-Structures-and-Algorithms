//  find the best way to move in a matrix from left to right(matrix is filled with values and you only have certain direction of moves)
//  the best way is where you get largest sum of numbers
//  moves allowed :-
//  right, upperright, lowerright  -->  {{1, 1}, {0, 1}, {-1, 1}};

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vii& arr) {
    for (vi& a : arr) {
        for (int i : a) {
            cout << i << " ";
        } cout << endl;
    }
}

vii moves = {{1, 1}, {0, 1}, {-1, 1}};
int maxInMine_01(int r, int c, vii& board) {
    if (c == board[0].size()) {
        return 0;
    }
    int maxValue = 0;
    for (vi dir : moves) {
        if (r + dir[0] >= 0 && r + dir[0] < board.size()) {
            maxValue = max(maxValue, maxInMine_01(r + dir[0], c + dir[1], board));
        }
    }
    return maxValue + board[r][c];
}

int maxInMine_02(int r, int c, vii& board, vii& dp) {
    if (c == board[0].size() - 1) {
        return dp[r][c] = board[r][c];
    }
    if (dp[r][c] != 0) {
        return dp[r][c];
    }
    int maxValue = 0;
    for (vi dir : moves) {
        if (r + dir[0] >= 0 && r + dir[0] < board.size()) {
            maxValue = max(maxValue, maxInMine_02(r + dir[0], c + dir[1], board, dp));
        }
    }
    return dp[r][c] = maxValue + board[r][c];
}

int maxInMine_03(vii& board) {
    vii dp(board.size(), vi(board[0].size(), 0));
    for (int c = board[0].size() - 1; c >= 0; c--) {
        for (int r = board.size() - 1; r >= 0; r--) {
            if (c == board[0].size() - 1) {
                dp[r][c] = board[r][c];
                continue;
            }
            int maxValue = 0;
            for (vi dir : moves) {
                if (r + dir[0] >= 0 && c + dir[1] >= 0 && r + dir[0] < board.size() && c + dir[1] < board[0].size()) {
                    maxValue = max(maxValue, dp[r + dir[0]][c + dir[1]]);
                }
            }
            dp[r][c] = maxValue + board[r][c];
        }
    }
    int maxAns = 0;
    for (int i = 0; i < board.size(); i++) {
        maxAns = max(maxAns, dp[i][0]);
    }
    return maxAns;
}

void solve(vii& board) {
    int maxInMine_01_ans = 0;
    for (int i = 0; i < board.size(); i++) {
        maxInMine_01_ans = max(maxInMine_01(i, 0, board), maxInMine_01_ans);
    }
    cout << maxInMine_01_ans << endl;

    //  --------------------------------------------------------

    int maxInMine_02_ans = 0;
    vii dp(board.size(), vi(board[0].size(), 0));
    for (int i = 0; i < board.size(); i++) {
        maxInMine_02_ans = max(maxInMine_02(i, 0, board, dp), maxInMine_02_ans);
    }
    cout << maxInMine_02_ans << endl;
    display(dp);

    //  --------------------------------------------------------

    cout << maxInMine_03(board) << endl;

}

int main(int args, char**argv) {
    vii board = {
        {1, 3, 3},
        {2, 1, 4},
        {0, 6, 4}
    };
    solve(board);
    return 0;
}