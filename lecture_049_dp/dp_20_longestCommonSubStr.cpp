//  find longest common substring(LCS)
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

//  wrong approach, will only return subsequence, not substring, appears to be right, nut actually is wrong
/* int LCS_00(string str1, int i, string str2, int j) {
    if (i == str1.length() || j == str2.length()) {
        return 0;
    }
    int maxLen = 0;
    if (str1[i] == str2[j]) {       //  agar equal to mera contribution lo 1 ka and aage ki length le aao
        maxLen = LCS_00(str1, i + 1, str2, j + 1) + 1;
    }
    //  mujhe chorh kar aage ki length laao(for bith strings) aur maxLen mai sabse max length daal do
    maxLen =  max(maxLen, max(LCS_00(str1, i + 1, str2, j), LCS_00(str1, i, str2, j + 1)));
    return maxLen;
} */

//  longest common substring recursion, with static, no dp
//  dummy calls to keep recursion flowing
int LCS_01_ans = 0;
int LCS_01(string str1, int i, string str2, int j) {
    if (i == str1.length() || j == str2.length()) {
        return 0;
    }
    int ans = 0;        //  dummy or this-stage ans
    if (str1[i] == str2[j]) {
        ans = LCS_01(str1, i + 1, str2, j + 1) + 1;
    }
    LCS_01(str1, i + 1, str2, j);       //  dummy calls to keep recursion moving
    LCS_01(str1, i, str2, j + 1);       //  won't contribute in this stage ans;
    //  setting actual ans
    LCS_01_ans = max(LCS_01_ans, ans);
    return ans;
}

//  longest common substring recursion, with static, with dp memorisation
//  dummy calls to keep recursion flowing
int LCS_02_ans = 0;
int LCS_02(string str1, int i, string str2, int j, vector<vector<int>>& dp) {
    if (i == str1.length() || j == str2.length()) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int ans = 0;        //  dummy or this-stage ans
    if (str1[i] == str2[j]) {
        ans = LCS_02(str1, i + 1, str2, j + 1, dp) + 1;
    }
    LCS_02(str1, i + 1, str2, j, dp);       //  dummy calls to keep recursion moving
    LCS_02(str1, i, str2, j + 1, dp);       //  won't contribute in this stage ans;
    //  setting actual ans
    LCS_02_ans = max(LCS_02_ans, ans);
    return dp[i][j] = ans;
}

//  longest common substring recursion like, with static like variable out of loop, with dp tabulation
//  dummy calls(to keep recursion flowing) omittied as its iterative
int LCS_03(string str1, string str2) {
    vector<vector<int>> dp (str1.length() + 1, vector<int> (str2.length() + 1, 0));
    int maxAns = 0;
    for (int i = str1.length() - 1; i >= 0; i--) {
        for (int j = str2.length() - 1; j >= 0; j--) {        
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i + 1][j + 1] + 1;
            }
            maxAns = max(maxAns, dp[i][j]);
        }
    }
    display(dp);
    return maxAns;
}

void solve(string str1, string str2) {
    LCS_01(str1, 0, str2, 0);
    cout << LCS_01_ans << endl;

    vector<vector<int>> dp2(str1.length(), vector<int> (str2.length(), -1));
    LCS_02(str1, 0, str2, 0, dp2);
    cout << LCS_02_ans << endl;
    display(dp2);

    cout << LCS_03(str1, str2) << endl;
}

int main(int args, char**argv) {
    // string str1 = "AGGTAB";
    // string str2 = "GXTxAYB";
    // string str1 = "abcdfhijk";
    // string str2 = "abceghijk";
    string str1 = "abcefhijk";
    string str2 = "abcdghijk";
    solve(str1, str2);
    return 0;
}