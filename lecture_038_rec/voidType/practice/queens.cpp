#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

//  ========== one D ============
int queen1D_comb(int size, int vidx, int tnq, int qpsf, string ans) {
    if (vidx == size || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int i = vidx; i < size; i++) {
        count += queen1D_comb(size, i + 1, tnq, qpsf + 1, ans + "b"+ to_string(i) + "q" + to_string(qpsf) + " ");
    }
    return count;
}

int queen1D_comb_subSeq(int size, int vidx, int tnq, int qpsf, string ans) {
    if (vidx == size || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    count += queen1D_comb_subSeq(size, vidx + 1, tnq, qpsf + 1, ans + "b"+ to_string(vidx) + "q" + to_string(qpsf) + " ");
    count += queen1D_comb_subSeq(size, vidx + 1, tnq, qpsf, ans);
    return count;
}

int queen1D_perm(int size, int vis, int tnq, int qpsf, string ans) {
    if (qpsf == tnq) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!(vis & (1 << i))) {
            vis |= (1 << i);
            count += queen1D_perm(size, vis, tnq, qpsf + 1, ans + "b"+ to_string(i) + "q" + to_string(qpsf) + " ");
            vis &= (~(1 << i));
        }
    }
    return count;
}

int queen1D_perm_subSeq(int size, int vis, int vidx, int tnq, int qpsf, string ans) {
    if (vidx == size || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (!(vis & (1 << vidx))) {
        vis |= (1 << vidx);
        count += queen1D_perm_subSeq(size, vis, 0, tnq, qpsf + 1, ans + "b"+ to_string(vidx) + "q" + to_string(qpsf) + " ");
        vis &= (~(1 << vidx));
    }
    count += queen1D_perm_subSeq(size, vis, vidx + 1, tnq, qpsf, ans);
    return count;
}

//  ============ two D =============
int queen2D_comb(vector<vector<bool>> &board, int vidx, int qpsf, int tnq, string ans) {
    if (qpsf == tnq) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = vidx; i < board.size() * board[0].size(); i++) {
        int r = i / board[0].size();
        int c = i % board[0].size();
        count += queen2D_comb(board, i + 1, qpsf + 1, tnq, ans + "(" + to_string(r) + "," + to_string(c) + ")" + to_string(qpsf) + " ");
    }
    return count;
}

int queen2D_comb_subSeq(vector<vector<bool>> &board, int vidx, int qpsf, int tnq, string ans) {
    if (vidx == board.size() * board[0].size() || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    int r = vidx / board[0].size();
    int c = vidx % board[0].size();
    count += queen2D_comb_subSeq(board, vidx + 1, qpsf + 1, tnq, ans + "(" + to_string(r) + "," + to_string(c) + ")" + to_string(qpsf) + " ");
    count += queen2D_comb_subSeq(board, vidx + 1, qpsf, tnq, ans);
    return count;
}

int queen2D_perm(vector<vector<bool>> &board, int qpsf, int tnq, string ans) {
    if (qpsf == tnq) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < board.size() * board[0].size(); i++) {
        int r = i / board[0].size();
        int c = i % board[0].size();
        if (!board[r][c]) {
            board[r][c] = true;
            count += queen2D_perm(board, qpsf + 1, tnq, ans + "(" + to_string(r) + "," + to_string(c) + ")" + to_string(qpsf) + " ");
            board[r][c] =false;
        }
    }
    return count;
}

int queen2D_perm_subSeq(vector<vector<bool>> &board, int vidx, int qpsf, int tnq, string ans) {
    if (vidx == board.size() * board[0].size() || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    int r = vidx / board[0].size();
    int c = vidx % board[0].size();
    if (!board[r][c]) {
        board[r][c] = true;
        count += queen2D_perm_subSeq(board, 0, qpsf + 1, tnq, ans + "(" + to_string(r) + "," + to_string(c) + ")" + to_string(qpsf) + " ");
        board[r][c] =false;
    }
    count += queen2D_perm_subSeq(board, vidx + 1, qpsf, tnq, ans);
    return count;
}

//  ========== main ==========

void oneD(int size, int tnq) {
    // cout << queen1D_comb(size, 0, tnq, 0, "") << endl;
    // cout << queen1D_comb_subSeq(size, 0, tnq, 0, "") << endl;
    // cout << queen1D_perm(size, 0, tnq, 0, "") << endl;
    // cout << queen1D_perm_subSeq(size, 0, 0, tnq, 0, "") << endl;
}

void twoD(int row, int col, int tnq) {
    vector<vector<bool>> arr(row, vector<bool> (col, false));
    // cout << queen2D_comb(arr, 0, 0, 4, "") << endl;
    // cout << queen2D_comb_subSeq(arr, 0, 0, 4, "") << endl;
    // cout << queen2D_perm(arr, 0, 4, "") << endl;
    // cout << queen2D_perm_subSeq(arr, 0, 0, 4, "") << endl;
}

int main(int args, char**argv) {
    oneD(5, 3);
    twoD(4, 4, 4);
    return 0;
}