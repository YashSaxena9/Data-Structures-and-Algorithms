// dutch flag algorithm

// sort {0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1,0,1,0} to sorted {0...., 1....} form
// sort {0,1,2,0,1,2,1,1,0,0,0,1,0,2,0,0,1,1,1,0,2,2,0,1,1,0,1,0,2,0} to sorted {0...., 1...., 2....} form

#include<iostream>
#include<vector>
using namespace std;

void sortZeroOne(vector<int> &arr)
{
	int ptr = 0, itr = 0;
	while (itr < arr.size())
	{
		if (arr[itr] == 0) {
			swap(arr[ptr], arr[itr]);
			ptr++;
		}
		itr++;
	}
}

void sortZeroOneTwo(vector <int> &arr) {
	int ptr1 = 0, ptr2 = arr.size() - 1, itr = 0;
	while (itr <= ptr2) {
		if (arr[itr] == 0) {
			swap(arr[ptr1], arr[itr]);
			ptr1++;
			itr++;
		}
		else if (arr[itr] == 2) {
			swap(arr[ptr2], arr[itr]);
			ptr2--;
		}
		else {
			itr++;
		}
	}
}

void display(vector <int> &arr) {
	for (int i : arr) {
		cout<<i<<" ";
	}
}

int main(int argc, char**argv)
{
	vector <int> arr1 = {0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1,0,1,0};
	vector <int> arr2 = {0,1,2,0,1,2,1,1,0,0,0,1,0,2,0,0,1,1,1,0,2,2,0,1,1,0,1,0,2,0};
	display(arr1);
	cout<<endl;
	sortZeroOne(arr1);
	display(arr1);
	cout << endl;
	return 0;
}
