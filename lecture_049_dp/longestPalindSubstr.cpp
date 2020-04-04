//  count number of palindromic substring in a given string

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

//  palindromic substrings, with tabulation (with static like int, bool vector dp)
int longestPalindromeSubstr_03(string str) {
    int maxLength = 0;
    vbb dp(str.length(), vb (str.length(), false));
    for (int gap = 0; gap < str.length(); gap++) {
        for (int i = 0, j = gap; j < str.length(); j++, i++) {
            if (gap == 0) {
                dp[i][j] = true;
                maxLength = 1;
            } else if (str[i] == str[j]) {
                if (gap == 1) {
                    dp[i][j] = true;
                    maxLength = max(maxLength, j - i + 1);
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }
    }
    display(dp);
    return maxLength;
}

//  palindromic substrings, with tabulation (no static like int, int vector dp)
int longestPalindromeSubstr_04(string str) {
    vii dp(str.length(), vi (str.length(), 0));
    for (int gap = 0; gap < str.length(); gap++) {
        for (int i = 0, j = gap; j < str.length(); j++, i++) {
            if (gap == 0) {
                dp[i][j] = 1;
            } else if (str[i] == str[j]) {
                if (gap == 1) {
                    dp[i][j] = 2;
                } else if (dp[i + 1][j - 1] != 0) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
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

    cout << longestPalindromeSubstr_03(str4) << endl;

    cout << longestPalindromeSubstr_04(str4) << endl;
}

int main(int args, char**argv) {
    solve();
    return 0;
}