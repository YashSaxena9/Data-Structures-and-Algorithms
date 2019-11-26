//  binary search, upper bound binary search, lower boind binary search, returning the closest element if number not found

#include <iostream>
// #include <climits>		//  library to 
#include <vector>
using namespace std;

void input(vector <int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cin>>arr[i];
	}
}

void display(vector <int> &arr) {
	for (int i : arr) {
		cout<<i<<" ";
	}
}

int bin_search(vector <int> &arr, int data) {
	
	int si = 0, ei = arr.size();
	while (si <= ei) {
		int mid = (si + ei)/2;
		if (arr[mid] == data) {
			return mid;
		}
		else if (arr[mid] < data) {
			si = mid + 1;
		}
		else if (arr[mid] > data) {
			ei = mid - 1;
		}
	}

	if (ei == -1) {
		return si;
	}

	else if (si == arr.size()) {
		return ei;
	}

	//  nearest is the digit whose difference with data is smallest
	else if (data - arr[ei] <= arr[si] - data) {
		return ei;		//  if arr[ei] is nearest
	}

	return si;			//  if arr[si] is nearest
}

int l_bin_search(vector<int> &arr, int data) {

	int si = 0, ei = arr.size();
	while (si <= ei)
	{
		int mid = (si + ei) / 2;
		if (arr[mid] == data) {
			if (mid - 1 > -1 && arr[mid - 1] == arr[mid]) {
				ei = mid - 1;
			}
			else {
				return mid;
			}
		}
		else if (arr[mid] < data) {
			si = mid + 1;
		}
		else if (arr[mid] > data) {
			ei = mid - 1;
		}
	}

	if (ei == -1) {
		return si;
	}

	else if (si == arr.size()) {
		return ei;
	}

	//  nearest is the digit whose difference with data is smallest
	else if (data - arr[ei] <= arr[si] - data) {
		return ei; //  if arr[ei] is nearest
	}

	return si; //  if arr[si] is nearest
}

int u_bin_search(vector<int> &arr, int data) {

	int si = 0, ei = arr.size();
	while (si <= ei)
	{
		int mid = (si + ei) / 2;
		if (arr[mid] == data) {
			if (mid + 1 < arr.size() && arr[mid + 1] == arr[mid]) {
				si = mid + 1;
			}
			else {
				return mid;
			}
		}
		else if (arr[mid] < data) {
			si = mid + 1;
		}
		else if (arr[mid] > data) {
			ei = mid - 1;
		}
	}

	if (ei == -1) {
		return si;
	}

	else if (si == arr.size()) {
		return ei;
	}

	//  nearest is the digit whose difference with data is smallest
	else if (data - arr[ei] <= arr[si] - data) {
		return ei; //  if arr[ei] is nearest
	}

	return si; //  if arr[si] is nearest
}

int main(int args, char**argv) {
	
	cout<<"enter size of array: ";
	int size;
	cout<<"size : ";
	cin>>size;
	vector <int> arr(size, 0);
	cout<<"enter the array: ";
	input(arr);
	int data;
	cout<<"data: ";
	cin>>data;
	cout<<bin_search(arr, data)<<endl;
	cout << u_bin_search(arr, data) << endl;
	cout << l_bin_search(arr, data) << endl;
	return 0;
}
