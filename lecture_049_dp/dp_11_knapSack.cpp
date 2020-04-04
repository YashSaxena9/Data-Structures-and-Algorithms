/*  
 Knap sack problem, there are n items of given weight, every item have a values
 a theif have a sack of given capacity
 find what is the maximum profit a theif can generate if he can take any object(s) of weight less than or equal to capacity of sack
 sack should not overflow
 it is not compulsory to file the sack completely
*/

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vii& arr) {
    for (vi& v : arr) {
        for (int i : v) {
            cout << i << " ";
        } cout << endl;
    }
}

void display(vi& arr) {
    for (int i : arr) {
        cout << i << " ";
    } cout << endl;
}

//  knap sack, no repition of same item, no dp (subsequence like calls, for loop doesn't support dp)
//  we iterate array of weight from front her
int knapSack_Bounded_01(int idx, int cap, vi& weight, vi& values) {
    if (idx == weight.size() || cap == 0) {
        return 0;
    }
    int picked = 0, unpicked = 0;
    if (cap - weight[idx] >= 0) {
        picked = knapSack_Bounded_01(idx + 1, cap - weight[idx], weight, values) + values[idx];
    }
    unpicked = knapSack_Bounded_01(idx + 1, cap, weight, values);
    return max(picked, unpicked);
}

//  knap sack, with repition of same item, no dp  (subsequence like calls, for loop supports dp in this)
//  we iterate array of weight from front her
int knapSack_Unbounded_01(int idx, int cap, vi& weight, vi& values) {
    if (idx == weight.size() || cap == 0) {
        return 0;
    }
    int picked = 0, unpicked = 0;
    if (cap - weight[idx] >= 0) {
        picked = knapSack_Unbounded_01(idx, cap - weight[idx], weight, values) + values[idx];
        // picked_next = knapSack_Unbounded_01(idx + 1, cap - weight[idx], weight, values) + values[idx];
        // picked_self = knapSack_Unbounded_01(idx, cap - weight[idx], weight, values) + values[idx];
    }
    unpicked = knapSack_Unbounded_01(idx + 1, cap, weight, values);
    return max(picked, unpicked);
}

//  knap sack, no repition of same item, with dp memorisaton (subsequence like calls, for loop doesn't support dp)
//  works like coin change combination single use for single item
//  to get desired filling of dp, we iterate array of weight from back
int knapSack_Bounded_02(int idx, int cap, vi& weight, vi& values, vii& dp) {
    if (idx < 0 || cap == 0) {
        return 0;
    }
    if (dp[idx][cap] != 0) {
        return dp[idx][cap];
    }
    int picked = 0, unpicked = 0;
    if (cap - weight[idx - 1] >= 0) {
        picked = knapSack_Bounded_02(idx - 1, cap - weight[idx - 1], weight, values, dp) + values[idx - 1];
    }
    unpicked = knapSack_Bounded_02(idx - 1, cap, weight, values, dp);
    return dp[idx][cap] = max(picked, unpicked);
}

//  knap sack, with repition of same item, with dp memorisation (for loop supports 1D dp in this)
//  works like coin change combination multiple use for single item
//  to get desired filling of dp, we iterate array of weight from back
int knapSack_Unbounded_02(int idx, int cap, vi& weight, vi& values, vi& dp) {
    if (idx < 0 || cap == 0) {
        return 0;
    }
    if (dp[cap] != 0) {
        return dp[cap];
    }
    int count = 0;
    for (int i = idx; i >= 0; i--) {
        if (cap - weight[i - 1] >= 0) {
            count = max(count, knapSack_Unbounded_02(i, cap - weight[i - 1], weight, values, dp) + values[i - 1]);
        }
    }
    return dp[cap] = count;
}

//  knap sack, no repition of same item, with dp tabulation (subsequence like calls, for loop doesn't support dp)
//  works like coin change combination single use for single item
//  to get desired filling of dp, we iterate array of weight from back
int knapSack_Bounded_03(int capacity, vi& weight, vi& values) {
    vii dp(weight.size() + 1, vi(capacity + 1, 0));
    for (int idx = 1; idx <= weight.size(); idx++) {
        for (int cap = 0; cap <= capacity; cap++) {
            int picked = 0, unpicked = 0;
            if (cap - weight[idx - 1] >= 0) {
                picked = dp[idx - 1][cap - weight[idx - 1]] + values[idx - 1];
            }
            unpicked = dp[idx - 1][cap];
            dp[idx][cap] = max(picked, unpicked);
        }
    }
    display(dp);
    return dp[weight.size()][capacity];
}

//  knap sack, with repition of same item, with dp tabulation (for loop supports 1D dp in this)
//  works like coin change combination multiple use for single item
//  to get desired filling of dp, we iterate array of weight from back
int knapSack_Unbounded_03(int capacity, vi& weight, vi& values) {
    vi dp(capacity + 1, 0);
    for (int idx = 0; idx < weight.size(); idx++) {
        for (int cap = 0; cap <= capacity; cap++) {
            if (cap - weight[idx] >= 0) {
                dp[cap] = max(dp[cap], dp[cap - weight[idx]] + values[idx]);
            }
        }
    }
    display(dp);
    return dp[capacity];
}

void solve(int cap, vi& weight, vi& values) {
    // cout << knapSack_Bounded_01(0, cap, weight, values) << endl;

    // vii dp1(weight.size() + 1, vi(cap + 1, 0));
    // cout << knapSack_Bounded_02(weight.size(), cap, weight, values, dp1) << endl;
    // display(dp1);

    // cout << knapSack_Bounded_03(cap, weight, values) << endl;

    //  -------------------------------------------------------------------------
    
    // cout << knapSack_Unbounded_01(0, cap, weight, values) << endl;

    // vi dp2(cap + 1, 0);
    // cout << knapSack_Unbounded_02(weight.size(), cap, weight, values, dp2) << endl;
    // display(dp2);
    
    // cout << knapSack_Unbounded_03(cap, weight, values) << endl;
}

int main(int args, char**argv) {
    vi weight1 = {2, 5, 1, 3, 4};
    vi values1 = {15, 14, 10, 45, 30};
    int cap1 = 7;

    vi weight2 = {10, 20, 30};
    vi values2 = {60, 100, 120};
    int cap2 = 50;
    solve(cap2, weight2, values2);
    return 0;
}