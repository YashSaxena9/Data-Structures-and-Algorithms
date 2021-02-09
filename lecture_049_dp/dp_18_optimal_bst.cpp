//  GFG  ->  optimal bst
/*  
    Given a sorted array keys[0.. n-1] of search keys and an array freq[0.. n-1] of frequency counts,
    where freq[i] is the number of searches to keys[i].
    Construct a binary search tree of all keys such that the total cost of all the searches is as small as possible.
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

int sum_01(vector<int>& freq, int i, int j) {
    int ans = 0;
    for (int s = i; s <= j; s++) {
        ans += freq[s];
    }
    return ans;
}

//  find minimum cost which we will get in case of optimat bst, using recursion, no dp
int optimal_BST_01(int si, int ei, vector<int>& freq) {
    if (si == ei) {
        return freq[si];
    }
    int presSum = sum_01(freq, si, ei);
    int min_ = (int)1e7;        //  O(n^3)
    for (int cut = si; cut <= ei; cut++) {
        int left = (cut == 0) ? 0 : optimal_BST_01(si, cut - 1, freq);
        int right = (cut == freq.size() - 1) ? 0 : optimal_BST_01(cut + 1, ei, freq);
        min_ = min(min_, left + right);
    }
    return min_ + presSum;
}

//  find minimum cost which we will get in case of optimat bst, using array of present sum, using recursion, with dp memorisation
int optimal_BST_02(int si, int ei, vector<int>& freq, vector<int>& psum, vector<vector<int>>& dp) {
    /* if (si == ei) {      //  not needed
        return freq[si];
    } */
    if (si > ei) return 0;
    if (dp[si][ei] != 0) {
        return dp[si][ei];
    }
    int min_ = (int)1e7;
    for (int cut = si; cut <= ei; cut++) {
        int left = (cut == 0) ? 0 : optimal_BST_02(si, cut - 1, freq, psum, dp);
        int right = (cut == freq.size() - 1) ? 0 : optimal_BST_02(cut + 1, ei, freq, psum, dp);
        int myCost = left + (psum[ei] - (((si - 1) >= 0) ? psum[si - 1] : 0)) + right;        //  O(n^3)
        min_ = min(min_, myCost);
    }
    return dp[si][ei] = min_;
}

//  find minimum cost which we will get in case of optimat bst, using array of present sum, not using recursion, with dp tabulation
int optimal_BST_03(vector<int>& freq, vector<int>& psum) {
    vector<vector<int>> dp(freq.size(), vector<int>(freq.size(), 0));
    for (int gap = 0; gap < freq.size(); gap++) {
        for (int si = 0, ei = gap; ei < freq.size(); si++, ei++) {
            int min_ = (int)1e7;
            for (int cut = si; cut <= ei; cut++) {
                int left = (cut == 0) ? 0 : dp[si][cut - 1];
                int right = (cut == freq.size() - 1) ? 0 : dp[cut + 1][ei];
                int myCost = left + (psum[ei] - (((si - 1) >= 0) ? psum[si - 1] : 0)) + right;        //  O(n^3)
                min_ = min(min_, myCost);
            }
            dp[si][ei] = min_;
        }
    }
    display(dp);
    return dp[0][freq.size() - 1];
}

void solve(vector<int>& keys, vector<int>& freq) {
    // cout << optimal_BST_01(0, keys.size() - 1, freq) << endl;

    vector<vector<int>> dp(freq.size(), vector<int>(freq.size(), 0));
    vector<int> psum(freq.size(), freq[0]);
    for (int i = 1; i < freq.size(); i++) {
        psum[i] = psum[i - 1] + freq[i];
    }
    cout << optimal_BST_02(0, keys.size() - 1, freq, psum, dp) << endl;
    display(dp);
    
    cout << optimal_BST_03(freq, psum) << endl;
}

int main(int args, char**argv) {
    vector<int> keys = {10, 12, 20};
    vector<int> freq = {34, 8, 50};
    solve(keys, freq);
    return 0;
}