//  leetcode - 72  -->  Edit distance
/*  Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
 You have the following 3 operations permitted on a word:
 1 -> Insert a character
 2 -> Delete a character
 3 -> Replace a character */

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

//  convert str1 to str2, return number of operations required, using recursion, with dp memorisation
//  index wise, straight iteration of string using indexes
int minDistance_00(string str1, int i, string str2, int j, vector<vector<int>>& dp) {
    if (i == str1.length()) {   //  word1 insufficient, insert rest of the char of word 2
        return dp[i][j] = str2.length() - j;
    }
    if (j == str2.length()) {   //  word2 complete, delete rest of the char of word 1
        return dp[i][j] = str1.length() - i;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if (str1[i] == str2[j]) {
        //  char eual, operation on rest of the word
        ans = minDistance_00(str1, i + 1, str2, j + 1, dp);
    } else {
        //  char not equal, 1 operation + min(insert, replace, deletion)
        int deletion = minDistance_00(str1, i + 1, str2, j, dp);
        int replace = minDistance_00(str1, i + 1, str2, j + 1, dp);
        int insertion = minDistance_00(str1, i, str2, j + 1, dp);
        ans = 1 + min(insertion, min(replace, deletion));
    }
    return dp[i][j] = ans;
}

//  convert str1 to str2, return number of operations required, using recursion, no dp
//  index wise, reverse iteration of string using indexes
int minDistance_01(string str1, int i, string str2, int j) {
    if (i == -1) {   //  word1 insufficient, insert rest of the char of word 2
        return j + 1;       //  j + 1 as we need length of left substring for required operations
    }
    if (j == -1) {   //  word2 complete, delete rest of the char of word 1
        return i + 1;       //  i + 1 as we need length of left substring for required operations
    }
    int ans = 0;
    if (str1[i] == str2[j]) {
        //  char eual, operation on rest of the word
        ans = minDistance_01(str1, i - 1, str2, j - 1);
    } else {
        //  char not equal, 1 operation + min(insert, replace, deletion)
        int deletion = minDistance_01(str1, i - 1, str2, j);
        int replace = minDistance_01(str1, i - 1, str2, j - 1);
        int insertion = minDistance_01(str1, i, str2, j - 1);
        ans = 1 + min(insertion, min(replace, deletion));
    }
    return ans;
}

//  convert str1 to str2, return number of operations required, using recursion, with dp memorisation
//  index wise, reverse iteration of string using indexes
int minDistance_02(string str1, int i, string str2, int j, vector<vector<int>>& dp) {
    if (i == -1) {   //  word1 insufficient, insert rest of the char of word 2
        return j + 1;       //  j + 1 as we need length of left substring for required operations
    }
    if (j == -1) {   //  word2 complete, delete rest of the char of word 1
        return i + 1;       //  i + 1 as we need length of left substring for required operations
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if (str1[i] == str2[j]) {
        //  char equal, operation on rest of the word
        ans = minDistance_02(str1, i - 1, str2, j - 1, dp);
    } else {
        //  char not equal, 1 operation + min(insert, replace, deletion)
        int deletion = minDistance_02(str1, i - 1, str2, j, dp);
        int replace = minDistance_02(str1, i - 1, str2, j - 1, dp);
        int insertion = minDistance_02(str1, i, str2, j - 1, dp);
        ans = 1 + min(insertion, min(replace, deletion));
    }
    return dp[i][j] = ans;
}

//  convert str1 to str2, return number of operations required, using recursion, with dp memorisation
//  lengtg wise, reverse iteration of string using lengthg
int minDistance_02_withLen(string str1, int i, string str2, int j, vector<vector<int>>& dp) {
    if (i == 0) {   //  word1 insufficient, insert rest of the char of word 2
        return dp[i][j] = j;
    }
    if (j == 0) {   //  word2 complete, delete rest of the char of word 1
        return dp[i][j] = i;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;
    if (str1[i - 1] == str2[j - 1]) {
        //  char equal, operation on rest of the word
        ans = minDistance_02_withLen(str1, i - 1, str2, j - 1, dp);
    } else {
        //  char not equal, 1 operation + min(insert, replace, deletion)
        int deletion = minDistance_02_withLen(str1, i - 1, str2, j, dp);
        int replace = minDistance_02_withLen(str1, i - 1, str2, j - 1, dp);
        int insertion = minDistance_02_withLen(str1, i, str2, j - 1, dp);
        ans = 1 + min(insertion, min(replace, deletion));
    }
    return dp[i][j] = ans;
}

//  convert str1 to str2, return number of operations required, using recursion, with dp memorisation
//  lengtg wise, reverse iteration of string using lengthg
int minDistance_03_withLen(string str1, string str2) {
    vector<vector<int>> dp (str1.length() + 1, vector<int>(str2.length() + 1, 0));
    for (int i = 0; i <= str1.length(); i++) {
        for (int j = 0; j <= str2.length(); j++) {
            if (i == 0) {   //  word1 insufficient, insert rest of the char of word 2
                dp[i][j] = j;
                continue;
            }
            if (j == 0) {   //  word2 complete, delete rest of the char of word 1
                dp[i][j] = i;
                continue;
            }
            int ans = 0;
            if (str1[i - 1] == str2[j - 1]) {
                //  char equal, operation on rest of the word
                ans = dp[i - 1][j - 1];
            } else {
                //  char not equal, 1 operation + min(insert, replace, deletion)
                int deletion = dp[i - 1][j];
                int replace = dp[i - 1][j - 1];
                int insertion = dp[i][j - 1];
                ans = 1 + min(insertion, min(replace, deletion));
            }
            dp[i][j] = ans;
        }
    }
    
    display(dp);
    return dp[str1.length()][str2.length()];
}

void solve(string str1, string str2) {
    // vector<vector<int>> dp1(str1.length() + 1, vector<int>(str2.length() + 1, -1));
    // cout << minDistance_00(str1, 0, str2, 0, dp1) << endl;
    // display(dp1);

    // cout << minDistance_01(str1, str1.length() - 1, str2, str2.length() - 1) << endl;
    
    // vector<vector<int>> dp2(str1.length(), vector<int>(str2.length(), -1));
    // cout << minDistance_02(str1, str1.length() - 1, str2, str2.length() - 1, dp2) << endl;
    // display(dp2);
    
    vector<vector<int>> dp3(str1.length() + 1, vector<int>(str2.length() + 1, -1));
    cout << minDistance_02_withLen(str1, str1.length(), str2, str2.length(), dp3) << endl;
    display(dp3);

    cout << minDistance_03_withLen(str1, str2) << endl;
}

int main(int args, char**argv) {
    string str1 = "saturday";
    string str2 = "sunday";
    solve(str1, str2);
    return 0;
}