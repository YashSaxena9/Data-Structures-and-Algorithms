//  find longest common sub-sequence(LCSS)
//  e.g. = ABCDGH / AEDFHR
//  here LCS = ADH -> length = 3

#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<int>>& arr) {
    for (vector<int>& v : arr) {
        for (int i : v) {
            cout << i << " ";
        } cout << endl;
    }
}

//  length of longest common subsequence using recursion, bad syntax
int LCSS_00(int si1, int si2, string str1, string str2, vector<vector<int>>& dp) {
    if (si1 == str1.length() || si2 == str2.length()) {
        return 0;
    }
    // if (dp[si1][si2] != 0) {
    //     return dp[si1][si2];
    // }
    int myAns = 0;
    for (int i = si1; i < str1.length(); i++) {
        for (int j = si2; j < str2.length(); j++) {
            if (str1[i] == str2[j]) {
                int recLen = LCSS_00(i + 1, j + 1, str1, str2, dp);
                myAns = max(myAns, recLen + 1);
            }
        }
    }
    // dp[si1][si2] = myAns;
    return myAns;
}

//  length of longest common subsequence using recursion, no dp
int LCSS_01(string str1, int i, string str2, int j) {
    if (i == str1.length() || j == str2.length()) {
        return 0;
    }
    if (str1[i] == str2[j]) {
        return LCSS_01(str1, i + 1, str2, j + 1) + 1;
    } else {
        return max(LCSS_01(str1, i + 1, str2, j), LCSS_01(str1, i, str2, j + 1));
    }
}

//  length of longest common subsequence using recursion, with dp memorisation
int LCSS_02(string str1, int i, string str2, int j, vector<vector<int>>& dp) {
    if (i == str1.length() || j == str2.length()) {
        return 0;
    }
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    int ans = 0;
    if (str1[i] == str2[j]) {
        ans = LCSS_02(str1, i + 1, str2, j + 1, dp) + 1;
    } else {
        ans = max(LCSS_02(str1, i + 1, str2, j, dp), LCSS_02(str1, i, str2, j + 1, dp));
    }
    return dp[i][j] = ans;
}

//  length of longest common subsequence, not using recursion, with dp tabulation
int LCSS_03(string str1, string str2) {
    vector<vector<int>> dp (str1.length() + 1, vector<int> (str2.length() + 1, 0));
    for (int i = str1.length() - 1; i >= 0; i--) {
        for (int j = str2.length() - 1; j >= 0; j--) {        
            int ans = 0;
            if (str1[i] == str2[j]) {
                ans = dp[i + 1][j + 1] + 1;
            } else {
                ans = max(dp[i][j + 1], dp[i + 1][j]);
            }
            dp[i][j] = ans;
        }
    }
    display(dp);
    return dp[0][0];
}

void solve(string str1, string str2) {
    // vector<vector<int>> dp1(str1.length(), vector<int> (str2.length(), 0));
    // cout << LCSS_00(0, 0, str1, str2, dp1) << endl;
    // display(dp1);

    // cout << LCSS_01(str1, 0, str2, 0) << endl;

    // vector<vector<int>> dp2(str1.length(), vector<int> (str2.length(), 0));
    // cout << LCSS_02(str1, 0, str2, 0, dp2) << endl;
    // display(dp2);

    // cout << LCSS_03(str1, str2) << endl;
}

int main(int args, char**argv) {
    // string str1 = "ABCDGH";
    // string str2 = "AEDFHR";
    string str1 = "AGGTAB";
    string str2 = "GXTxAYB";
    solve(str1, str2);
    return 0;
}