#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

//  ========= combination ==========
int comb_inf(vector<int> &arr, int tar, int vidx, string ans) {
    if (tar == 0) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = vidx; i < arr.size(); i++) {
        if (tar - arr[i] >= 0) {
            count += comb_inf(arr, tar - arr[i], i, ans + to_string(arr[i]) + " ");
        }
    }
    return count;
}

int comb_inf_subSeq(vector<int> &arr, int tar, int vidx, string ans) {
    if (vidx == arr.size() || tar <= 0) {
        if (tar == 0) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    count += comb_inf_subSeq(arr, tar - arr[vidx], vidx, ans + to_string(arr[vidx]) + " ");
    count += comb_inf_subSeq(arr, tar, vidx + 1, ans);
    return count;
}

int comb_noRep(vector<int> &arr, int tar, int vidx, string ans) {
    if (tar == 0) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = vidx; i < arr.size(); i++) {
        if (tar - arr[i] >= 0) {
            count += comb_noRep(arr, tar - arr[i], i + 1, ans + to_string(arr[i]) + " ");
        }
    }
    return count;
}

int comb_noRep_subSeq(vector<int> &arr, int tar, int vidx, string ans) {
    if (vidx == arr.size() || tar <= 0) {
        if (tar == 0) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    count += comb_noRep_subSeq(arr, tar - arr[vidx], vidx + 1, ans + to_string(arr[vidx]) + " ");
    count += comb_noRep_subSeq(arr, tar, vidx + 1, ans);
    return count;
}

//  =========== permutation ============
int perm_inf(vector<int> &arr, int tar, string ans) {
    if (tar == 0) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (tar - arr[i] >= 0) {
            count += perm_inf(arr, tar - arr[i], ans + to_string(arr[i]) + " ");
        }
    }
    return count;
}

int perm_inf_subSeq(vector<int> &arr, int vidx, int tar, string ans) {
    if (vidx == arr.size() || tar <= 0) {
        if (tar == 0) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    count += perm_inf_subSeq(arr, 0, tar - arr[vidx], ans + to_string(arr[vidx]) + " ");
    count += perm_inf_subSeq(arr, vidx + 1, tar, ans);
    return count;
}

int perm_noRep(vector<int> &arr, int vis, int tar, string ans) {
    if (tar == 0) {
        cout << ans << endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (!(vis & (1 << i)) && tar - arr[i] >= 0) {
            vis |= (1 << i);
            count += perm_noRep(arr, vis, tar - arr[i], ans + to_string(arr[i]) + " ");
            vis &= (~(1 << i));
        }
    }
    return count;
}

int perm_noRep_subSeq(vector<int> &arr, int vis, int vidx, int tar, string ans) {
    if (vidx == arr.size() || tar <= 0) {
        if (tar == 0) {
            cout << ans << endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (!(vis & (1 << vidx))) {
        vis |= (1 << vidx);
        count += perm_noRep_subSeq(arr, vis, 0, tar - arr[vidx], ans + to_string(arr[vidx]) + " ");
        vis &= (~(1 << vidx));
    }
    count += perm_noRep_subSeq(arr, vis, vidx + 1, tar, ans);
    return count;
}

//  ========== main =============
void combination(vector<int> &arr, int tar) {
    // cout << comb_inf(arr, tar, 0, "") << endl;
    // cout << comb_inf_subSeq(arr, tar, 0, "") << endl;
    // cout << comb_noRep(arr, tar, 0, "") << endl;
    // cout << comb_noRep_subSeq(arr, tar, 0, "") << endl;
}

void permutation(vector<int> &arr, int tar) {
    // cout << perm_inf(arr, tar, "") << endl;
    // cout << perm_inf_subSeq(arr, 0, tar, "") << endl;
    // cout << perm_noRep(arr, 0, tar, "") << endl;
    // cout << perm_noRep_subSeq(arr, 0, 0, tar, "") << endl;
}

int main(int args, char**argv) {
    vector<int> arr = {2,3,5,7};
    int tar = 10;
    combination(arr, tar);
    permutation(arr, tar);
    return 0;
}