#include <iostream>
#include <vector>
#include <list>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vi& arr) {
    for (int i : arr) {
        cout << i << " ";
    } cout << endl;
}

void displayList(list<int>& ll) {
    for (int i : ll) {
        cout << i << " ";
    } cout << endl;
}

//  ways to tile a floor of n x m with 1 x m tiles, no dp
int waysToTile_01(int n, int m) {
    if (n < m) {
        return 1;
    }
    if (n == m) {
        return 2;
    }
    int count = 0;
    count += waysToTile_01(n - 1, m);      //  horizontal
    count += waysToTile_01(n - m, m);      //  one part filled if n multiple of m + some constant(c -> can be zero)
    return count;
}

//  ways to tile a floor of n x m with 1 x m tiles, with dp memorization
int waysToTile_02(int n, int m, vi& dp) {
    if (n < m) {
        dp[n] = 1;
        return 1;
    }
    if (n == m) {
        dp[n] = 2;
        return 2;
    }
    if (dp[n] != 0) {
        return dp[n];
    }
    int count = 0;
    count += waysToTile_02(n - 1, m, dp);      //  horizontal
    count += waysToTile_02(n - m, m, dp);      //  one part filled if n multiple of m + some constant(c -> can be zero)
    dp[n] = count;
    return count;
}

//  ways to tile a floor of n x m with 1 x m tiles, with dp tabulation
//  space O(n), time O(n)
int waysToTile_03(int n, int m) {
    vi dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (i < m) {
            dp[i] = 1;
            continue;
        }
        if (i == m) {
            dp[i] = 2;
            continue;
        }
        /*  //  or to shorten the syntax
        if (i <= m) {
            dp[i] = (i < m) ? 1 : 2;
            continue;
        }
        */
        int count = 0;
        count += dp[i - 1];      //  horizontal
        count += dp[i - m];      //  one part filled if n multiple of m + some constant(c -> can be zero)
        dp[i] = count;
    }
    display(dp);
    return dp[n];
}

//  ways to tile a floor of n x m with 1 x m tiles, with dp tabulation (using linked list)
//  space O(m), time O(n)
//  sliding window solution
int waysToTile_04(int n, int m) {
    if (n <= m) {
        return (n == m) ? 2 : 1;
    }
    list<int> ll;
    for (int i = 1; i <= m; i++) {
        ll.push_back(1);
    }
    for (int i = m; i <= n; i++) {
        int horizontal = ll.back();
        int vertical = ll.front();

        ll.push_back(horizontal + vertical);
        ll.pop_front();
    }
    displayList(ll);
    return ll.back();
}

void solve() {
    int n = 17, m = 6;       //  (7, 4) -> (ans = 5 ways)
    cout << waysToTile_01(n, m) << endl;

    vi dp(n + 1);
    cout << waysToTile_02(n, m, dp) << endl;
    display(dp);

    cout << waysToTile_03(n, m) << endl;
    
    cout << waysToTile_04(n, m) << endl;
}

int main(int args, char**argv) {
    solve();
    return 0;
}