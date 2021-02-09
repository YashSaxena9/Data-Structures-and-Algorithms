//  find size of maximum square of 1s forming in a board filled with 0s and 1s.

#include <iostream>
#include <vector>
#define vi vector<int>
#define vii vector<vi>
using namespace std;

void display(vii& arr) {
    for (vi v : arr) {
        for (int i : v) {
            cout << i << " ";
        } cout << endl;
    }
}

//  direction array to form square
vii dir = {{1, 1}, {0, 1}, {1, 0}};

//  brute force approch to call every index helper
int maxSquareSize(int r, int c, vii& matrix) {
    int minSize = (int)1e7;
    for (vi d : dir) {
        int x = r + d[0];
        int y = c + d[1];
        if (x < matrix.size() && y < matrix[0].size()) {
            minSize = min(minSize, maxSquareSize(x, y, matrix));
        }
    }
    if (matrix[r][c] == 0) {
        return 0;
    }
    return minSize + 1;
}

//  brute force approch to call every index, calling helper(no dp)
void maxSquareSizeBruteForce(vii& matrix) {
    int maxSquare = 0;
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            maxSquare = max(maxSquare, maxSquareSize(i, j, matrix));
        }
    }
    cout << maxSquare << endl;
}

//  better approch for recursion call, no dp
int staticSqSizeAns_01 = 0;
int maxSquareSize_btr_01(int r, int c, vii& matrix) {
    if (r == matrix.size() ||c == matrix[0].size()) {
        return 0;
    }
    int down = maxSquareSize_btr_01(r + 1, c, matrix);
    int right = maxSquareSize_btr_01(r, c + 1, matrix);
    int diag = maxSquareSize_btr_01(r + 1, c + 1, matrix);
    int minPossibleSquare = 0;
    if (matrix[r][c] == 1) {
        minPossibleSquare = min(down, min(right, diag)) + 1;
    }
    staticSqSizeAns_01 = max(staticSqSizeAns_01, minPossibleSquare);
    return minPossibleSquare;
}

//  better approch for recursion call, with dp memorisation
int staticSqSizeAns_02 = 0;
int maxSquareSize_btr_02(int r, int c, vii& matrix, vii& dp) {
    if (r == matrix.size() ||c == matrix[0].size()) {
        return 0;
    }
    if (dp[r][c] != -1) {       //  not 0 as 0 have a significance in matrix
        //  if matrix have size 0 and dp contain 0 as ans then ans from dp would not be taken, so we take -1 as default in dp
        return dp[r][c];
    }
    int down = maxSquareSize_btr_02(r + 1, c, matrix, dp);
    int right = maxSquareSize_btr_02(r, c + 1, matrix, dp);
    int diag = maxSquareSize_btr_02(r + 1, c + 1, matrix, dp);
    int minPossibleSquare = 0;
    if (matrix[r][c] == 1) {
        minPossibleSquare = min(down, min(right, diag)) + 1;
    }
    dp[r][c] = minPossibleSquare;       //  dp on off
    staticSqSizeAns_02 = max(staticSqSizeAns_02, minPossibleSquare);
    return minPossibleSquare;
}

//  better approch for recursion call, with dp tabulation(better syntax)
int maxSquareSize_btr_03(vii& matrix) {
    vii dp (matrix.size(), vi (matrix[0].size(), 0));
    int staticSqSizeAns_03 = 0;
    int r = matrix.size() - 1;
    int c = matrix[0].size() - 1;
    for (int i = r; i >= 0; i--) {
        for (int j = c; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                dp[i][j] = min(dp[i + 1][j + 1], min(dp[i + 1][j], dp[i][j + 1])) + 1;
            }
            staticSqSizeAns_03 = max(staticSqSizeAns_03, dp[i][j]);
        }
    }
    display(dp);
    return staticSqSizeAns_03;
}

/*
//  better approch for recursion call, with dp tabulation
int maxSquareSize_btr_03(vii& matrix) {
    vii dp (matrix.size(), vi (matrix[0].size(), 0));
    int staticSqSizeAns_03 = 0;
    int rsize = matrix.size();
    int csize = matrix[0].size();
    for (int i = rsize - 1; i >= 0; i--) {
        for (int j = csize - 1; j >= 0; j--) {
            int down = (i + 1 < rsize) ? dp[i + 1][j] : 0;
            int right = (j + 1 < csize) ? dp[i][j + 1] : 0;
            int diag = (i + 1 < rsize && j + 1 < csize) ? dp[i + 1][j + 1] : 0;
            int minPossibleSquare = 0;
            if (matrix[i][j] == 1) {
                minPossibleSquare = min(down, min(right, diag)) + 1;
            }
            dp[i][j] = minPossibleSquare;
            staticSqSizeAns_03 = max(staticSqSizeAns_03, dp[i][j]);
        }
    }
    display(dp);
    return staticSqSizeAns_03;
}
*/

void solve(vii& matrix) {
    // maxSquareSizeBruteForce(matrix);
    // //  ---------------------------------------------
    // maxSquareSize_btr_01(0, 0, matrix);
    // cout << staticSqSizeAns_01 << endl;
    // //  ---------------------------------------------
    // vii dp(matrix.size(), vi(matrix[0].size(), -1));
    // maxSquareSize_btr_02(0, 0, matrix, dp);
    // cout << staticSqSizeAns_02 << endl;
    // display(dp);
    // //  ---------------------------------------------
    cout << maxSquareSize_btr_03(matrix) << endl;
}

int main(int args, char**argv) {
    vii matrix = {
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    solve(matrix);
    return 0;
}