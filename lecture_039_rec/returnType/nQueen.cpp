#include<iostream>
#include<vector>
#include<string>
using namespace std;

void display(vector<string> &arr) {
    for (string r : arr) {
        cout << r << endl;
    }
    cout << arr.size() << endl;
}

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
vector<string> nqueen_Comb(vector<vector<bool>> &board, int vidx, int tnq) {
    calls1++;               //  to count recursion calls
    if (tnq == 0) {
        vector<string> base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int i = vidx; i < board.size() * board[0].size(); i++) {
        int r = i / board[0].size(), c = i % board[0].size();
        if (isSafe_circle(board, r, c)) {
            board[r][c] = true;
            vector<string> recAns = nqueen_Comb(board, i + 1, tnq - 1);
            board[r][c] = false;
            for (string ans : recAns) {
                myAns.push_back("(" + to_string(r) + ", " + to_string(c) + ")" + " " + ans);
            }
        }
    }
    return myAns;
}

vector<string> nqueen_Perm(vector<vector<bool>> &board, int tnq) {
    if (tnq == 0) {
        vector<string> base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int i = 0; i < board.size() * board[0].size(); i++) {
        int r = i / board[0].size(), c = i % board[0].size();
        if (isSafe_circle(board, r, c)) {
            board[r][c] = true;
            vector<string> recAns = nqueen_Perm(board, tnq - 1);
            board[r][c] = false;
            for (string ans : recAns) {
                myAns.push_back("(" + to_string(r) + ", " + to_string(c) + ")" + " " + ans);
            }
        }
    }
    return myAns;
}

//  ================ better ====================

int calls2 = 0;
vector<string> nQueen_btr(vector<vector<bool>> &board, int row, int tnq) {
    calls2++;                   //  to count recursion calls
    if (row == board.size() || tnq <= 0) {
        vector<string> base;
        if (tnq == 0) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    for (int col = 0; col < board[0].size(); col++) {
        if (isSafe_circle(board, row, col)) {
            board[row][col] = true;
            vector<string> recAns = nQueen_btr(board, row + 1, tnq - 1);
            board[row][col] = false;
            for (string ans : recAns) {
                myAns.push_back("(" + to_string(row) + ", " + to_string(col) + ")" + " " + ans);
            }
        }
    }
    return myAns;
}

//  ================== fastest ====================
int row_fill = 0, col_fill = 0;
long diag1_fill = 0L, diag2_fill = 0L;
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
vector<string> nQueen_fastest(int rSize, int cSize, int row, int tnq) {
    calls3++;                   //  to count recursion calls
    if (row == rSize || tnq <= 0) {
        vector<string> base;
        if (tnq == 0) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    for (int col = 0; col < cSize; col++) {
        if (isSafe_circle_btr(cSize, row, col)) {
            row_fill |= (1 << row);
            col_fill |= (1 << col);
            diag1_fill |= (1 << (row - col + cSize - 1));
            diag2_fill |= (1 << (row + col));

            vector<string> recAns = nQueen_fastest(rSize, cSize, row + 1, tnq - 1);

            row_fill &= (~(1 << row));
            col_fill &= (~(1 << col));
            diag1_fill &= (~(1 << (row - col + cSize - 1)));
            diag2_fill &= (~(1 << (row + col)));
            for (string ans : recAns) {
                myAns.push_back("(" + to_string(row) + ", " + to_string(col) + ")" + " " + ans);
            }
        }
    }
    return myAns;
}

int main(int args, char**argv) {
    // vector<vector<bool>> arr(4, vector<bool> (4, false));
    // vector<string> nQueen_c = nqueen_Comb(arr, 0, 4);
    // display(nQueen_c);
    // vector<string> nQueen_p = nqueen_Perm(arr, 4);
    // display(nQueen_p);
    // vector<string> nQueenBtr_c = nQueen_btr(arr, 0, 4);
    // display(nQueenBtr_c);
    // vector<string> nQueenfast_c =  nQueen_fastest(4, 4, 0, 4);
    // display(nQueenfast_c);
    
    vector<vector<bool>> arr(10, vector<bool> (10, false));
    vector<string> ans_slow = nqueen_Comb(arr, 0, 10);
    vector<string> ans_fast = nQueen_fastest(10, 10, 0, 10);
    cout << calls1 << " , " << calls2 << " , " << calls3 << endl;
    return 0;
}