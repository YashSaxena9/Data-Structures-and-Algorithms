#include<iostream>
#include<vector>
#include<string>
using namespace std;

//  ============ display ===========
void display(vector<string> &arr) {
    for (string ar : arr) {
        cout << ar << endl;
    }
    cout << arr.size() << endl;
}

//  ============ combination =============

vector<string> comb_inf(vector<int> &arr, int vidx, int tar) {
    if (tar == 0) {
        vector<string>base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int i = vidx; i < arr.size(); i++) {
        if (tar - arr[i] >= 0) {
            vector<string> recAns = comb_inf(arr, i, tar - arr[i]);
            for (string ra : recAns) {
                myAns.push_back(ra + to_string(arr[i]) + " ");
            }
        }
    }
    return myAns;
}

vector<string> comb_inf_subSeq(vector<int> &arr, int vidx, int tar) {
    if (vidx == arr.size() || tar <= 0) {
        vector<string>base;
        if (tar == 0) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    vector<string> recAns1 = comb_inf_subSeq(arr, vidx, tar - arr[vidx]);
    vector<string> recAns2 = comb_inf_subSeq(arr, vidx + 1, tar);
    for (string r : recAns1) {
        myAns.push_back(r + to_string(arr[vidx]) + " ");
    }
    for (string r : recAns2) {
        myAns.push_back(r);
    }
    return myAns;
}

vector<string> comb_noRep(vector<int> &arr, int vidx, int tar) {
    if (tar == 0) {
        vector<string>base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int i = vidx; i < arr.size(); i++) {
        if (tar - arr[i] >= 0) {
            vector<string> recAns = comb_noRep(arr, i + 1, tar - arr[i]);
            for (string ra : recAns) {
                myAns.push_back(ra + to_string(arr[i]) + " ");
            }
        }
    }
    return myAns;
}

vector<string> comb_noRep_subSeq(vector<int> &arr, int vidx, int tar) {
    if (vidx == arr.size() || tar <= 0) {
        vector<string>base;
        if (tar == 0) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    vector<string> recAns1 = comb_noRep_subSeq(arr, vidx + 1, tar - arr[vidx]);
    vector<string> recAns2 = comb_noRep_subSeq(arr, vidx + 1, tar);
    for (string r : recAns1) {
        myAns.push_back(r + to_string(arr[vidx]) + " ");
    }
    for (string r : recAns2) {
        myAns.push_back(r);
    }
    return myAns;
}

//  ============ permutation =============

vector<string> perm_inf(vector<int> &arr, int tar) {
    if (tar == 0) {
        vector<string>base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int ar : arr) {
        if (tar - ar >= 0) {
            vector<string> recAns = perm_inf(arr, tar - ar);
            for (string ra : recAns) {
                myAns.push_back(ra + to_string(ar) + " ");
            }
        }
    }
    return myAns;
}

vector<string> perm_inf_subSeq(vector<int> &arr, int vidx, int tar) {
    if (vidx == arr.size() || tar <= 0) {
        vector<string> base;
        if (tar == 0) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    vector<string> recAns1 = perm_inf_subSeq(arr, 0, tar - arr[vidx]);
    vector<string> recAns2 = perm_inf_subSeq(arr, vidx + 1, tar);
    for (string r : recAns1) {
        myAns.push_back(r + to_string(arr[vidx]) + " ");
    }
    for (string r : recAns2) {
        myAns.push_back(r);
    }
    return myAns;
}

vector<string> perm_noRep(vector<int> &arr, int vis, int tar) {
    if (tar == 0) {
        vector<string> base(1, "");
        return base;
    }
    vector<string> myAns;
    for (int i = 0; i < arr.size(); i++) {
        if (!(vis & (1 << i)) && tar - arr[i] >= 0) {
            vis |= (1 << i);
            vector<string> recAns = perm_noRep(arr, vis, tar - arr[i]);
            vis &= (~(1 << i));
            for (string ra : recAns) {
                myAns.push_back(ra + to_string(arr[i]) + " ");
            }
        }
    }
    return myAns;
}

vector<string> perm_noRep_subSeq(vector<int> &arr, int vis, int vidx, int tar) {
    if (vidx == arr.size() || tar <= 0) {
        vector<string> base;
        if (tar == 0) {
            base.push_back("");
        }
        return base;
    }
    vector<string> myAns;
    vector<string> recAns1;
    if (!(vis & (1 << vidx))) {
        vis |= (1 << vidx);
        recAns1 = perm_noRep_subSeq(arr, vis, 0, tar - arr[vidx]);
        vis &= (~(1 << vidx));
    }
    vector<string> recAns2 = perm_noRep_subSeq(arr, vis, vidx + 1, tar);
    for (string r : recAns1) {
        myAns.push_back(r + to_string(arr[vidx]) + " ");
    }
    for (string r : recAns2) {
        myAns.push_back(r);
    }
    return myAns;
}

//  ============ main ===========
void comb(vector<int> &arr, int tar) {
    // vector<string> inf_c = comb_inf(arr, 0, tar);
    // display(inf_c);
    // vector<string> infSub_c = comb_inf_subSeq(arr, 0, tar);
    // display(infSub_c);
    // vector<string> noRep_c = comb_noRep(arr, 0, tar);
    // display(noRep_c);
    // vector<string> noRepSub_c = comb_noRep_subSeq(arr, 0, tar);
    // display(noRepSub_c);
}

void perm(vector<int> &arr, int tar) {
    // vector<string> inf_p = perm_inf(arr, tar);
    // display(inf_p);
    // vector<string> infSub_p = perm_inf_subSeq(arr, 0, tar);
    // display(infSub_p);
    // vector<string> noRep_p = perm_noRep(arr, 0, tar);
    // display(noRep_p);
    // vector<string> noRepSub_p = perm_noRep_subSeq(arr, 0, 0, tar);
    // display(noRepSub_p);
}

int main(int args, char**argv) {
    vector<int> arr = {2, 3, 5, 7};
    int tar = 10;
    comb(arr, tar);
    perm(arr, tar);
    return 0;
}