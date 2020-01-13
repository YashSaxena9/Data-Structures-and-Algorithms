#include<iostream>
#include<vector>
#include<string>
using namespace std;

void display(vector<vector<int>> &arr) {
    for (vector<int> ar : arr) {
        for (int a : ar) {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << "\n---------------------------\n" << endl;
}

bool isSafe(vector<vector<int>> &board, int r, int c, int num) {
    for (int i = 0; i < board.size(); i++) {
        if (board[i][c] == num) {
            return false;
        }
    }
    for (int i = 0; i < board[0].size(); i++) {
        if (board[r][i] == num) {
            return false;
        }
    }
    
    int row = (r / 3) * 3;
    int col = (c / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + row][j + col] == num) {
                return false;
            }
        }
    }
    return true;
}

int sudoku(vector<vector<int>> &board, int vidx) {
    if (vidx == board.size() * board[0].size()) {
        display(board);
        return 1;
    }
    int count = 0;
    int r = vidx / board[0].size();
    int c = vidx % board[0].size();
    if (board[r][c] == 0) {
        for (int i = 1; i <= 9; i++) {
            if (isSafe(board, r, c, i)) {
                board[r][c] = i;
                count += sudoku(board, vidx + 1);
                board[r][c] = 0;
            }
        }
    } else {
        count += sudoku(board, vidx + 1);
    }
    return count;
}

int main(int args, char**argv) {
    vector<vector<int>> board = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                                {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                                {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                                {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                                {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                                {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                                // {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
                                {0,0,0,0,0,0,0,0,0},
                                {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                                {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    cout << sudoku(board, 0);
    return 0;
}