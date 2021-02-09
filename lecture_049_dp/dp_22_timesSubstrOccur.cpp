//  find number of times a sub-string occurs in a given string(GFG)
/* e.g. : string = "GeeksforGeeks", substr = "Gks"
       ans = 4
 */

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

//  return number of times given sub-string str2 repeats in str1 as subsequence, using recursion, no dp
int timesSubstrOccur_01(string str1, int i, string str2, int j) {
    if (i == str1.length() || j == str2.length()) {
        if (j == str2.length()) {
            return 1;
        }
        return 0;
    }
    int ans = 0;
    ans += timesSubstrOccur_01(str1, i + 1, str2, j);      //  not contribute
    if (str1[i] == str2[j]) {   //  if characters equal(contribute and not contribute)
        ans += timesSubstrOccur_01(str1, i + 1, str2, j + 1);      //  contribute
    }
    return ans;
}

//  return number of times given sub-string str2 repeats in str1 as subsequence, using recursion, with dp memorisation
int timesSubstrOccur_02(string str1, int i, string str2, int j, vector<vector<int>>& dp) {
    if (i == str1.length() || j == str2.length()) {
        if (j == str2.length()) {
            return dp[i][j] = 1;
        }
        return 0;
    }
    if (dp[i][j] != 0) {
        return dp[i][j];
    }
    int ans = 0;
    if (str1[i] == str2[j]) {   //  if characters equal(contribute and not contribute)
        ans += timesSubstrOccur_02(str1, i + 1, str2, j + 1, dp);      //  contribute
    }
    ans += timesSubstrOccur_02(str1, i + 1, str2, j, dp);      //  not contribute
    return dp[i][j] = ans;
}

//  return number of times given sub-string str2 repeats in str1 as subsequence, not using recursion, with dp tabulatiom
int timesSubstrOccur_03(string str1, string str2) {
    vector<vector<int>> dp (str1.length() + 1, vector<int> (str2.length() + 1));
    for (int i = str1.length(); i >= 0; i--) {
        for (int j = str2.length(); j >= 0; j--) {    
            if (i == str1.length() || j == str2.length()) {
                if (j == str2.length()) {
                    dp[i][j] = 1;
                }
                continue;
            }
            if (str1[i] == str2[j]) {   //  if characters equal(contribute and not contribute)
                dp[i][j] += dp[i + 1][j + 1];      //  contribute
            }
            dp[i][j] += dp[i + 1][j];      //  not contribute
        }
    }
    display(dp);
    return dp[0][0];
}

void solve(string str1, string str2) {
    // cout << timesSubstrOccur_01(str1, 0, str2, 0) << endl;
    
    // vector<vector<int>> dp (str1.length() + 1, vector<int>(str2.length() + 1, 0));
    // cout << timesSubstrOccur_02(str1, 0, str2, 0, dp) << endl;
    // display(dp);

    cout << timesSubstrOccur_03(str1, str2) << endl;
}

int main(int args, char**argv) {
    string str1 = "GeeksforGeeks";
    string str2 = "Gks";
    solve(str1, str2);
    return 0;
}