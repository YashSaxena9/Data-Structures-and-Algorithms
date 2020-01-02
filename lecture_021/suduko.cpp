//  sudoku problem
#include<iostream>
#include<vector>
#include<string>
#define vii vector<vector<int>>
#define vi vector<int>
using namespace std;

/* __________ display __________ */
void display(vii &arr) {
	for (vi ar : arr) {
		for (int i : ar) {
			cout<<i<<" ";
		} 
		cout<<endl;
	}
	cout<<endl;
}

/* __________ is valid place or not __________ */
bool isValid(vii &arr, int row, int col, int num) {
	//  for row
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i][col] == num) {
			return false;
		}
	}

	//  for column
	for (int j = 0; j < arr[0].size(); j++) {
		if (arr[row][j] == num) {
			return false;
		}
	}

	//  for 3:3 matrix
	int nr = (row / 3) * 3;
	int nc = (col / 3) * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j <3; j++) {
			if (arr[nr + i][nc + j] == num) {
				return false;
			}
		}
	}
	return true;
}

/* __________ sudoku Solver __________ */
int sudokuSol(vii &box, int vidx) {
	if (vidx == 81) {
		display(box);
		return 1;
	}
	int count = 0;
	int r = vidx / box[0].size(), c = vidx % box[0].size();
	if (box[r][c] == 0) {
		for (int i = 1; i <= 9; i++) {
			if (isValid(box, r, c, i)) {
				box[r][c] = i;
				count += sudokuSol(box, vidx + 1);
				box[r][c] = 0;
			}
		}
	}
	else {
		count += sudokuSol(box, vidx + 1);
	}
	return count;
}

/* __________ solve __________ */
void solve() {
	vii arr = {
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,1,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0}
	};
	// vii arr(9,vi(9,0));
	cout<<sudokuSol(arr, 0)<<endl;
}

/* __________ main __________ */
int main(int args, char**argv) {
	solve();
	return 0;
}