//  print array with recursion
//  maximum, minimum, find

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int max_(vector <int> &arr, int idx) {
	if (idx == arr.size()) {
		return INT_MIN;
	}
	int prev_ = max_(arr, idx + 1);
	// if (arr[idx] > prev_) {
	// 	return arr[idx];
	// }
	// return prev_;
	return max(arr[idx], prev_);
}

int min_(vector <int> &arr, int idx) {
	if (idx == arr.size()) {
		return INT_MAX;
	}
	int prev_ = min_(arr, idx + 1);
	// if (arr[idx] < prev_) {
	// 	return arr[idx];
	// }
	// return prev_;
	return min(arr[idx], prev_);
}

bool find_(vector <int> &arr, int toFind, int idx) {
	if (idx == arr.size()) {
		return false;
	}
	if (arr[idx] == toFind) {
		return true;
	}
	return find_(arr, toFind, idx + 1);
}

int lastIdx(vector<int> &arr, int idx, int data) {
	if (arr.size() == idx) {
		return -1;
	}
	int recAns = lastIdx(arr, idx + 1, data);
	if (recAns != -1) {
		return recAns;
	}
	else {
		return (arr[idx] == data ? idx : -1);
	}
	// return  -1;
} 

vector<int> allIdx(vector<int> &arr, int idx, int data, int count) {
	if (idx == arr.size()) {
		vector<int> baseArr(count);
		return baseArr;
	}
	if (arr[idx] == data) {
		count++;
	}
	vector<int> recAns = allIdx(arr, idx + 1, data, count);
	if (arr[idx] == data) {
		recAns[count - 1] = idx;
	}
	return recAns;
}

// private:
void display_(vector <int> &arr, int idx) {
	if (idx == arr.size()) {
		return;
	}
	cout<<arr[idx]<<" ";
	display_(arr, idx+1);
}

// public:
// void display(vector <int> &arr) {
// 	display_(arr, 0);
// }

int main(int args, char**argv) {
	vector <int> arr = {10,20,30,40,50,10};
	display_(arr, 0);
	cout<<endl;
	cout<<boolalpha<<find_(arr, 30, 0)<<endl;
	cout<<max_(arr, 0)<<endl;
	return 0;
}