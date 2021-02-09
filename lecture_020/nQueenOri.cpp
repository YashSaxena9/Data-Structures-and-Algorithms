//  n queen original

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isValid(int r, int c, int n, int m) {
	if (r < 0 || c < 0 || r >= n || c >= m) {
		return false;
	}
	return true;
}

bool isQueenSafe(vector<vector<bool>> &boxes, int r, int c) {
	int n = boxes.size();
	int m = boxes[0].size();
	int arr[4][2] = {{0,-1},{-1,-1},{-1,0},{-1,1}};
	for (int i = 0; i < 4; i++) {
		for (int rad = 1; rad < max(n, m); rad++) {
			int row = r + (rad * arr[i][0]);
			int col = c + (rad * arr[i][1]);

			//  important code for valid n queen answers instead of all possible combinations of queen arrangement
			if (isValid(row, col, n, m) && boxes[row][col]) {
				return false;
			}
		}
	}
	return true;
}

/* __________ n queen original __________ */
int n_queenCom_2D(vector<vector<bool>> &boxes, int oneDidx, int queenCount, int totQueen, string ans) {
	if (queenCount == totQueen) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	for (int i = oneDidx; i < (boxes.size() * boxes[0].size()); i++) {
		int r = i / boxes[0].size(), c = i % boxes[0].size();
		if (isQueenSafe(boxes, r, c)) {
			boxes[r][c] = true;
			count += n_queenCom_2D(boxes, i + 1, queenCount + 1, totQueen, ans + "q" + to_string(queenCount + 1) + "b" + to_string(i + 1) + " ");
			boxes[r][c] = false;
		}
	}
	return count;
}

/* __________ solve __________ */
void solve() {
	vector<vector<bool>> arr(4,vector<bool>(4,false));
	cout<<n_queenCom_2D(arr, 0, 0, 4, "")<<endl;		//  4 queens
}

/* __________ main __________ */
int main(int args, char**argv) {
	solve();
	return 0;
}