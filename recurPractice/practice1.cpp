#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> selfSum(vector<int> &arr) {
	vector<int> myAns;
	for (int ar : arr) {
		int rem = ar % 10;
		ar /= 10;
		myAns.push_back(ar + rem);
	}
	return myAns;
}

int pairSum(vector<int> &arr, vector<int> &sumArr) {
	int ptr1 = 0, ptr2 = 0, ans = 0;
	int count = 0, myAns = -1;
	for (int i = 0; i < arr.size(); i++) {
		ans = arr[i];
		for (int j = i + 1; j < arr.size(); j++) {
			if (sumArr[i] == sumArr[j]) {
				ans += arr[j];
				myAns = max(myAns, ans);
				ans -= arr[j];
			}
		} 
	}

	return myAns;
}

int main(int args, char**argv) {
	vector<int> arr = {51, 71, 13};
	vector<int> sumArr = selfSum(arr);
	int ans = pairSum(arr, sumArr);
	cout<<ans<<endl;
	return 0;
}