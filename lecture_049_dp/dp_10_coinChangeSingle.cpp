//  coin change single move combination AKA target sum
//  coin change single move permutation does not support DP

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vii& arr) {
    for (vi& ar : arr) {
        for (int i : ar) {
            cout << i << " ";
        } cout << endl;
    }
}

//  using for loop method, tough to create in dp
int coinChangeComb_00(int tar, int idx, vi& options) {
    if (tar == 0) {
        return 1;
    }
    int count = 0;
    for (int i = idx; i < options.size(); i++) {
        if (tar - options[i] >= 0) {
            count += coinChangeComb_00(tar - options[i], i + 1, options);
        } 
    }
    return count;
}

//  using subsequence like calls method, no dp
int coinChangeComb_01(int tar, int idx, vi& options) {
    if (tar == 0) {
        return 1;
    }
    if (idx == options.size() || tar < 0) {
        return 0;
    }
    int count = 0;
    count += coinChangeComb_01(tar - options[idx], idx + 1, options);       //  contribute
    count += coinChangeComb_01(tar, idx + 1, options);                      //  doesn't contribute
    return count;
}

//  using subsequence like calls method, with dp memorization (calling in reverse order of option array)
int coinChangeComb_02(int tar, int idx, vi& options, vii& dp) {
    if (tar <= 0 || idx == -1) {
        if (tar == 0) {
            dp[idx + 1][tar] = 1;       //  idx + 1 as we assume we also have a coin of 0 present in the beginning of the options which is actually not present, but still our dp is created based on that assumtion so idx = 0 row of dp is utilised for coin of zero
            return 1;
        }
        return 0;
    }
    if (dp[idx + 1][tar] != 0) {       //  idx + 1 as we assume we also have a coin of 0 present in the beginning of the options which is actually not present, but still our dp is created based on that assumtion so idx = 0 row of dp is utilised for coin of zero
        return dp[idx + 1][tar];
    }
    int count = 0;
    count += coinChangeComb_02(tar - options[idx], idx - 1, options, dp);
    count += coinChangeComb_02(tar, idx - 1, options, dp);
    dp[idx + 1][tar] = count;       //  idx + 1 as we assume we also have a coin of 0 present in the beginning of the options which is actually not present, but still our dp is created based on that assumtion so idx = 0 row of dp is utilised for coin of zero
    return count;
}

//  using subsequence like calls method, with dp tabulation (calling in reverse order of option array)
int coinChangeComb_03(int tar, vi& options) {
    vii dp(options.size() + 1, vi(tar + 1, 0));
    dp[0][0] = 1;
    for (int idx = 1; idx <= options.size(); idx++) {
        int optionIdx = idx - 1;
        for (int t = 0; t <= tar; t++) {
            if (tar == 0) {
                dp[idx][tar] = 1;       //  idx + 1 as we assume we also have a coin of 0 present in the beginning of the options which is actually not present, but still our dp is created based on that assumtion so idx = 0 row of dp is utilised for coin of zero
                continue;
            }
            if (t - options[optionIdx] >= 0) {
                dp[idx][t] += dp[idx - 1][t - options[optionIdx]];
            }
            dp[idx][t] += dp[idx - 1][t];
        }
    }
    display(dp);
    return dp[options.size()][tar];
}

void solve(int tar, vi& options) {
    cout << coinChangeComb_00(tar, 0, options) << endl;

    vii dp(options.size() + 1, vi(tar + 1, 0));
    cout << coinChangeComb_01(tar, 0, options) << endl;
    
    cout << coinChangeComb_02(tar, options.size() - 1, options, dp) << endl;    //  we iterate from back of options to get desired dp
    display(dp);

    cout << coinChangeComb_03(tar, options) << endl;
}

int main(int args, char**argv) {
    int tar = 10;
    vi options = {2, 3, 5, 7};
    solve(tar, options);
    return 0;
}