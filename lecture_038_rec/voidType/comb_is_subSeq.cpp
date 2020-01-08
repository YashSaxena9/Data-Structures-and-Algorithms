//  combination ==> sub sequence
//  subsequence ==> bits in loop

/* ========== print this subsequence in this order ============
[
    [],
    [1],
    [1,2],
    [1,2,3],
    [1,3],
    [2],
    [2,3],
    [3]
]
=========================== end ============================ */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void combin_tree_preOrder(vector<int> &arr, int vidx, string ans) {
    cout << "[" << ans << "]" << endl;
    if (vidx == arr.size()) {
        return;
    }
    // cout<<ans<<endl;
    for (int i = vidx; i < arr.size(); i++) {
        combin_tree_preOrder(arr, i + 1, ans + to_string(arr[i]));
    }
}

int main(int args, char**argv) {
    vector<int> arr = {1, 2, 3};
    combin_tree_preOrder(arr, 0, "");
    return 0;
}