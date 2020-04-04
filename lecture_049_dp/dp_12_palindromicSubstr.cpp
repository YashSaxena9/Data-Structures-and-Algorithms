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

bool palindromeSubstr_02(int si, int ei, string str, vii& dp) {
    if (si >= ei) {
        return dp[si][ei] = (si == ei) ? 1 : 0;
    }
    if (dp[si][ei] != 0) {
        return dp[si][ei];
    }
    if (str[si] == str[ei] && ei - si == 1) {
        dp[si][ei] = 2;
    } else if (str[si] == str[ei]) {
        dp[si][ei] = palindromeSubstr_02(si + 1, ei - 1, str, dp);
        dp[si][ei] += (dp[si][ei] >= 0) ? 2 : 0;
    } else {

    }
    return count;
}

int palindromeSubseq_02(int si, int ei, string str) {
    if (si > ei) {
        return 0;
    }
    if (si == ei ) {
        return 1;
    } else if (str[si] == str[ei]) {
        return palindromeSubseq_02(si + 1, ei, str) + palindromeSubseq_02(si, ei - 1, str) + 1;
    } else {
        return palindromeSubseq_02(si + 1, ei, str) + palindromeSubseq_02(si, ei - 1, str) - palindromeSubseq_02(si + 1, ei - 1, str);
    }
}

//  total palindromic substrings, with tabulation
int totalPalindromeSubstr(string str) {
    vbb dp(str.length(), vb (str.length(), false));
    int count = 0;
    for (int gap = 0; gap < str.length(); gap++) {
        for (int i = 0, j = gap; j < str.length(); j++, i++) {
            if (gap == 0) {
                dp[i][j] = true;
            } else if (str[i] == str[j]) {
                if (gap == 1) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            if (dp[i][j]) {     //  counting number of trues
                count++;
            }
        }
    }
    // for (int gap = 0; gap < str.length(); gap++) {
    //     for (int i = 0, j = gap; j < str.length(); j++, i++) {
    //         if (dp[i][j]) {
    //             count++;
    //         }
    //     }
    // }
    display(dp);
    return count;
}

//  longest palindromic substrings, with tabulation
int longestPalindromeSubstr_01(string str) {
    vbb dp(str.length(), vb (str.length(), false));
    int maxLen = 0;
    for (int gap = 0; gap < str.length(); gap++) {
        for (int i = 0, j = gap; j < str.length(); j++, i++) {
            if (gap == 0) {
                dp[i][j] = true;
            } else if (str[i] == str[j]) {
                if (gap == 1) {
                    dp[i][j] = true;
                } else {
                    dp[i][j] = dp[i + 1][j - 1];
                }
            }
            maxLen = max(maxLen, (dp[i][j]) ? j - i + 1 : 0);       //  calculating maximum length
        }
    }
    display(dp);
    return maxLen;
}

//  grow the substring in both direction  :  (0 <- [i, j] -> str.length() - 1)
int growAndCheckPalindrome(int i, int j, string str) {
    while (i >= 0 && j < str.length() && str[i] == str[j]) {
        i--;
        j++;
    }
    i++;
    j--;
    return j - i + 1;
}

//  longest palindromic substrings, with tabulation (no extra space)
int longestPalindromeSubstr_02(string str) {
    int maxLen = 0;
    vii dp(str.length(), vi (str.length(), 0));
    for (int i = 0; i < str.length() - 1; i++) {
        int odd = growAndCheckPalindrome(i, i, str);        //  odd length substring
        int even = growAndCheckPalindrome(i, i + 1, str);        //  even length substring
        maxLen = max(maxLen, max(odd, even));
    }
    return maxLen;
}

void solve() {
    string str1 = "abccbdefeg";
    string str2 = "efabcbadd";
    string str3 = "abbccd";
    string str4 = "amrmsra";
    cout << str1 << endl;

    cout << totalPalindromeSubstr(str2) << endl;
    // cout << palindromeSubseq_02(0, str4.length() - 1, str4) << endl;

    // cout << palindromeSubstr_03(str4) << endl;
    cout << longestPalindromeSubstr_01(str2) << endl;

    cout << longestPalindromeSubstr_02(str2) << endl;
}

int main(int args, char**argv) {
    solve();
    return 0;
}