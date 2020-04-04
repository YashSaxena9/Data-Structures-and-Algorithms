//  friends pairing problem GFG
//  friends can stay in single or pair of two in group
//  count number of ways to divide them in a group

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
#define vl vector<long long int>
#define vll vector<vl>
using namespace std;

void display(vl& arr) {
    for (long long int i : arr) {
        cout << i << " ";
    } cout << endl;
}

//  only number of ways, no dp
long long int friendsPairing_01(long long int nums) {
    if (nums <= 1) {        //  base case can be nums <= 1 & nums <= 2 also
        return 1;
    }
    long long int count = 0;
    count += friendsPairing_01(nums - 1);
    /*  //  will use for loop only to get the string which we have paired
    for (long long int i = nums - 1; i > 0; i--) {
        count += friendsPairing_01(nums - 2);
    }
    */
    count += (nums - 1) * friendsPairing_01(nums - 2);
    return count;
}

//  only number of ways, with memorization dp (with extra space)
long long int friendsPairing_02(long long int nums, vl& dp) {
    if (nums <= 2) {            //  base
        dp[nums] = 1;
        return 1;
    }
    if (dp[nums] != 0) {        //  getting ans from dp if exist
        return dp[nums];
    }
    long long int count = 0;
    count += friendsPairing_02(nums - 1, dp);       //  single ways
    count += (nums - 1) * friendsPairing_02(nums - 2, dp);      //  pair ways
    dp[nums] = count;           //  dp on off line
    return count;
}

//  only number of ways, with tabulation dp (with extra space)
long long int friendsPairing_03(long long int nums) {
    vl dp(nums + 1, 0);
    for (int i = 1; i <= nums; i++) {
        if (i <= 2) {            //  base
            dp[i] = 1;
            continue;
        }
        long long int count = 0;
        count += dp[i - 1];       //  single ways
        count += (i - 1) * dp[i - 2];      //  pair ways
        dp[i] = count;           //  dp on off line
    }
    return dp[nums];
}

//  only number of ways, with tabulation dp (by deep-analysis, without extra space)
long long int friendsPairing_04(long long int nums) {
    long long int a = 1;  //  n = 0 (nothing to pair, so all are paired)
    long long int b = 1;  //  n = 1 (only one single, no pair)
    long long int ans = 0;
    for (int i = 2; i <= nums; i++) {
        ans = b + a * (i - 1);
        a = b;
        b = ans;
    }
    return b;
}

void solve() {
    int num = 100;
    vl dp1(num + 1, 0);
    // cout << friendsPairing_01(num) << endl;
    // cout << friendsPairing_02(num, dp1) << endl;
    // display(dp1);
    // cout << friendsPairing_03(num) << endl;
    cout << friendsPairing_04(num) << endl;
}

int main(int args, char**argv) {
    solve();
    return 0;
}