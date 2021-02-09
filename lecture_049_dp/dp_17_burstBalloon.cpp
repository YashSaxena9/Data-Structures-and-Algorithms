//  leetcode 312  ->  burst balloon
/* 
    If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
    Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
    Find the maximum coins you can collect by bursting the balloons wisely.
    Input: [3,1,5,8]
    Output: 167 
    Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
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

//  index -1 and nums.size() virtually have value "1"
//  burst balloon recursion cut type, no dp
int burstBalloon_01(int si, int ei, vector<int>& nums) {
    int l = (si == 0) ? 1 : nums[si - 1];
    int r = (ei == nums.size() - 1) ? 1 : nums[ei + 1];
    int myAns = 0;
    for (int cut = si; cut <= ei; cut++) {
        int left = (cut == si ) ? 0 : burstBalloon_01(si, cut - 1, nums);
        int right = (cut == ei ) ? 0 : burstBalloon_01(cut + 1, ei, nums);
        myAns = max(myAns, left + l * nums[cut] * r + right);
    }
    return myAns;
}

//  index -1 and nums.size() virtually have value "1"
//  burst balloon recursion cut type, with dp memorisation
int burstBalloon_02(int si, int ei, vector<int>& nums, vector<vector<int>>& dp) {
    if (dp[si][ei] != 0) {
        return dp[si][ei];
    }
    int l = (si == 0) ? 1 : nums[si - 1];
    int r = (ei == nums.size() - 1) ? 1 : nums[ei + 1];
    int myAns = 0;
    for (int cut = si; cut <= ei; cut++) {
        int left = (cut == si ) ? 0 : burstBalloon_02(si, cut - 1, nums, dp);
        int right = (cut == ei ) ? 0 : burstBalloon_02(cut + 1, ei, nums, dp);
        myAns = max(myAns, left + l * nums[cut] * r + right);
    }
    dp[si][ei] = myAns;
    return myAns;
}

//  index -1 and nums.size() virtually have value "1"
//  burst balloon recursion cut type, with tabulation
int burstBalloon_03(vector<int>& nums) {
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    for (int gap = 0; gap < nums.size(); gap++) {
        for (int i = 0, j = gap; j < nums.size(); i++, j++) {
            int l = (i == 0) ? 1 : nums[i - 1];
            int r = (j == nums.size() - 1) ? 1 : nums[j + 1];
            int myAns = 0;
            for (int cut = i; cut <= j; cut++) {
                int left = (cut == i ) ? 0 : dp[i][cut - 1];
                int right = (cut == j ) ? 0 : dp[cut + 1][j];
                myAns = max(myAns, left + l * nums[cut] * r + right);
            }
            dp[i][j] = myAns;
        }
    }
    display(dp);
    return dp[0][nums.size() - 1];
}

void solve(vector<int>& nums) {
    // cout << burstBalloon_01(0, nums.size() - 1, nums) << endl;
    
    vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), 0));
    cout << burstBalloon_02(0, nums.size() - 1, nums, dp) << endl;
    display(dp);

    cout << burstBalloon_03(nums) << endl;
}

int main(int args, char**argv) {
    vector<int> nums = {3, 1, 5, 8};
    solve(nums);
    return 0;
}