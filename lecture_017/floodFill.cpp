//  flood fill for 4 and 8 moves, print all paths
#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* __________ is valid position ____________ */
bool isValidLocation(vector <vector <bool>> &isDone, int x, int y) {
	if (x < 0 || y < 0 || x >= isDone.size() || y >= isDone[0].size() || isDone[x][y]) {
		return false;
	}
	return true;
}

/* __________ floodfill for 4 moves ____________ */
int floodFill4(vector<vector <bool>> &isDone, int sr, int sc, int er, int ec, string ans) {
	if (sr == er && sc == ec) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	isDone[sr][sc] = true;

	if (isValidLocation(isDone, sr + 1, sc)) {
		count += floodFill4(isDone, sr + 1, sc, er, ec, ans + "D");
	}

	if (isValidLocation(isDone, sr, sc + 1)) {
		count += floodFill4(isDone, sr, sc + 1, er, ec, ans + "R");
	}

	if (isValidLocation(isDone, sr - 1, sc)) {
		count += floodFill4(isDone, sr - 1, sc, er, ec, ans + "U");
	}

	if (isValidLocation(isDone, sr, sc - 1)) {
		count += floodFill4(isDone, sr, sc - 1, er, ec, ans + "L");
	}

	isDone[sr][sc] = false;
	return count;
}

/* __________ floodfill for 8 moves ____________ */
int floodFill8(vector<vector <bool>> &isDone, int sr, int sc, int er, int ec, string ans) {
	if (sr == er && sc == ec) {
		cout<<ans<<endl;
		return 0;
	}
	int max_ = 0;
	isDone[sr][sc] = true;

	if (isValidLocation(isDone, sr + 1, sc)) {
		max_ = max(max_, floodFill8(isDone, sr + 1, sc, er, ec, ans + " S"));
	}

	if (isValidLocation(isDone, sr, sc + 1)) {
		max_ = max(max_, floodFill8(isDone, sr, sc + 1, er, ec, ans + " E"));
	}

	if (isValidLocation(isDone, sr - 1, sc)) {
		max_ = max(max_, floodFill8(isDone, sr - 1, sc, er, ec, ans + " N"));
	}

	if (isValidLocation(isDone, sr, sc - 1)) {
		max_ = max(max_, floodFill8(isDone, sr, sc - 1, er, ec, ans + " W"));
	}

	if (isValidLocation(isDone, sr -1, sc - 1)) {
		max_ = max(max_, floodFill8(isDone, sr - 1, sc - 1, er, ec, ans + " NW"));
	}

	if (isValidLocation(isDone, sr -1, sc + 1)) {
		max_ = max(max_, floodFill8(isDone, sr - 1, sc + 1, er, ec, ans + " NE"));
	}

	if (isValidLocation(isDone, sr + 1, sc + 1)) {
		max_ = max(max_, floodFill8(isDone, sr + 1, sc + 1, er, ec, ans + " SE"));
	}

	if (isValidLocation(isDone, sr + 1, sc - 1)) {
		max_ = max(max_, floodFill8(isDone, sr + 1, sc - 1, er, ec, ans + " SW"));
	}

	isDone[sr][sc] = false;
	return max_ + 1;
}

/* __________ floodfill for 8 with count ____________ */
int floodFill8_(vector<vector <bool>> &isDone, int sr, int sc, int er, int ec, string ans) {
	if (sr == er && sc == ec) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	isDone[sr][sc] = true;

	if (isValidLocation(isDone, sr + 1, sc)) {
		count += floodFill8_(isDone, sr + 1, sc, er, ec, ans + " S");
	}

	if (isValidLocation(isDone, sr, sc + 1)) {
		count += floodFill8_(isDone, sr, sc + 1, er, ec, ans + " E");
	}

	if (isValidLocation(isDone, sr - 1, sc)) {
		count += floodFill8_(isDone, sr - 1, sc, er, ec, ans + " N");
	}

	if (isValidLocation(isDone, sr, sc - 1)) {
		count += floodFill8_(isDone, sr, sc - 1, er, ec, ans + " W");
	}

	if (isValidLocation(isDone, sr -1, sc - 1)) {
		count += floodFill8_(isDone, sr - 1, sc - 1, er, ec, ans + " NW");
	}

	if (isValidLocation(isDone, sr -1, sc + 1)) {
		count += floodFill8_(isDone, sr - 1, sc + 1, er, ec, ans + " NE");
	}

	if (isValidLocation(isDone, sr + 1, sc + 1)) {
		count += floodFill8_(isDone, sr + 1, sc + 1, er, ec, ans + " SE");
	}

	if (isValidLocation(isDone, sr + 1, sc - 1)) {
		count += floodFill8_(isDone, sr + 1, sc - 1, er, ec, ans + " SW");
	}

	isDone[sr][sc] = false;
	return count;
}

/* __________ floodfill for 8 moves better ____________ */
int floodFill8_better(vector<vector <bool>> &isDone, int sr, int sc, int er, int ec, string ans) {
	if (sr == er && sc == ec) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	isDone[sr][sc] = true;
	
	string dir_str[8] = {"N ", "E ", "W ", "S ", "NE ", "NW ", "SE ", "SW "};
	int dir[8][2] = {{1, 0},{0, 1},{0, -1},{-1, 0},{-1, 1},{-1,-1},{1, 1},{1, -1}};

	for (int d = 0; d < 8; d++) {
		int x = sr + dir[d][0];
		int y = sc + dir[d][1];
		if (isValidLocation(isDone, x, y)) {
			count += floodFill8_better(isDone, x, y, er, ec, ans + dir_str[d]);
		}
	}

	isDone[sr][sc] = false;
	return count;
}

/* __________ solve ____________ */
void solve() {
	vector<vector<bool>> isDone(3, vector<bool>(4, false));
	cout<<"maximum branch length : "<<floodFill8_better(isDone, 0, 0, 2, 3, "")<<endl;		//  pass by index
}

/* __________ main ____________ */
int main(int args, char**argv) {
	solve();
	return 0;
}