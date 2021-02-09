//  count number of palindromic subsequence in a given string

#include <iostream>
#include <vector>
#define vb vector<bool>
#define vbb vector<vb>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vbb& arr) {
    for (vb& ar : arr) {
        for (bool b : ar) {
            cout << b << " ";
            // cout << (boolalpha) << b << " ";
        } cout << endl;
    }
}

void display(vii& arr) {
    for (vi& ar : arr) {
        for (int i : ar) {
            cout << i << " ";
        } cout << endl;
    }
}

//  count all palindromic subsequences, no dp
int totalPalindromicSubseq_01(int si, int ei, string str) {
    if (si > ei) {
        return 0;
    }
    if (si == ei) {
        return 1;
    }
    if (str[si] == str[ei]) {
        return totalPalindromicSubseq_01(si + 1, ei, str) + totalPalindromicSubseq_01(si, ei - 1, str) + 1;
    } else {
        int count = 0;
        count += totalPalindromicSubseq_01(si + 1, ei, str);
        count += totalPalindromicSubseq_01(si, ei - 1, str);
        count -= totalPalindromicSubseq_01(si + 1, ei - 1, str);
        return count;
    }
}

//  count all palindromic subsequences, with dp memorisation
int totalPalindromicSubseq_02(int si, int ei, string str, vii& dp) {
    if (si > ei) {
        return 0;
    }
    if (si == ei) {
        return dp[si][ei] = 1;
    }
    if (dp[si][ei] != 0) {
        return dp[si][ei];
    }
    if (str[si] == str[ei]) {
        return dp[si][ei] = totalPalindromicSubseq_02(si + 1, ei, str, dp) + totalPalindromicSubseq_02(si, ei - 1, str, dp) + 1;
    } else {
        int count = 0;
        count += totalPalindromicSubseq_02(si + 1, ei, str, dp);
        count += totalPalindromicSubseq_02(si, ei - 1, str, dp);
        count -= totalPalindromicSubseq_02(si + 1, ei - 1, str, dp);
        return dp[si][ei] = count;
    }
}

//  count all palindromic subsequences, with dp tabulaion
int totalPalindromicSubseq_03(string str) {
    vii dp(str.length(), vi(str.length(), 0));
    for (int gap = 0; gap < str.length(); gap++) {
        for (int i = 0, j = gap; j < str.length(); j++, i++) {
            if (i == j) {
                dp[i][j] = 1;
            }
            else if (str[i] == str[j]) {
                // dp[i][j] = dp[i + 1][j - 1] + 1 + dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] + 1;
            } else {
                dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
            }
        }
    }
    display(dp);
    return dp[0][str.length() - 1];
}

//  give length of longest palindromic subsequence, with tabulation (no static like int, int vector dp)
int longestPalindromeSubseq_01(string str) {
    vii dp(str.length(), vi (str.length(), 0));
    for (int gap = 0; gap < str.length(); gap++) {
        for (int i = 0, j = gap; j < str.length(); j++, i++) {
            if (gap == 0) {
                dp[i][j] = 1;
            } else if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    display(dp);
    return dp[0][str.length() - 1];
}

void solve() {
    string str1 = "abccbdefeg";
    string str2 = "efabcbadd";
    string str3 = "abc";
    string str4 = "accd";
    string str5 = "amrmsra";

    cout << totalPalindromicSubseq_01(0, str5.size() - 1, str5) << endl;

    vii dp(str5.size(), vi(str5.size(), 0));
    cout << totalPalindromicSubseq_02(0, str5.size() - 1, str5, dp) << endl;
    display(dp);

    cout << totalPalindromicSubseq_03(str5) << endl;
    
    // cout << longestPalindromeSubseq_01(str5) << endl;
}

int main(int args, char**argv) {
    solve();
    return 0;
}