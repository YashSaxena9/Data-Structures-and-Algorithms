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

//  ---------------------------------- longest increasing subsequence ----------------------------------------

//  recursion no dp
int LIS_ans_01 = 1;
int longestIncSubseq_01(int ei, vi& arr) {          //  ei is end Idx
    if (ei == 0) {
        return 1;
    }
    int max_ = 1; 
    for (int i = ei - 1; i >= 0; i--) {
        int recAns = longestIncSubseq_01(i, arr);
        if (arr[i] < arr[ei]) {
            max_ = max(max_, recAns + 1);                   //  this state answer
        }
    }
    LIS_ans_01 = max(LIS_ans_01, max_);       //  global answer for alll states
    return max_;
}

//  dp memorisation
int LIS_ans_02 = 1;
int longestIncSubseq_02(int ei, vi& arr, vi& dp) {
    if (ei == 0) {
        return dp[ei] = 1;
    }
    if (dp[ei] != 0) {
        return dp[ei];
    }
    int max_ = 1; 
    for (int i = ei - 1; i >= 0; i--) {
        int recAns = longestIncSubseq_02(i, arr, dp);
        if (arr[i] < arr[ei]) {
            max_ = max(max_, recAns + 1);                   //  this state answer
        }
    }
    LIS_ans_02 = max(LIS_ans_02, max_);       //  global answer for alll states
    return dp[ei] = max_;
}

//  dp tabulation
vi longestIncSubseq_03(vi& arr) {
    vi dp(arr.size(), 1);
    int max_ = 1;
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);       //  global answer for alll states
            }
        }
        max_ = max(max_, dp[i]);                   //  this state answer
    }
    cout << max_ << endl;
    return dp;
}

//  ----------------------------------- longest decreasing subsequence --------------------------------------

//  recursionno dp
int LDS_ans_01 = 1;
int longestDecSubseq_01(int si, vi& arr) {          //  ei is end Idx
    if (si == arr.size() - 1) {
        return 1;
    }
    int max_ = 1; 
    for (int i = si + 1; i < arr.size(); i++) {
        int recAns = longestDecSubseq_01(i, arr);
        if (arr[i] < arr[si]) {
            max_ = max(max_, recAns + 1);                   //  this state answer
        }
    }
    LDS_ans_01 = max(LDS_ans_01, max_);       //  global answer for alll states
    return max_;
}

//  dp memorisation
int LDS_ans_02 = 1;
int longestDecSubseq_02(int si, vi& arr, vi& dp) {
    if (si == arr.size() - 1) {
        return dp[si] = 1;
    }
    if (dp[si] != 0) {
        return dp[si];
    }
    int max_ = 1; 
    for (int i = si + 1; i < arr.size(); i++) {
        int recAns = longestDecSubseq_02(i, arr, dp);
        if (arr[i] < arr[si]) {
            max_ = max(max_, recAns + 1);                   //  this state answer
        }
    }
    LDS_ans_02 = max(LDS_ans_02, max_);       //  global answer for alll states
    return dp[si] = max_;
}

//  dp tabulation
vi longestDecSubseq_03(vi& arr) {
    vi dp(arr.size(), 1);
    int max_ = 1;
    for (int i = arr.size() - 1; i >= 0; i--) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + 1);       //  global answer for alll states
            }
        }
        max_ = max(max_, dp[i]);                   //  this state answer
    }
    cout << max_ << endl;
    return dp;
}

//  -------------------------------------- longest bitonic subsequence ------------------------------------

//  using tabulation of LIS and LDS, then summing answer for each place and minus one
int longestBitonicSubseq(vi& arr) {
    vi LIS = longestIncSubseq_03(arr);
    vi LDS = longestDecSubseq_03(arr);
    int max_ = 1;
    for (int i = 0; i < arr.size(); i++) {
        max_ = max(max_, LIS[i] + LDS[i] - 1);
    }
    return max_;
}

//  ------------------------------------- maximum sum increasing subsequence -------------------------------------

//  recursion, no dp
int MSIS_ans_01 = (int)-1e6;
int maxSumIncSubseq_01(int ei, vi& arr) {          //  ei is end Idx
    if (ei == 0) {
        return arr[ei];
    }
    int max_ = 1; 
    for (int i = ei - 1; i >= 0; i--) {
        int recAns = maxSumIncSubseq_01(i, arr);
        if (arr[i] < arr[ei]) {
            max_ = max(max_, recAns + arr[ei]);                   //  this state answer
        }
    }
    MSIS_ans_01 = max(MSIS_ans_01, max_);       //  global answer for alll states
    return max_;
}

//  dp memorisation
int MSIS_ans_02 = (int)-1e6;
int maxSumIncSubseq_02(int ei, vi& arr, vi& dp) {
    if (ei == 0) {
        return dp[ei] = arr[ei];
    }
    if (dp[ei] != 0) {
        return dp[ei];
    }
    int max_ = 1; 
    for (int i = ei - 1; i >= 0; i--) {
        int recAns = maxSumIncSubseq_02(i, arr, dp);
        if (arr[i] < arr[ei]) {
            max_ = max(max_, recAns + arr[ei]);                   //  this state answer
        }
    }
    MSIS_ans_02 = max(MSIS_ans_02, max_);       //  global answer for alll states
    return dp[ei] = max_;
}

//  dp tabulation
int maxSumIncSubseq_03(vi& arr) {
    vi dp(arr);
    int max_ = (int)-1e6;
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] < arr[i]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);       //  global answer for alll states
            }
            max_ = max(max_, dp[i]);                   //  this state answer
        }
    }
    display(dp);
    return max_;
}

//  ------------------------------------- minimum deletions to make an array sorted -------------------------------------

//  find the LIS length and subtract that from length of array
int minDelToMakeSorted(vi& arr) {
    //  same code as LIS tabulation with minor change
    vi dp(arr.size(), 1);
    int max_ = 1;
    for (int i = 1; i < arr.size(); i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (arr[j] <= arr[i]) {             //  makeing it <= as sorted array can have same repeating elements consecutively
                dp[i] = max(dp[i], dp[j] + 1);       //  global answer for alll states
            }
        }
        max_ = max(max_, dp[i]);                   //  this state answer
    }
    return arr.size() - max_;
}

//  ==================================== __main__ =======================================

void solve(vi& arr) {
    // longestIncSubseq_01(arr.size() - 1, arr);
    // cout << LIS_ans_01 << endl;

    // vi dp1 (arr.size(), 0);
    // longestIncSubseq_02(arr.size() - 1, arr, dp1);
    // cout << LIS_ans_02 << endl;
    // display(dp1);

    // vi dp_LIS =  longestIncSubseq_03(arr);
    // display(dp_LIS);

    //  ----------------------------------------------------

    // longestDecSubseq_01(0, arr);
    // cout << LDS_ans_01 << endl;

    // vi dp2 (arr.size(), 0);
    // longestDecSubseq_02(0, arr, dp2);
    // cout << LDS_ans_02 << endl;
    // display(dp2);

    // vi dp_LDS = longestDecSubseq_03(arr);
    // display(dp_LDS);

    //  ----------------------------------------------------

    // cout << longestBitonicSubseq(arr) << endl;

    //  ----------------------------------------------------

    // maxSumIncSubseq_01(arr.size() - 1, arr);
    // cout << MSIS_ans_01 << endl;

    // vi dp3 (arr.size(), 0);
    // maxSumIncSubseq_02(arr.size() - 1, arr, dp3);
    // cout << MSIS_ans_02 << endl;
    // display(dp3);

    // cout << maxSumIncSubseq_03(arr) << endl;

    //  ----------------------------------------------------

    // cout << minDelToMakeSorted(arr) << endl;
}

int main(int args, char**argv) {
    vi arr1 = {0, 8, 4, 12, 2, 10, 6, 14, 16, 9, 5, 13, 3, 11, 7, 15, 1};
    vi arr2 = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    vi arr3 = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    solve(arr1);
    // solve(arr2);
    // solve(arr3);
    return 0;
}