#include<iostream>
#include<vector>
#include<string>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vii &arr) {
    for (vi ar : arr) {
        for (int a : ar) {
            cout << a << " ";
        }
        cout << endl;
    }
    cout << "\n----------------------------\n" << endl;
}

int sudoku_solver(vii &board, vi &places, int vidx, vi &rowFill, vi &colFill, vii &boxFill) {
    if (vidx == places.size()) {
        display(board);
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= 9; i++) {
        int r = places[vidx] / board[0].size();
        int c = places[vidx] % board[0].size();
        int mask = (1 << i);
        if (!(rowFill[r] & mask) && !(colFill[c] & mask) && !(boxFill[r / 3][c / 3] & mask)) {
            board[r][c] = i;
            rowFill[r] ^= mask;
            colFill[c] ^= mask;
            boxFill[r / 3][c / 3] ^= mask;
            
            count += sudoku_solver(board, places, vidx + 1, rowFill, colFill, boxFill);
            
            rowFill[r] ^= mask;
            colFill[c] ^= mask;
            boxFill[r / 3][c / 3] ^= mask;
            board[r][c] = 0;
        }
    }
    return count;
}

void sudoku() {
    vii board = {
        {0, 0, 6, 0, 0, 8, 0, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };
    vi places, rowFill(9, 0), colFill(9, 0);
    vii boxFill(3, vi(3, 0));
    for (int i = 0; i < board.size() * board[0].size(); i++) {
        int r = i / board[0].size();
        int c = i % board[0].size();
        int val = board[r][c];
        if (val == 0) {
            places.push_back(i);
        } else {
            rowFill[r] |= (1 << val);
            colFill[c] |= (1 << val);
            boxFill[r / 3][c / 3] |= (1 << val);
        }
    }
    cout << sudoku_solver(board, places, 0, rowFill, colFill, boxFill) << endl;
}

int main(int args, char**argv) {
    sudoku();
    return 0;
}