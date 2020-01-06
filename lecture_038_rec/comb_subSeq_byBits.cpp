//  combination = subsequence tree 
//  subsequence tree is similar to binary counting
//  sub sequence method ques can be done by bits in for loop

#include<iostream>
#include<vector>
#include<string>
#include<math.h>
using namespace std;

//  ========= sub sequences of {a, b, c} ===========

int with_Comb(vector<char> &arr, int vidx, string ans) {
    cout << "[" << ans << "]" << endl;
    int count = 0;
    if (vidx == arr.size()) {
        return 1;
    }
    for (int i = vidx; i < arr.size(); i++) {
        count += with_Comb(arr, i + 1, ans + arr[i]);
    }
    return count + 1;
}

int with_subSeq(vector<char> &arr, int vidx, string ans) {
    if (vidx == arr.size()) {
        cout << "[" << ans << "]" << endl;
        return 1;
    }
    int count = 0;
    count += with_subSeq(arr, vidx + 1, ans);
    count += with_subSeq(arr, vidx + 1, ans + arr[vidx]);
    return count;
}

//  no recursion
int with_bits(vector<char> &arr) {
    int total = pow(2, arr.size());
    for (int i = 0; i < total; i++) {
        string ans = "";
        for (int j = 0; j < arr.size(); j++) {
            if (i & (1 << j)) {
                ans = arr[arr .size() - j - 1] + ans;
            }
        }
        cout << "[" << ans << "]" << endl;
    }
    return total;
}

int main(int args, char**argv) {
    vector<char> arr = {'a', 'b', 'c'};
    cout << with_bits(arr) << endl;
    cout << with_Comb(arr, 0, "") << endl;
    cout << with_subSeq(arr, 0, "") << endl;
    return 0;
}