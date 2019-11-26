//  use dutch flag to sort array with only 0,1,2,3

#include<iostream>
#include<vector>
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
	cout<<endl;
}

int countThree(vector <int> &arr) {
	int count = 0;
	for (int i : arr) {
		if (i == 3) {
			count++;
		}
	}
	return count;
}


/*
	void swap(vector <int> arr, num1, num2) {
		int temp = arr[num1];
		arr[num1] = arr[num2];
		arr[num2] = temp;
	}
*/


void sortDutchFlag(vector <int> &arr) {
	int threes = countThree(arr);
	int ptr1 = 0, ptr2 = arr.size() - threes - 1, ptr3 = arr.size() - 1, itr = 0;
	while (itr < ptr2) {
		if (arr[itr] == 0) {
			swap(arr[itr], arr[ptr1]);
			ptr1++;
			itr++;
		}
		else if (arr[itr] == 2) {
			swap(arr[itr], arr[ptr2]);
			ptr2--;
		}
		else if (arr[itr] == 3) {
			swap(arr[itr], arr[ptr3]);
			ptr3--;
		}
		else {
			itr++;
		}
	}

}

int main(int args, char**argv) {
	cout<<"enter size: ";
	int size;
	cin>>size;
	cout<<"enter data in array: ";
	vector <int> arr(size);
	input(arr);
	// swap(arr[0],arr[arr.size() - 1]);
	display(arr);
	sortDutchFlag(arr);
	display(arr);
	return 0;
} 