#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vi& arr) {
    for (int i : arr) {
        cout << i << " ";
    } cout << endl;
}

int longestIncSubstr_01(vi& arr, int idx, int lnum, string ans) {
    if (idx == arr.size()) {
        cout << ans << endl;
        return 0;
    }
    int picked = -1, unpicked = -1;
    for (int i = idx + 1; i < arr.size(); i++) {
        if (arr[i] > lnum) {
            picked = max(picked, longestIncSubstr_01(arr, i, arr[i], ans + to_string(arr[i]) + " "));     //  start bnega
        }
    }
    if (picked != -1) {
        picked++;
    }
    unpicked = longestIncSubstr_01(arr, idx + 1, lnum, ans);   //  start nhi bnega
    return max(picked, unpicked);
}

int longestIncSubstr_02(vi& arr, int idx, int lnum, string ans, vi& dp) {
    if (idx == arr.size()) {
        cout << ans << endl;
        return 0;
    }
    if (dp[idx + 1] != 0) {
        return dp[idx + 1];
    }
    int picked = -1, unpicked = -1;
    unpicked = longestIncSubstr_02(arr, idx + 1, lnum, ans, dp);   //  start nhi bnega
    for (int i = idx + 1; i < arr.size(); i++) {
        if (arr[i] > lnum) {
            picked = max(picked, longestIncSubstr_02(arr, i, arr[i], ans + to_string(arr[i]) + " ", dp));     //  start bnega
        }
    }
    if (picked != -1) {
        picked++;
    }
    return dp[idx + 1] = max(picked, unpicked);
}

int longestIncSubstr_03(vi& arr) {
    vi dp(arr.size(), 1);
    int max_ = 1;
    for (int i = 1; i < arr.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_ = max(max_, dp[i]);
    }
    display(dp);
    return max_;
}

int longestDecSubstr_03(vi& arr) {
    vi dp(arr.size(), 1);
    int max_ = 1;
    for (int i = arr.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        max_ = max(max_, dp[i]);
    }
    display(dp);
    return max_;
}

void solve(vi& arr) {
    // cout << longestIncSubstr_01(arr, -1, -1e6, "") << endl;

    // vi dp(arr.size() + 1, 0);
    // cout << longestIncSubstr_02(arr, -1, -1e6, "", dp) << endl;
    // display(dp);

    cout << longestIncSubstr_03(arr) << endl;

    //  -------------------------------------------------------------

    cout << longestDecSubstr_03(arr) << endl;
}

int main(int args, char**argv) {
    vector<int> arr1 = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> arr2 = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    solve(arr2);
    return 0;
}