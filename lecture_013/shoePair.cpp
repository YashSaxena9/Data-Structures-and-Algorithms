//  find missing pair in the array

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int missingPair(vector<int> &arr) {
	if (!(arr.size() % 2)) {
		cout<<"all paired"<<endl;
		return -1;
	}

	int si = 0, ei = arr.size() - 1;
	while (si <= ei) {
		int mid = (si + ei)/2;
		if (si == ei) {
			return mid;
		}
		/*
		else if (!(mid % 2)) {
			if (arr[mid] == arr[mid + 1]) {
				si = mid + 1;
			}
			else {
				ei = mid - 1;
			}
		}
		else if (mid % 2) {
			if (arr[mid] == arr[mid - 1]) {
				si = mid + 1;
			}
			else {
				ei = mid - 1;
			}
		}
		*/
		//  short form for above commented code
		else if ((!(mid % 2) && arr[mid] == arr[mid + 1]) || ((mid % 2) && arr[mid] == arr[mid - 1])) {
			si = mid + 1;
		}
		else {
			ei = mid - 1;
		}
	}
	return -1;
}

int main(int args, char**argv) {
	vector<int> arr = {1,1,2,2,3,3,4,4,5,5,7,8,8,10,10,11,11};
	cout<<missingPair(arr)<<endl;
	return 0;
}