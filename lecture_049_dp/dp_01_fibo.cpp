//  Fibonacci

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vi& arr) {
    for (int ele : arr) {
        cout << ele << " ";
    } cout << endl;
}

//  without dp
int fibo_01(int num) {
    if (num <= 1) {
        return num;
    }
    int ans = fibo_01(num - 1) + fibo_01(num - 2);
    return ans;
}

//  dp memorisation
int fibo_02(int num, vi& dp) {
    if (num <= 1) {
        dp[num] = num;  //  base case for dp
        return dp[num];
    }
    if (dp[num] != 0) {     // dp line(also for on off)
        return dp[num];
    }
    int ans = fibo_02(num - 1, dp) + fibo_02(num - 2, dp);
    dp[num] = ans;      //  dp on and off line
    return dp[num];
}

//  dp tabulation
int fibo_03(int num) {
    vector<int> dp(num + 1, 0);
    for (int i = 0; i <= num; i++) {
        if (i <= 1) {
            dp[i] = i;
            continue;
        }
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    // display(dp);
    return dp[num];
}

void solve() {
    int num = 40;
    cout << fibo_01(num) << endl;
    vector<int> dp(num + 1, 0);
    cout << fibo_02(num, dp) << endl;
    // display(dp);
    cout << fibo_03(num) << endl;
}

int main(int args, char**argv) {
    solve();
    return 0;
}