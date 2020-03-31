//  coin change problem multi move permutation and combination by for loop solution(not subsequence solution)
//  use coin change combination for solving equation -->  2x + 3y + 5z + 7p = 10
/* 
solution :- 
    2 2 2 2 2   -> 2x  {x = 5}
    2 2 3 3     -> 2x + 3y  {x = 2, y = 2}
    2 3 5       -> 2x + 3y + 5z  {x = 1, y = 1, z = 1}
    3 7         -> 3y + 7p  {y = 1, p = 1}
*/

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vi& arr) {
    for (int i : arr) {
        cout << i << " ";
    } cout << endl;
}

void display(vii& arr) {
    for (vi v : arr) {
        for (int i : v) {
            cout << i << " ";
        } cout << endl;
    }
}

//  coin change permutation multi move by for loop(no subsequence), no dp
int coinChangePerm_01(int tar, vi& coins) {
    if (tar == 0) {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (tar - coins[i] >= 0) {
            count += coinChangePerm_01(tar - coins[i], coins);
        }
    }
    return count;
}

//  coin change combination multi move by for loop(no subsequence), no dp
int coinChangeComb_01(int tar, int vidx, vi& coins) {
    if (tar == 0) {
        return 1;
    }
    int count = 0;
    for (int i = vidx; i < coins.size(); i++) {
        if (tar - coins[i] >= 0) {
            count += coinChangeComb_01(tar - coins[i], i, coins);
        }
    }
    return count;
}

//  coin change permutation multi move by for loop(no subsequence), with dp memorization
int coinChangePerm_02(int tar, vi& coins, vi& dp) {
    if (tar == 0) {
        return dp[tar] = 1;
    }
    if (dp[tar] != 0) {
        return dp[tar];
    }
    int count = 0;
    for (int i = 0; i < coins.size(); i++) {
        if (tar - coins[i] >= 0) {
            count += coinChangePerm_02(tar - coins[i], coins, dp);
        }
    }
    return dp[tar] = count;
}

//  coin change combination multi move by for loop(no subsequence), with dp memorization( not recommended as uses 2D dp)
int coinChangeComb_02(int tar, int vidx, vi& coins, vii& dp) {
    if (tar == 0) {
        return dp[tar][vidx] = 1;
    }
    if (dp[tar][vidx] != 0) {
        return dp[tar][vidx];
    }
    int count = 0;
    for (int i = vidx; i < coins.size(); i++) {
        if (tar - coins[i] >= 0) {
            count += coinChangeComb_02(tar - coins[i], i, coins, dp);
        }
    }
    dp[tar][vidx] = count;
    return count;
}

//  coin change permutation multi move by for loop(no subsequence), with dp tabulation
int coinChangePerm_03(int tar, vi& coins) {
    vi dp(tar + 1, 0);
    dp[0] = 1;
    for (int t = 1; t <= tar; t++) {                    //  change to next target for calculating answer for a all coins at once
        for (int i = 0; i < coins.size(); i++) {        //  find solution for all coin for present target
            if (t - coins[i] >= 0) {
                dp[t] += dp[t - coins[i]];
            }
        }
    }
    display(dp);
    return dp[tar];
}

//  coin change combination multi move by for loop(no subsequence), with dp tabulation
int coinChangeComb_03(int tar, vi& coins) {
    vi dp(tar + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < coins.size(); i++) {        //  find solution for one coin for all 0 to target numbers
        for (int t = 1; t <= tar; t++) {            //  change to next target for calculating answer for a particular coin as previous
            if (t - coins[i] >= 0) {
                dp[t] += dp[t - coins[i]];
            }
        }
    }
    display(dp);
    return dp[tar];
}

void solvePerm(int tar, vi& coins) {
    cout << coinChangePerm_01(tar, coins) << endl;

    vi dp(tar + 1, 0);
    cout << coinChangePerm_02(tar, coins, dp) << endl;
    display(dp);

    cout << coinChangePerm_03(tar, coins) << endl;
}

void solveComb(int tar, vi& coins) {
    cout << coinChangeComb_01(tar, 0, coins) << endl;

    vii dp(tar + 1, vi(coins.size(), 0));
    cout << coinChangeComb_02(tar, 0, coins, dp) << endl;
    display(dp);

    cout << coinChangeComb_03(tar, coins) << endl;
}

int main(int args, char**argv) {
    vector<int> coins = {2, 3, 5, 7};
    int tar = 20;
    // solvePerm(tar, coins);
    solveComb(tar, coins);
    return 0;
}