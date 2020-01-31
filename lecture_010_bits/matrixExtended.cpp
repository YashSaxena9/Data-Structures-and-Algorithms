//  iterate matrix diagonally and orint upper triangle
//  transverse the matrix

/**
 * matrixExtended
 */
#include<iostream>
#include<vector>
#include<string>

using namespace std;

void printDiag(vector<vector<char>> &arr) {
	for (int gap = 0; gap < arr[0].size(); gap++) {
		for (int row = 0, col = gap; row < arr.size() && col < arr[0].size(); row++, col++) {
			cout<<arr[row][col]<<" ";
		}
		cout<<endl;
	}
}

void display(vector<vector<char>> &arr) {
	for (vector<char> ar : arr) {
		for (char c : ar) {
			cout<<c<<" ";
		}
		cout<<endl;
	}
}

void transMat(vector<vector<char>> &arr) {
	for (int r = 0; r < arr.size(); r++) {
		for (int c = r; c < arr[0].size(); c++) {
			char temp = arr[r][c];
			arr[r][c] = arr[c][r];
			arr[c][r] = temp;
		}
	}
}

void rotate90_clockwise(vector<vector<char>> &arr) {
	transMat(arr);
	int c1 = 0, c2 = arr[0].size() - 1;
	while (c1 < c2) {
		for (int r = 0; r < arr.size(); r++) {
			char temp = arr[r][c1];
			arr[r][c1] = arr[r][c2];
			arr[r][c2] = temp;
		}
		c1++;
		c2--;
	}
}

int main(int args, char**argv) {
	vector<vector<char>> arr = {
		{'a','b','c','d'},
		{'e','f','g','h'},
		{'i','j','k','l'},
		{'m','n','o','p'}
	};
	printDiag(arr);
	cout<<endl;
	rotate90_clockwise(arr);
	display(arr);
	return 0;
}

