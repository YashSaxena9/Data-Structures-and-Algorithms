//  find matrix chain multiplication (MCM) -> (GFG)

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vector<vector<int>>& arr) {
    for (vector<int>& ar : arr) {
        for (int i : ar) {
            cout << i << " ";
        } cout << endl;
    }
}

void display(vector<vector<string>>& arr) {
    for (vector<string>& ar : arr) {
        for (string i : ar) {
            cout << i << " ";
        } cout << endl;
    }
}

void display(vector<vector<pair<int, string>>>& arr) {
    for (vector<pair<int, string>>& ar : arr) {
        for (auto i : ar) {
            cout << i.first << " ";
        } cout << endl;
    }
}

int MCM_memo_01(vi& arr, int si, int ei) {
    if (si + 1 == ei) {
        return 0;
    }
    int myCost = (int)1e7;
    for (int cut = si + 1; cut < ei; cut++) {
        int left = MCM_memo_01(arr, si, cut);
        int right = MCM_memo_01(arr, cut, ei);
        int recCost =  left + (arr[si] * arr[cut] * arr[ei]) + right;
        myCost = min(recCost, myCost);
    }
    return myCost;
}

pair<int, string> MCM_withStr_01(vi& arr, int si, int ei) {
    if (si == ei - 1) {
        string str = string(1, ((char)(si + 'A')));
        return {0, str};
    }
    pair<int, string> minAns = {(int)1e7, ""};
    for (int cut = si + 1; cut < ei; cut++) {
        pair<int, string> left = MCM_withStr_01(arr, si, cut);
        pair<int, string> right = MCM_withStr_01(arr, cut, ei);
        int recAns = left.first + arr[si] * arr[cut] * arr[ei] + right.first;
        if (minAns.first > recAns) {
            minAns.first = recAns;
            minAns.second = "(" + left.second + right.second + ")";
        }
    }
    return minAns;
}

int MCM_memo_02(vi& arr, int si, int ei, vii& dp) {
    if (si + 1 == ei) {
        return 0;
    }
    if (dp[si][ei] != 0) {
        return dp[si][ei];
    }
    int myCost = (int)1e7;
    for (int cut = si + 1; cut < ei; cut++) {
        int left = MCM_memo_02(arr, si, cut, dp);
        int right = MCM_memo_02(arr, cut, ei, dp);
        int recCost =  left + (arr[si] * arr[cut] * arr[ei]) + right;
        myCost = min(recCost, myCost);
    }
    return dp[si][ei] = myCost;
}

pair<int, string> MCM_withStr_02(vi& arr, int si, int ei, vector<vector<pair<int, string>>>& dp) {
    if (si == ei - 1) {
        string str = string(1, ((char)(si + 'A')));
        return dp[si][ei] = {0, str};
    }
    if (dp[si][ei].first != 0) {
        return dp[si][ei];
    }
    pair<int, string> minAns = {(int)1e7, ""};
    for (int cut = si + 1; cut < ei; cut++) {
        pair<int, string> left = MCM_withStr_02(arr, si, cut, dp);
        pair<int, string> right = MCM_withStr_02(arr, cut, ei, dp);
        int recAns = left.first + arr[si] * arr[cut] * arr[ei] + right.first;
        if (minAns.first > recAns) {
            minAns.first = recAns;
            minAns.second = "(" + left.second + right.second + ")";
        }
    }
    return dp[si][ei] = minAns;
}

int MCM_memo_03(vi& arr) {
    vii dp(arr.size(), vi(arr.size(), 0));
    for (int gap = 2; gap < arr.size(); gap++) {
        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++) {
            int myCost = (int)1e7;
            for (int cut = si + 1; cut < ei; cut++) {
                int left = dp[si][cut];
                int right = dp[cut][ei];
                int recCost =  left + (arr[si] * arr[cut] * arr[ei]) + right;
                myCost = min(recCost, myCost);
            }
            dp[si][ei] = myCost;
        }
    }
    display(dp);
    return dp[0][arr.size() - 1];
}

int MCM_withStr_03(vi& arr) {
    vii dp(arr.size(), vi(arr.size(), 0));
    vector<vector<string>> sdp(arr.size(), vector<string>(arr.size(), ""));
    for (int gap = 1; gap < arr.size(); gap++) {
        for (int si = 0, ei = gap; ei < arr.size(); si++, ei++) {
            if (gap == 1) {
                sdp[si][ei] = string(1, (char)(si + 'A'));
                continue;
            }
            int myCost = (int)1e7;
            for (int cut = si + 1; cut < ei; cut++) {
                int left = dp[si][cut];
                int right = dp[cut][ei];
                int recCost =  left + (arr[si] * arr[cut] * arr[ei]) + right;
                if (myCost > recCost) {
                    dp[si][ei] = recCost;
                    myCost = recCost;
                    sdp[si][ei] = "(" + sdp[si][cut] + sdp[cut][ei] + ")";
                }
            }
            dp[si][ei] = myCost;
        }
    }
    display(dp);
    display(sdp);
    return dp[0][arr.size() - 1];
}

void solve(vector<int>& arr) {
    // cout << MCM_memo_01(arr, 0, arr.size() - 1) << endl;
    
    // vector<vector<pair<int, string>>> dp2(arr.size(), vector<pair<int, string>>(arr.size(), {0, ""}));
    // pair<int, string> ans = MCM_withStr_02(arr, 0, arr.size() - 1, dp2);
    // cout << ans.second << " -> " << ans.first << endl;

    // vii dp1(arr.size(), vi(arr.size(), 0));
    // cout << MCM_memo_02(arr, 0, arr.size() - 1, dp1) << endl;
    // display(dp1);

    // cout << MCM_memo_03(arr) << endl;
    
    cout << MCM_withStr_03(arr) << endl;
}

int main(int args, char**argv) {
    vector<int> arr1 = {40, 20, 30, 10, 30};
    vector<int> arr2 = {10, 20, 30, 40, 30};
    solve(arr2);
    return 0;
}