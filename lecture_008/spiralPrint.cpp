//  print in wave like iteration
// matrix =  1  2  3  4
// 	    	 5  6  7  8
//  		 9 10 11 12
//  		13 14 15 16

// output =  1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

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

void display_spiral_H(vector <vector <int>> &arr) {
	int minrow = 0, mincol = 0;
	int maxrow = arr.size() - 1, maxcol = arr[0].size() - 1;
	int tot_ele = arr.size() * arr[0].size(), count = 0;
	while (count < tot_ele) {
		for (int col = mincol; col <= maxcol && count < tot_ele; col++) {
			cout<<arr[minrow][col]<<" ";
			count++;
		}
		minrow++;
		for (int row = minrow; row <= maxrow && count < tot_ele; row++) {
			cout<<arr[row][maxcol]<<" ";
			count++;
		}
		maxcol--;
		for (int col = maxcol; col >= mincol && count < tot_ele; col--) {
			cout<<arr[maxrow][col]<<" ";
			count++;
		}
		maxrow--;
		for (int row = maxrow; row >= minrow && count < tot_ele; row--) {
			cout<<arr[row][mincol]<<" ";
			count++;
		}
		mincol++;
	}
	cout<<endl;
}

void display_spiral_V(vector <vector <int>> &arr) {
	int minrow = 0, mincol = 0;
	int maxrow = arr.size() - 1, maxcol = arr[0].size() - 1;
	int tot_ele = arr.size() * arr[0].size(), count = 0;
	while (count < tot_ele) {
		for (int row = minrow; row <= maxrow && count < tot_ele; row++) {
			cout<<arr[row][mincol]<<" ";
			count++;
		}
		mincol++;

		for (int col = mincol; col <= maxcol && count < tot_ele; col++) {
			cout<<arr[maxrow][col]<<" ";
			count++;
		}
		maxrow--;	

		for (int row = maxrow; row >= minrow && count < tot_ele; row--) {
			cout<<arr[row][maxcol]<<" ";
			count++;
		}
		maxcol--;

		for (int col = maxcol; col >= mincol && count < tot_ele; col--) {
			cout<<arr[minrow][col]<<" ";
			count++;
		}
		minrow++;
	}
	cout<<endl;
}

int main(int args, char**argv) {
	int row = 0, col = 0;
	cin>>row>>col;
	vector <vector <int>> arr(row, vector <int> (col, 0));
	input(arr);
	cout<<endl;
	display_spiral_H(arr);
	display_spiral_V(arr);
}