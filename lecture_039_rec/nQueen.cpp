#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isSafe_sepLoops_comb(vector<vector<bool>> &board, int row, int col) {
    for (int i = row; i >= 0; i--) {
        if (board[i][col]) {
            return false;
        }
    }
    for (int i = col; i >= 0; i--) {
        if (board[row][i]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < board[0].size(); i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }
    return true;
}

bool isSafe_circle(vector<vector<bool>> &board, int row, int col) {
    vector<vector<int>> option = {{-1, 0}, {-1, -1}, {-1, 1}, {0, -1}, {1, 0}, {1, 1}, {1, -1}, {0, 1}};
    for (int i = 0; i < option.size(); i++) {
        // for (int rad = 1; rad < max(board.size(), board[0].size()); rad++) {
        for (int rad = 0; rad < max(board.size(), board[0].size()); rad++) {
            int r = row + rad * option[i][0];
            int c = col + rad * option[i][1];
            if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) {
                break;
            }
            if (board[r][c]) {
                return false;
            }
        }
    }
    return true;
}

int calls1 = 0;
int nqueen_Comb(vector<vector<bool>> &board, int vidx, int qpsf, int tnq, string ans) {
    calls1++;               //  to count recursion calls
    if (qpsf == tnq) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = vidx; i < board.size() * board[0].size(); i++) {
        int r = i / board[0].size(), c = i % board[0].size();
        if (isSafe_circle(board, r, c)) {
            board[r][c] = true;
            count += nqueen_Comb(board, i + 1, qpsf + 1, tnq, ans + "(" + to_string(r) + "," + to_string(c) + ")" + " ");
            board[r][c] = false;
        }
    }
    return count;
}

int nqueen_Perm(vector<vector<bool>> &board, int vidx, int tnq, string ans) {
    if (tnq == 0) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < board.size() * board[0].size(); i++) {
        int r = i / board[0].size(), c = i % board[0].size();
        if (isSafe_circle(board, r, c)) {
            board[r][c] = true;
            count += nqueen_Perm(board, i + 1, tnq - 1, ans + "(" + to_string(r) + "," + to_string(c) + ")" + " ");
            board[r][c] = false;
        }
    }
    return count;
}

//  ================ better ====================

int calls2 = 0;
int nQueen_btr(vector<vector<bool>> &board, int row, int tnq, string ans) {
    calls2++;                   //  to count recursion calls
    if (row == board.size() || tnq <= 0) {
        if (tnq == 0) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int col = 0; col < board[0].size(); col++) {
        if (isSafe_circle(board, row, col)) {
            board[row][col] = true;
            count += nQueen_btr(board, row + 1, tnq - 1, ans + "(" + to_string(row) + "," + to_string(col) + ")" + " ");
            board[row][col] = false;
        }
    }
    return count;
}

//  ================== fastest ====================
int row_fill = 0, col_fill = 0, diag1_fill = 0, diag2_fill = 0;
bool isSafe_circle_btr(int cSize, int r, int c) {
    if ((row_fill & (1 << r))) {
        return false;   
    }
    if ((col_fill & (1 << c))) {
        return false;
    }
    if ((diag1_fill & (1 << (r - c + cSize - 1)))) {
        return false;
    }
    if ((diag2_fill & (1 << (r + c)))) {
        return false;
    }
    return true;
}

int calls3 = 0;
int nQueen_fastest(int rSize, int cSize, int row, int tnq, string ans) {
    calls3++;                   //  to count recursion calls
    if (row == rSize || tnq <= 0) {
        if (tnq == 0) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int col = 0; col < cSize; col++) {
        if (isSafe_circle_btr(cSize, row, col)) {
            row_fill |= (1 << row);
            col_fill |= (1 << col);
            diag1_fill |= (1 << (row - col + cSize - 1));
            diag2_fill |= (1 << (row + col));
            
            count += nQueen_fastest(rSize, cSize, row + 1, tnq - 1, ans + "(" + to_string(row) + "," + to_string(col) + ")" + " ");
            
            row_fill &= (~(1 << row));
            col_fill &= (~(1 << col));
            diag1_fill &= (~(1 << (row - col + cSize - 1)));
            diag2_fill &= (~(1 << (row + col)));
        }
    }
    return count;
}

int main(int args, char**argv) {
    vector<vector<bool>> arr(4, vector<bool> (4, false));
    // cout << nqueen_Comb(arr, 0, 0, 4, "") << endl;
    // cout << nqueen_Perm(arr, 0, 4, "") << endl;
    cout << nQueen_btr(arr, 0, 4, "") << endl;
    cout << nQueen_fastest(4, 4, 0, 4, "") << endl;
    cout << calls2 << " , " << calls3 << endl;
    return 0;
}