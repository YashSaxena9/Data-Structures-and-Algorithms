//  you are in a game board and have moves (using dice) to reach the end point

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vi& arr) {
    for (int i : arr) {
        cout << i << " ";
    }
    cout << endl;
}

//  board path multi move permutation using dice without dp
int boardPath_dice_01(int start, int target) {
    if (start == target) {
        return 1;
    }
    int count = 0;
    for (int i = 1; i <= 6; i++) {
        if (start + i <= target) {
            count += boardPath_dice_01(start + i, target);
        }
    }
    return count;
}

//  board path multi move permutation using dice with dp memorisation
int boardPath_dice_02(int start, int target, vi& dp) {
    if (start == target) {
        dp[start] = 1;
        return 1;
    }
    int count = 0;
    if (dp[start] != 0) {       //  dp condition line
        return dp[start];
    }
    //  or use
    //  for (int i = 1; i <= 6 && start + i <= target; i++)
    for (int i = 1; i <= 6; i++) {
        if (start + i <= target) {
            count += boardPath_dice_02(start + i, target, dp);
        }
    }
    dp[start] = count;      //  dp on off
    return count;
}

//  board path multi move permutation using dice with dp tabulaation
int boardPath_dice_03(int start, int target) {
    vi dp(target + 1);
    for (int i = target; i >= start; i--) {
        if (i == target) {
            dp[i] = 1;
            continue;
        }
        int count = 0;
        for (int j = 1; j <= 6; j++) {
            if (i + j <= target) {
                count += dp[i + j];
            }
        }
        dp[i] = count;
    }
    return dp[start];
}

//  board path multi move permutation using outcome array without dp
int boardPath_arr_01(int start, int target, vi& moves) {
    if (start == target) {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < moves.size(); i++) {
        if (start + moves[i] <= target) {
            count += boardPath_arr_01(start + moves[i], target, moves);
        }
    }
    return count;
}

//  board path multi move permutation using outcome array with dp memorisation
int boardPath_arr_02(int start, int target, vi& moves, vi& dp) {
    if (start == target) {
        dp[start] = 1;
        return 1;
    }
    int count = 0;
    if (dp[start] != 0) {           //  dp condition line
        return dp[start];
    }
    //  or use this only if array is in sorted order
    //  or else the loop will break for greater no. but smaller ones will not get visited
    //  for (int i = 1; i <= 6 && start + i <= target; i++)
    for (int i = 0; i < moves.size(); i++) {
        if (start + moves[i] <= target) {
            count += boardPath_arr_02(start + moves[i], target, moves, dp);
        }
    }
    dp[start] = count;      //  dp on off
    return count;
}

//  board path multi move permutation using outcome array with dp tabulation
int boardPath_arr_03(int start, int target, vi& moves) {
    vi dp(target + 1);
    for (int i = target; i >= start; i--) {
        if (i == target) {
            dp[i] = 1;
            continue;
        }
        int count = 0;
        for (int j = 0; j < moves.size(); j++) {
            if (i + moves[j] <= target) {
                count += dp[i + moves[j]];
            }
        }
        dp[i] = count;
    }
    return dp[start];
}

void solve() {
    int start = 0, target = 10;
    vi dp1(target + 1);
    cout << boardPath_dice_01(start, target) << endl;
    cout << boardPath_dice_02(start, target, dp1) << endl;
    cout << boardPath_dice_03(start, target) << endl;
    display(dp1);
    //  ---------------------------------------------------------
    vi dp2(target + 1);
    vi moves = {2, 5, 3, 7};
    cout << boardPath_arr_01(start, target, moves) << endl;
    cout << boardPath_arr_02(start, target, moves, dp2) << endl;
    cout << boardPath_arr_03(start, target, moves) << endl;
    display(dp2);
}

int main(int args, char**argv) {
    solve();
    return 0;
}