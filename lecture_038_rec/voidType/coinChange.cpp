#include<iostream>
#include<vector>
#include<string>
using namespace std;

int coinChange_inf_perm(vector<int> &arr, int tar, string ans) {
    if (tar == 0) {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (tar - arr[i] >= 0) {
            count += coinChange_inf_perm(arr, tar - arr[i], ans + to_string(arr[i]));
        }
    }
    return count;
}

int coinChange_inf_comb(vector<int> &arr, int idx, int tar, string ans) {
    if (tar == 0) {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for (int i = idx; i < arr.size(); i++) {
        if (tar - arr[i] >= 0) {
            count += coinChange_inf_comb(arr, i, tar - arr[i], ans + to_string(arr[i]));
        }
    }
    return count;
}

int coinChange_noRep_comb(vector<int> &arr, int idx, int tar, string ans) {
    if (tar == 0) {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for (int i = idx; i < arr.size(); i++) {
        if (tar - arr[i] >= 0) {
            count += coinChange_noRep_comb(arr, i + 1, tar - arr[i], ans + to_string(arr[i]));
        }
    }
    return count;
}

int coinChange_noRep_perm(vector<int> &arr, vector<bool> &vis, int tar, string ans) {
    if (tar == 0) {
        cout<<ans<<endl;
        return 1;
    }
    int count = 0;
    for (int i = 0; i < arr.size(); i++) {
        if (!vis[i] && tar - arr[i] >= 0) {
            vis[i] = true;
            count += coinChange_noRep_perm(arr, vis, tar - arr[i], ans + to_string(arr[i]));
            vis[i] = false;
        }
    }
    return count;
}

int coinChange_inf_comb_subSeq(vector<int> &arr, int vidx, int tar, string ans) {
    if (vidx == arr.size() || tar == 0) {
        if (tar == 0) {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (tar - arr[vidx] >= 0) {
        count += coinChange_inf_comb_subSeq(arr, vidx, tar - arr[vidx], ans + to_string(arr[vidx]));
    }
    count += coinChange_inf_comb_subSeq(arr, vidx + 1, tar, ans);
    return count;
}

int coinChange_noRep_comb_subSeq(vector<int> &arr, int vidx, int tar, string ans) {
    if (vidx == arr.size() || tar == 0) {
        if (tar == 0) {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (tar - arr[vidx] >= 0) {
        count += coinChange_noRep_comb_subSeq(arr, vidx + 1, tar - arr[vidx], ans + to_string(arr[vidx]));
    }
    count += coinChange_noRep_comb_subSeq(arr, vidx + 1, tar, ans);
    return count;
}

int coinChange_inf_perm_subSeq(vector<int> &arr, int vidx, int tar, string ans) {
    if (vidx == arr.size() || tar == 0) {
        if (tar == 0) {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (tar - arr[vidx] >= 0) {
        count += coinChange_inf_perm_subSeq(arr, 0, tar - arr[vidx], ans + to_string(arr[vidx]));
    }
    count += coinChange_inf_perm_subSeq(arr, vidx + 1, tar, ans);
    return count;
}

int coinChange_noRep_perm_subSeq(vector<int> &arr, vector<bool> &vis, int vidx, int tar, string ans) {
    if (vidx == arr.size() || tar == 0) {
        if (tar == 0) {
            cout<<ans<<endl;
            return 1;
        }
        return 0;
    }
    int count = 0;
    if (!vis[vidx] && tar - arr[vidx] >= 0) {
        vis[vidx] = true;
        count += coinChange_noRep_perm_subSeq(arr, vis, 0, tar - arr[vidx], ans + to_string(arr[vidx]));
        vis[vidx] = false;
    }
    count += coinChange_noRep_perm_subSeq(arr, vis, vidx + 1, tar, ans);
    return count;
}

int main(int args, char**argv) {
    vector<int> arr = {2,3,5,7};
    vector<bool> vis(arr.size(), false);
    int tar = 10;
    // cout<<coinChange_inf_perm(arr, tar, "")<<endl;
    // cout<<coinChange_inf_comb(arr, 0, tar, "")<<endl;
    // cout<<coinChange_noRep_comb(arr, 0, tar, "")<<endl;
    cout<<coinChange_noRep_perm(arr, vis, tar, "")<<endl;
    // cout<<coinChange_inf_comb_subSeq(arr, 0, tar, "")<<endl;
    // cout<<coinChange_noRep_comb_subSeq(arr, 0, tar, "")<<endl;
    // cout<<coinChange_inf_perm_subSeq(arr, 0, tar, "")<<endl;
    cout<<coinChange_noRep_perm_subSeq(arr, vis, 0, tar, "")<<endl;
    return 0;
}