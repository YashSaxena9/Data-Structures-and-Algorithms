#include <iostream>
#include <vector>
using namespace std;

void display(vector<vector<bool>>& arr) {
    for (vector<bool>& ar : arr) {
        for (bool b : ar) {
            cout << b << " ";
        } cout << endl;
    }
}

void display(vector<vector<int>>& arr) {
    for (vector<int>& ar : arr) {
        for (int b : ar) {
            cout << b << " ";
        } cout << endl;
    }
}

//  fills a matrix with true for those substrings which are palindrome
void fillPalindDp(string str, vector<vector<bool>>& dp) {
    for (int gap = 0; gap < str.size(); gap++) {
        for (int i = 0, j = gap; j < str.size(); i++, j++) {
            if (gap == 0) {
                dp[i][j] = true;
            } else if (str[i] == str[j]) {
                if (j - 1 == i) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }
    }
}

//  find minimum cuts required to make a string palindrome by recursion, no dp
int minPalindCuts_01(int si, int ei, string str, vector<vector<bool>>& isPalind) {
    if (isPalind[si][ei]) {
        return 0;
    }
    // cout << " hit " << endl;
    int minAns = ei - si + 1;
    for (int cuts = si; cuts < ei; cuts++) {
        int left = minPalindCuts_01(si, cuts, str, isPalind);
        int right = minPalindCuts_01(cuts + 1, ei, str, isPalind);
        int myAns = left + right + 1;
        minAns = min(minAns, myAns);
    }
    return minAns;
}

//  find minimum cuts required to make a string palindrome by recursion, with dp memorisation
int minPalindCuts_02(int si, int ei, string str, vector<vector<bool>>& isPalind, vector<vector<int>>& dp) {
    if (isPalind[si][ei]) {
        return dp[si][ei] = 0;
    }
    if (dp[si][ei] != 0) {
        return dp[si][ei];
    }
    int minAns = ei - si + 1;
    for (int cuts = si; cuts < ei; cuts++) {
        int left = minPalindCuts_02(si, cuts, str, isPalind, dp);
        int right = minPalindCuts_02(cuts + 1, ei, str, isPalind, dp);
        int myAns = left + 1 + right;
        minAns = min(minAns, myAns);
    }
    return dp[si][ei] = minAns;
}

//  find minimum cuts required to make a string palindrome (came up after studying recursion with dp memorisation), with dp tabulation
int minPalindCuts_03(string str, vector<vector<bool>>& isPalind) {
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), 0));
    for (int gap = 1; gap < str.length(); gap++) {
        for (int i = 0, j = gap; j < str.length(); i++, j++) {
            if (isPalind[i][j]) {
                dp[i][j] = 0;
                continue;
            }
            int minAns = j - i + 1;
            for (int cuts = i; cuts < j; cuts++) {
                int left = dp[i][cuts];
                int right = dp[cuts + 1][j];
                minAns = min(minAns, left + 1 + right);
            }
            dp[i][j] = minAns;
        }
    }
    display(dp);
    return dp[0][str.length() - 1];
}

//  ------------------------------------------------------------------------------------

void solve(string str) {
    vector<vector<bool>> isPalind_dp(str.length(), vector<bool>(str.length(), false));
    fillPalindDp(str, isPalind_dp);
    // display(isPalind_dp);
    
    cout << minPalindCuts_01(0, str.length() - 1, str, isPalind_dp) << endl;
    
    vector<vector<int>> dp(str.length(), vector<int>(str.length(), 0));
    cout << minPalindCuts_02(0, str.length() - 1, str, isPalind_dp, dp) << endl;
    display(dp);

    cout << minPalindCuts_03(str, isPalind_dp) << endl;
}

int main(int args, char**argv) {
    string str1 = "ababbbabbababa";
    string str2 = "ab";
    string str3 = "abcdef";
    string str4 = "abcbddf";
    solve(str4);
}