//  n queen basics in 2d using subsequence method
//  subsequence method = element will either add or won't add

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* __________ n queen 2D using subsequence method (combinations) __________ */
int n_QueenCombSub_2D(vector<vector<bool>> &boxes, int oneD_idx, int queenCount, int totQueens, string ans) {
	if (queenCount > totQueens || oneD_idx == boxes.size() * boxes[0].size()) {
		if (queenCount > totQueens) {
			cout<<ans<<endl;
			return 1;
		}
		return 0;
	}
	int count = 0;
	int r = oneD_idx / boxes[0].size();
	int c = oneD_idx % boxes[0].size();
	if (!boxes[r][c]) {
		boxes[r][c] = true;
		count += n_QueenCombSub_2D(boxes, oneD_idx + 1, queenCount + 1, totQueens, ans + "q" + to_string(queenCount) + "b" + to_string(oneD_idx) + " ");
		boxes[r][c] = false;
	}
	count += n_QueenCombSub_2D(boxes, oneD_idx + 1, queenCount, totQueens, ans);
	return count;
}

/* __________ n queen 2D using subsequence method (permutations) __________ */
int n_QueenPermSub_2D(vector<vector<bool>> &boxes, int oneD_idx, int queenCount, int totQueens, string ans) {
	if (queenCount > totQueens || oneD_idx == boxes.size() * boxes[0].size()) {
		if (queenCount > totQueens) {
			cout<<ans<<endl;
			return 1;
		}
		return 0;
	}
	int count = 0;
	int r = oneD_idx / boxes[0].size();
	int c = oneD_idx % boxes[0].size();
	if (!boxes[r][c]) {
		boxes[r][c] = true;
		count += n_QueenPermSub_2D(boxes, 0, queenCount + 1, totQueens, ans + "q" + to_string(queenCount) + "b" + to_string(oneD_idx) + " ");
		boxes[r][c] = false;
	}
	count += n_QueenPermSub_2D(boxes, oneD_idx + 1, queenCount, totQueens, ans);
	return count;
}

/* __________ solve __________ */
void solve() {
	vector<vector<bool>> arr(4, vector<bool>(4, false));
	// int count = n_QueenPermSub_2D(arr, 0, 1, 3, "");
	int count = n_QueenCombSub_2D(arr, 0, 1, 3, "");
	cout<<count<<endl;
}

int main(int args, char**argv) {
	solve();
	return 0;
}