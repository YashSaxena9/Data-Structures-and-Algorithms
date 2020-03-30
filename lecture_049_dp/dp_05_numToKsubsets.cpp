#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vii& dp) {
    for (vi v : dp) {
        for (int ele : v) {
            cout << ele << " ";
        } cout << endl;
    }
}

//  counting number of ways to partition n numbers to k subsets, no dp
int K_subsets_01(int num, int k) {
    if (num < k) {
        return 0;
    }
    if (num == k || k == 1) {
        return 1;
    }
    int count = 0;
    count += K_subsets_01(num - 1, k - 1);      //  number makes new set
    count += k * K_subsets_01(num - 1, k);          //  number joining in sets comming as ans from recursion call(we multiply k as there are k ways of combining)
    return count;
}

//  counting number of ways to partition n numbers to k subsets, with dp memorisation
int K_subsets_02(int num, int k, vii& dp) {
    if (num < k) {
        dp[num][k] = 0;
        return 0;
    }
    if (num == k || k == 1) {
        dp[num][k] = 1;
        return 1;
    }
    if (dp[num][k] != 0) {
        return dp[num][k];
    }
    int count = 0;
    count += K_subsets_02(num - 1, k - 1, dp);      //  number makes new set
    count += k * K_subsets_02(num - 1, k, dp);          //  number joining in sets comming as ans from recursion call(we multiply k as there are k ways of combining)
    dp[num][k] = count;
    return count;
}

//  counting number of ways to partition n numbers to k subsets, with dp tabulation
int K_subsets_03(int num, int k_sets) {
    vii dp(num, vi(k_sets, 0));
    for (int n = 1; n <= num; n++) {
        for (int k = 1; k <= k_sets; k++) {
            if (n < k) {
                dp[n - 1][k - 1] = 0;
                continue;
            }
            if (n == k || k == 1) {
                dp[n - 1][k - 1] = 1;
                continue;
            }
            int count = 0;
            count += dp[n - 2][k - 2];      //  number makes new set
            count += k * dp[n - 2][k - 1];          //  number joining in sets comming as ans from recursion call(we multiply k as there are k ways of combining)
            dp[n - 1][k - 1] = count;
        }
    }
    display(dp);
    return dp[num - 1][k_sets - 1];
}

void solve() {
    int n = 10, k = 6;
    vii dp(n + 1, vi (k + 1));
    // cout << K_subsets_01(n, k) << endl;
    // cout << K_subsets_02(n, k, dp) << endl;
    cout << K_subsets_03(n, k) << endl;
    // display(dp);
}

int main(int args, char**argv) {
    solve();
    return 0;
}