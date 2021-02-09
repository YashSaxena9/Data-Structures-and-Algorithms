//  making and learning about multi dimentional arrays ( /matrices)

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

bool find(vector <vector <int>> &arr, int data) {
		for (vector <int> ar : arr) {
			for (int i : ar) {
				if (i == data) {
					return true;
				}
			}
		}
		return false;
	}

int max_(vector <vector <int>> &arr) {
	int temp = arr[0][0];
	for (int row = 0; row < arr.size(); row++) {
		for (int col = 0; col < arr[0].size(); col++) {
			if (temp < arr[row][col]) {
				temp = arr[row][col];
			}
		}
	}
	return temp;
}

int min_(vector <vector <int>> &arr) {
	int temp = arr[0][0];
	for (int row = 0; row < arr.size(); row++) {
		for (int col = 0; col < arr[0].size(); col++) {
			if (temp > arr[row][col]) {
				temp = arr[row][col];
			}
		}
	}
	return temp;
}

int main(int args, char**argv) {
	
	/*
		//  3D vector of size (n * m * p)
		vector <vector <vector <int>>> arr (n, vector <vector <int> > (m, vector <int> (p, 0)));
	*/

	//  2D vector
	int row, col;
	cin>>row>>col;
	vector <vector <int>> arr (row, vector <int>(col, 0));

	input(arr);
	cout<<endl;
	display(arr);
	cout<<endl;
	cout<<max_(arr)<<endl;

	int data;
	cout<<"enter data to find: ";
	cin>>data;
	cout<<boolalpha<<find(arr, data)<<endl;
	return 0;
}