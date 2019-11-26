//  print in wave like iteration
// matrix =  1  2  3  4
// 	    	 5  6  7  8
//  		 9 10 11 12
//  		13 14 15 16

// output =  1 2 3 4 8 7 6 5 9 10 11 12 16 15 14 13

#include <iostream>
#include <vector>
using namespace std;

void input(vector <vector <int>> &arr) {
	for (int row = 0; row < arr.size(); row++) {
		for (int col = 0; col < arr[0].size(); col++) {
			cin>>arr[row][col];
		}
	}
}

void display(vector <vector <int>> &arr) {
	for (vector <int> i : arr) {
		for (int j : i) {
			cout<<j<<" ";
		}
		cout<<endl;
	}
}

void display_H_wave(vector <vector <int>> &arr) {
	for (int row = 1; row <= arr.size(); row++) {
		if (row % 2 == 1) {
			for (int col = 1; col <= arr[0].size(); col++) {
				cout<<arr[row - 1][col - 1]<<" ";
			}
		}
		else if (row % 2 == 0) {
			for (int col = arr[0].size(); col >= 1; col--) {
				cout<<arr[row - 1][col - 1]<<" ";
			}
		}
	}
}

void display_V_wave(vector <vector <int>> &arr) {
	for (int col = 1; col <= arr[0].size(); col++) {
		if (col % 2 == 1) {
			for (int row = 1; row <= arr.size(); row++) {
				cout<<arr[row - 1][col - 1]<<" ";
			}
		}
		else if (col % 2 == 0) {
			for (int row = arr.size(); row >= 1; row--) {
				cout<<arr[row - 1][col - 1]<<" ";
			}
		}
	}
}

int main(int args, char**argv) {
	int row = 0, col = 0;
	cin>>row>>col;
	vector <vector <int>> arr(row, vector <int> (col, 0));
	input(arr);
	cout<<endl;
	display_V_wave(arr);
	
}