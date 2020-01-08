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
int queen2D_comb() {
    
}

//  ========== main ==========

void oneD(int size, int tnq) {
    // cout << queen1D_comb(size, 0, tnq, 0, "") << endl;
    // cout << queen1D_comb_subSeq(size, 0, tnq, 0, "") << endl;
    // cout << queen1D_perm(size, 0, tnq, 0, "") << endl;
    // cout << queen1D_perm_subSeq(size, 0, 0, tnq, 0, "") << endl;
}

int main(int args, char**argv) {
    oneD(5, 3);
    return 0;
}