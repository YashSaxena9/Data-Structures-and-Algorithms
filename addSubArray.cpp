#include<iostream>
#include<vector>

using namespace std;

void display(vector <int> &arr) {
	for (int i : arr) {
		cout<<i<<" ";
	}
}

void arrSum(vector <int> arr1, vector <int> arr2) {
	int carry = 0;
	int itr3 = arr1.size() < arr2.size()? arr2.size(): arr1.size();
	vector <int> sum_(itr3 + 1);
	int itr1 = arr1.size() - 1;
	int itr2 = arr2.size() - 1;
	while (itr1 >= 0 && itr2 >= 0) {
		int ans = arr1[itr1] + arr2[itr2] + carry;
		int rem = ans % 10;
		carry = ans / 10;
		sum_[itr3] = rem;
		itr3--;
		itr2--;
		itr1--;
		while ( itr1 >= 0) {
		int ans = arr1[itr1] + carry;
		int rem = ans % 10;
		carry = ans / 10;
		sum_[itr3] = rem;
		itr3--;
		itr1--;
	}
	while ( itr2 >= 0) {
		int ans = arr2[itr2] + carry;
		int rem = ans % 10;
		carry = ans / 10;
		sum_[itr3] = rem;
		itr3--;
		itr2--;
	}
	sum_[0] = carry;
	display(sum_);
}

int main(int args, char**argv) {
	vector <int> arr1 = { 1, 2, 3, 4};
	vector <int> arr2 = {4, 3};
	arrSum(arr1, arr2);
	return 0;
}