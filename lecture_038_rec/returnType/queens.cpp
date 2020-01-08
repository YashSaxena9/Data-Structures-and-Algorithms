#include<iostream>
#include<vector>
#include<string>
using namespace std;

//  =========== display ===========
void display(vector<string> &arr) {
    for (string r : arr) {
        cout << r << endl;
    }
    cout << arr.size() << endl;
}

//  =========== one D ============

vector<string> queen1D_comb(int size, int vidx, int qpsf, int tnq) {
    if (qpsf == tnq) {
        vector<string> base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int i = vidx; i < size; i++) {
        if (qpsf + 1 <= tnq) {
            vector<string> recAns = queen1D_comb(size, i + 1, qpsf + 1, tnq);
            for (string r : recAns) {
                myAns.push_back(r + "(b" + to_string(i) + ", q" + to_string(qpsf) + ") ");
            }
        }
    }
    return myAns;
}

vector<string> queen1D_comb_subSeq(int size, int vidx, int qpsf, int tnq) {
    if (vidx == size || qpsf >= tnq) {
        vector<string> base;
        if (qpsf == tnq) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    vector<string> recAns1 = queen1D_comb_subSeq(size, vidx + 1, qpsf + 1, tnq);
    vector<string> recAns2 = queen1D_comb_subSeq(size, vidx + 1, qpsf, tnq);
    for (string r : recAns1) {
        myAns.push_back(r + "(b" + to_string(vidx) + ", q" + to_string(qpsf) + ") ");
    }
    for (string r : recAns2) {
        myAns.push_back(r);
    }
    return myAns;
}

vector<string> queen1D_perm(int size, int vis, int qpsf, int tnq) {
    if (qpsf == tnq) {
        vector<string> base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int i = 0; i < size; i++) {
        if (!(vis & (1 << i)) && qpsf + 1 <= tnq) {
            vis |= (1 << i);
            vector<string> recAns = queen1D_perm(size, vis, qpsf + 1, tnq);
            vis &= (~(1 << i));
            for (string r : recAns) {
                myAns.push_back(r + "(b" + to_string(i) + ", q" + to_string(qpsf) + ") ");
            }
        }
    }
    return myAns;
}

vector<string> queen1D_perm_subSeq(int size, int vis, int vidx, int qpsf, int tnq) {
    if (vidx == size || qpsf >= tnq) {
        vector<string> base;
        if (qpsf == tnq) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    vector<string> recAns1;
    if (!(vis & (1 << vidx))) {
        vis |= (1 << vidx);
        recAns1 = queen1D_perm_subSeq(size, vis, 0, qpsf + 1, tnq);
        vis &= (~(1 << vidx));
    }
    vector<string> recAns2 = queen1D_perm_subSeq(size, vis, vidx + 1, qpsf, tnq);
    for (string r : recAns1) {
        myAns.push_back(r + "(b" + to_string(vidx) + ", q" + to_string(qpsf) + ") ");
    }
    for (string r : recAns2) {
        myAns.push_back(r);
    }
    return myAns;
}

//  =========== two D ============

vector<string> queen2D_comb(vector<vector<bool>> &board, int vidx, int tnq) {
    if (tnq == 0) {
        vector<string> base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int i = vidx; i < board.size() * board[0].size(); i++) {
        int r = i / board[0].size();
        int c = i % board[0].size();
        vector<string> recAns = queen2D_comb(board, i + 1, tnq - 1);
        for (string ans : recAns) {
            myAns.push_back("(" + to_string(r) + ", " + to_string(c) + ")" + ans);
        }
    }
    return myAns;
}

vector<string> queen2D_comb_subSeq(vector<vector<bool>> &board, int vidx, int tnq) {
    if (vidx == board.size() * board[0].size() || tnq <= 0) {
        vector<string> base;
        if (tnq == 0) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    int r = vidx / board[0].size();
    int c = vidx % board[0].size();
    vector<string> recAns1 = queen2D_comb_subSeq(board, vidx + 1, tnq - 1);
    vector<string> recAns2 = queen2D_comb_subSeq(board, vidx + 1, tnq);
    for (string ans : recAns1) {
        myAns.push_back("(" + to_string(r) + ", " + to_string(c) + ")" + ans);
    }
    for (string ans : recAns2) {
        myAns.push_back(ans);
    }
    return myAns;
}

vector<string> queen2D_perm(vector<vector<bool>> &board, int tnq) {
    if (tnq == 0) {
        vector<string> base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int i = 0; i < board.size() * board[0].size(); i++) {
        int r = i / board[0].size();
        int c = i % board[0].size();
        if (!board[r][c]) {
            board[r][c] = true;
            vector<string> recAns = queen2D_perm(board, tnq - 1);
            for (string ans : recAns) {
                myAns.push_back("(" + to_string(r) + ", " + to_string(c) + ")" + ans);
            }
            board[r][c] = false;
        }
    }
    return myAns;
}

vector<string> queen2D_perm_subSeq(vector<vector<bool>> &board, int vidx, int tnq) {
    if (vidx == board.size() * board[0].size() || tnq <= 0) {
        vector<string> base;
        if (tnq == 0) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    int r = vidx / board[0].size();
    int c = vidx % board[0].size();
    vector<string> recAns1;
    if (!board[r][c]) {
        board[r][c] = true;
        recAns1 = queen2D_perm_subSeq(board, 0, tnq - 1);
        board[r][c] = false;
    }
    vector<string> recAns2 = queen2D_perm_subSeq(board, vidx + 1, tnq);
    for (string ans : recAns1) {
        myAns.push_back("(" + to_string(r) + ", " + to_string(c) + ")" + ans);
    }
    for (string ans : recAns2) {
        myAns.push_back(ans);
    }
    return myAns;
}

//  =========== main ============

void oneD(int size, int tnq) {
    // vector<string> queen_c = queen1D_comb(size, 0, 0, tnq);
    // display(queen_c);
    // vector<string> queenSub_c = queen1D_comb_subSeq(size, 0, 0, tnq);
    // display(queenSub_c);

    // vector<string> queen_p = queen1D_perm(size, 0, 0, tnq);
    // display(queen_p);
    // vector<string> queenSub_p = queen1D_perm_subSeq(size, 0, 0, 0, tnq);
    // display(queenSub_p);
}

void twoD(vector<vector<bool>> &board, int tnq) {
    // vector<string> queen_c = queen2D_comb(board, 0, tnq);
    // display(queen_c);
    // vector<string> queenSub_c = queen2D_comb_subSeq(board, 0, tnq);
    // display(queenSub_c);
    // vector<string> queen_p = queen2D_perm(board, tnq);
    // display(queen_p);
    // vector<string> queenSub_p = queen2D_perm_subSeq(board, 0, tnq);
    // display(queenSub_p);
}

int main(int args, char**argv) {
    vector<vector<bool>> board(4, vector<bool> (4, false));
    oneD(5, 3);
    twoD(board, 4);
    return 0;
}