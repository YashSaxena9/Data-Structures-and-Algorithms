#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* __________ n queen 2D (combinations) __________ */
int N_QueenComb_2D(int size, int idx, int queenCount, int totQueens, string ans) {
	if (queenCount > totQueens) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	for (int i = idx; i < size; i++) {
		count += N_QueenComb_2D(size, i + 1, queenCount + 1, totQueens, ans + "q" + to_string(queenCount) + "b" + to_string(i));
	}
	return count;
}


/* __________ n queen 2D (permutations) __________ */
//  we use bool array because we access previous blocks before queen and we need to know if queen is set or unset
int N_QueenPerm_2D(vector<vector<bool>> &boxes, int queenCount, int totQueens, string ans) {
	if (queenCount > totQueens) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	for (int i = 0; i < boxes.size() * boxes[0].size(); i++) {
		int r = i / boxes[0].size();
		int c = i % boxes[0].size();
		if (!boxes[r][c]) {
			boxes[r][c] = true;
			count += N_QueenPerm_2D(boxes, queenCount + 1, totQueens, ans + "q" + to_string(queenCount) + "b" + to_string(i));
			boxes[r][c] = false;
		}
		/*
		if ((oneD_idx & (1<<i)) == 0) {
			boxes[i / boxes[0].size()][i % boxes[0].size()] == true;
			oneD_idx = (oneD_idx | (1 << i));
			count += N_QueenPerm_2D(boxes, oneD_idx, queenCount + 1, totQueens, ans + "q" + to_string(queenCount) + "b" + to_string(i) + " ");
			boxes[i / boxes[0].size()][i % boxes[0].size()] == false;
			oneD_idx = (oneD_idx & (~(1 << i)));
		}
		*/
	}
	return count;
}

/* __________ solve __________ */
void solve() {
	vector<vector<bool>> arr(4, vector<bool>(4, false));
	int count = N_QueenComb_2D(arr.size() * arr[0].size(), 0, 1, 3, "");
	cout<<count<<endl;
}

int main(int args, char**argv) {
	solve();
	return 0;
}