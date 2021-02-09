#include<iostream>
#include<vector>
#include<string>
using namespace std;

// =============== 1 D ===================
int queens1D_comb(int size, int vidx, int tnq, int qpsf, string ans) {
    if (vidx == size || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int i = vidx; i < size; i++) {
        count += queens1D_comb(size, i + 1, tnq, qpsf + 1, ans + "b" + to_string(i) + "q" + to_string(qpsf) + " ");
    }
    return count;
}

int queens1D_subSeq_comb(int size, int vidx, int tnq, int qpsf, string ans) {
    if (vidx == size || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    count += queens1D_subSeq_comb(size, vidx + 1, tnq, qpsf + 1, ans + "b" + to_string(vidx) + "q" + to_string(qpsf) + " ");
    count += queens1D_subSeq_comb(size, vidx + 1, tnq, qpsf, ans);
    return count;
}

int queens1D_perm(int size, int vis, int tnq, int qpsf, string ans) {
    if (qpsf == tnq) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (!(vis & (1 << i))) {
            vis |= (1 << i);
            count += queens1D_perm(size, vis, tnq, qpsf + 1, ans + "b" + to_string(i) + "q" + to_string(qpsf) + " ");
            vis &= (~(1 << i));
        }
    }
    return count;
}

int queens1D_subSeq_perm(int size, int vidx, int vis, int tnq, int qpsf, string ans) {
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
        count += queens1D_subSeq_perm(size, 0, vis, tnq, qpsf + 1, ans + "b" + to_string(vidx) + "q" + to_string(qpsf) + " ");
        vis &= (~(1 << vidx));
    }
    count += queens1D_subSeq_perm(size, vidx + 1, vis, tnq, qpsf, ans);
    return count;
}

// =============== 2 D ===================

int queens2D_comb(int row, int col, int vidx, int tnq, int qpsf, string ans) {
    if (vidx == row * col || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    for (int i = vidx; i < row * col; i++) {
        count += queens2D_comb(row, col, i + 1, tnq, qpsf + 1, ans + "(" + to_string(i / col) + "," + to_string(i % col) + ")" + to_string(qpsf) + " ");
    }
    return count;
}

int queens2D_subSeq_comb(int row, int col, int vidx, int tnq, int qpsf, string ans) {
    int vr = vidx % col, vc = vidx / col;
    if (vidx == row * col || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    count += queens2D_subSeq_comb(row, col, vidx + 1, tnq, qpsf + 1, ans + "(" + to_string(vr / col) + "," + to_string(vc % col) + ")" + to_string(qpsf) + " ");
    count += queens2D_subSeq_comb(row, col, vidx + 1, tnq, qpsf, ans);
    return count;
}

int queens2D_perm(int row, int col, int vis, int tnq, int qpsf, string ans) {
    //  no need for vidx as loop will protect outOfBound exception 
    //  ans vidx is not used anywhere else
    if (qpsf == tnq) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < row * col; i++) {
        if (!(vis & (1 << i))) {
            vis |= (1 << i);
            count += queens2D_perm(row, col, vis, tnq, qpsf + 1, ans + "(" + to_string(i / col) + "," + to_string(i % col) + ")" + to_string(qpsf) + " ");
            vis &= (~(1 << i));
        }
    }
    return count;
}

int queens2D_subSeq_perm(int row, int col, int vidx, int vis, int tnq, int qpsf, string ans) {
    int vr = vidx / col, vc = vidx % col;
    if (vidx == row * col || qpsf >= tnq) {
        if (qpsf == tnq) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (!(vis & (1 << vidx))) {
        vis |= (1 << vidx);
        count += queens2D_subSeq_perm(row, col, 0, vis, tnq, qpsf + 1, ans + "(" + to_string(vr / col) + "," + to_string(vc % col) + ")" + to_string(qpsf) + " ");
        vis &= (~(1 << vidx));
    }
    count += queens2D_subSeq_perm(row, col, vidx + 1, vis, tnq, qpsf, ans);
    return count;
}

int main(int args, char**argv) {
    // cout << queens1D_comb(5, 0, 3, 0, "") << endl;
    // cout << queens1D_subSeq_comb(5, 0, 3, 0, "") << endl;
    // cout << queens1D_perm(5, 0, 3, 0, "") << endl;
    // cout << queens1D_subSeq_perm(5, 0, 0, 3, 0, "") << endl;
    
    cout << queens2D_comb(4, 4, 0, 4, 0, "") << endl;
    cout << queens2D_subSeq_comb(4, 4, 0, 4, 0, "") << endl;
    // cout << queens2D_perm(4, 4, 0, 4, 0, "");
    // cout << queens2D_subSeq_perm(4, 4, 0, 0, 4, 0, "");
    return 0;
}