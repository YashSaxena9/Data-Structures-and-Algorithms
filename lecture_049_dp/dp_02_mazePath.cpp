//  Maze path, find ways to reach destination from source in a maze
//  moves allowed H, V and D   -->   (horizontal, vertical and diagonal)

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vii& dp) {
    for (vi& v : dp) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
}

//  without dp
int mazePathHV_01(int r, int c, int lr, int lc) {
    if (r == lr && c == lc) {
        return 1;
    }
    int count = 0;
    if (r + 1 <= lr) {
        count += mazePathHV_01(r + 1, c, lr, lc);
    }
    if (c + 1 <= lc) {
        count += mazePathHV_01(r, c + 1, lr, lc);
    }
    return count;
}

//  dp memorisation
int mazePathHV_02(int sr, int sc, int er, int ec, vii& dp) {
    if (sr == er && sc == ec) {
        return dp[sr][sc] = 1;
    }
    if (dp[sr][sc] != 0) {
        return dp[sr][sc];          //  if dp already saved
    }
    if (er == ec && dp[sc][sr] != 0) {
        return dp[sc][sr];          //  incase mirror exist
    }
    int count = 0;
    //  --------finding and saving dp--------
    if (sr + 1 <= er) {
        count += mazePathHV_02(sr + 1, sc, er, ec, dp);
    }
    if (sc + 1 <= ec) {
        count += mazePathHV_02(sr, sc + 1, er, ec, dp);
    }

    dp[sr][sc] = count;     //  save dp
    if (er == ec) {         //  if square board then using mirror path
        dp[sc][sr] = count;
    }
    //  -------------
    return count;
}

//  dp tabulation
int mazePathHV_03(int sr, int sc, int er, int ec) {     //  mirror case is useless as we only access index
    vii dp(er + 1, vi(ec + 1));
    for (int sr = er; sr >= 0; sr--) {
        for (int sc = ec; sc >= 0; sc--) {
            if (sr == er && sc == ec) {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;
            if (sr + 1 <= er) {
                count += dp[sr + 1][sc];
            }
            if (sc + 1 <= ec) {
                count += dp[sr][sc + 1];
            }

            dp[sr][sc] = count;     //  save dp
        }
    }
    display(dp);
    return dp[0][0];
}

//  without dp
int mazePathHVD_01(int r, int c, int lr, int lc) {
    if (r == lr && c == lc) {
        return 1;
    }
    int count = 0;
    if (r + 1 <= lr) {
        count += mazePathHVD_01(r + 1, c, lr, lc);
    }
    if (c + 1 <= lc) {
        count += mazePathHVD_01(r, c + 1, lr, lc);
    }
    if (r + 1 <= lr && c + 1 <= lc) {
        count += mazePathHVD_01(r + 1, c + 1, lr, lc);
    }
    return count;
}

//  dp memorisation
int mazePathHVD_02(int sr, int sc, int er, int ec, vii& dp) {
    if (sr == er && sc == ec) {
        return dp[sr][sc] = 1;
    }
    if (dp[sr][sc] != 0) {
        return dp[sr][sc];          //  if dp already saved
    }
    if (er == ec && dp[sc][sr] != 0) {
        return dp[sc][sr];          //  incase mirror exist
    }
    int count = 0;
    //  --------finding and saving dp--------
    if (sr + 1 <= er) {
        count += mazePathHVD_02(sr + 1, sc, er, ec, dp);
    }
    if (sc + 1 <= ec) {
        count += mazePathHVD_02(sr, sc + 1, er, ec, dp);
    }
    if (sr + 1 <= er && sc + 1 <= ec) {
        count += mazePathHVD_01(sr + 1, sc + 1, er, ec);
    }

    dp[sr][sc] = count;     //  save dp
    if (er == ec) {         //  if square board then using mirror path
        dp[sc][sr] = count;
    }
    //  -------------
    return count;
}

//  dp tabulation
int mazePathHVD_03(int sr, int sc, int er, int ec) {     //  mirror case is useless as we only access index
    vii dp(er + 1, vi(ec + 1));
    for (int sr = er; sr >= 0; sr--) {
        for (int sc = ec; sc >= 0; sc--) {
            if (sr == er && sc == ec) {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;
            if (sr + 1 <= er) {
                count += dp[sr + 1][sc];
            }
            if (sc + 1 <= ec) {
                count += dp[sr][sc + 1];
            }
            if (sr + 1 <= er && sc + 1 <= ec) {
                count += dp[sr + 1][sc + 1];
            }

            dp[sr][sc] = count;     //  save dp
        }
    }
    // display(dp);
    return dp[0][0];
}

//  without dp
int mazePathHVD_multi_01(int r, int c, int lr, int lc) {
    if (r == lr && c == lc) {
        return 1;
    }
    int count = 0;
    for (int jump = 1; jump + r <= lr; jump ++) {
        count += mazePathHVD_multi_01(r + jump, c, lr, lc);
    }
    for (int jump = 1; jump + c <= lc; jump ++) {
        count += mazePathHVD_multi_01(r, c + jump, lr, lc);
    }
    for (int jump = 1; jump + r <= lr && jump + c <= lc; jump ++) {
        count += mazePathHVD_multi_01(r + jump, c + jump, lr, lc);
    }
    return count;
}

//  dp memorisation
int mazePathHVD_multi_02(int sr, int sc, int er, int ec, vii& dp) {
    if (sr == er && sc == ec) {
        return dp[sr][sc] = 1;
    }
    if (dp[sr][sc] != 0) {
        return dp[sr][sc];          //  if dp already saved
    }
    if (er == ec && dp[sc][sr] != 0) {
        return dp[sc][sr];          //  incase mirror exist
    }
    int count = 0;
    //  --------finding and saving dp--------
    
    for (int jump = 1; jump + sr <= er; jump ++) {
        count += mazePathHVD_multi_02(sr + jump, sc, er, ec, dp);
    }
    for (int jump = 1; jump + sc <= ec; jump ++) {
        count += mazePathHVD_multi_02(sr, sc + jump, er, ec, dp);
    }
    for (int jump = 1; jump + sr <= er && jump + sc <= ec; jump ++) {
        count += mazePathHVD_multi_02(sr + jump, sc + jump, er, ec, dp);
    }

    dp[sr][sc] = count;     //  save dp
    if (er == ec) {         //  if square board then using mirror path
        dp[sc][sr] = count;
    }
    //  -------------
    return count;
}

//  dp tabulation
int mazePathHVD_multi_03(int sr, int sc, int er, int ec) {     //  mirror case is useless as we only access index
    vii dp(er + 1, vi(ec + 1));
    for (int sr = er; sr >= 0; sr--) {
        for (int sc = ec; sc >= 0; sc--) {
            if (sr == er && sc == ec) {
                dp[sr][sc] = 1;
                continue;
            }
            int count = 0;
            for (int jump = 1; jump + sr <= er; jump ++) {
                count += dp[sr + jump][sc];
            }
            for (int jump = 1; jump + sc <= ec; jump ++) {
                count += dp[sr][sc + jump];
            }
            for (int jump = 1; jump + sr <= er && jump + sc <= ec; jump ++) {
                count += dp[sr + jump][sc + jump];
            }

            dp[sr][sc] = count;     //  save dp
        }
    }
    // display(dp);
    return dp[0][0];
}

void solve() {
    int rSize = 3, cSize = 3;
    // vii dp1(rSize, vi(cSize, 0));
    // cout << mazePathHV_01(0, 0, rSize - 1, cSize - 1) << endl;
    // cout << mazePathHV_02(0, 0, rSize - 1, cSize - 1, dp1) << endl;
    cout << mazePathHV_03(0, 0, rSize - 1, cSize - 1) << endl;
    // display(dp1);
    // cout << "end" << endl;
    // vii dp2(rSize, vi(cSize, 0));
    // cout << mazePathHVD_01(0, 0, rSize - 1, cSize - 1) << endl;
    // cout << mazePathHVD_02(0, 0, rSize - 1, cSize - 1, dp2) << endl;
    // cout << mazePathHVD_03(0, 0, rSize - 1, cSize - 1) << endl;
    // display(dp2);
    // cout << "end" << endl;
    // vii dp3(rSize, vi(cSize, 0));
    // cout << mazePathHVD_multi_01(0, 0, rSize - 1, cSize - 1) << endl;
    // cout << mazePathHVD_multi_02(0, 0, rSize - 1, cSize - 1, dp3) << endl;
    // cout << mazePathHVD_multi_03(0, 0, rSize - 1, cSize - 1) << endl;
    // display(dp3);
    // cout << "end" << endl;
}

int main(int args, char**argv) {
    solve();
    return 0;
}