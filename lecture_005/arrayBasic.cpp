//  creating input method in array
//  using vectors mainly

//  make reverve() function and rotate(arr, k) function{no extra array}

//  reverse()
//  rotate(arr, k)

#include <iostream>
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

int find(vector <int> &arr, int data) {
	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] == data) {
			return i;
		}
	}
	return -1;
}

int max(vector <int> &arr) {
	int max_ = arr[0];
	for(int i : arr) {
		if (i > max_) {
			max_ = i;
		}
	}
	return max_;
}

int min(vector<int> &arr)
{
	int min_ = arr[0];
	for (int i : arr)
	{
		if (i < min_)
		{
			min_ = i;
		}
	}
	return min_;
}


/* swap function already exist in c++ */
		// void swap(vector <int> &arr, int num1, int num2) {
		// 	int temp = arr[num1];
		// 	arr[num1] = arr[num2];
		// 	arr[num2] = temp;
		// }

void reverse(vector <int> &arr, int si, int ei) {
	while (si < ei) {
		swap(arr[si], arr[ei]);
		si++;
		ei--;
	}
}

void rotate(vector <int> &arr, int lim) {
	lim %= arr.size();
	if (lim < 0) {
		lim += arr.size();
	}
	reverse(arr, 0, lim - 1);
	reverse(arr, lim, arr.size() - 1);
	reverse(arr, 0, arr.size() - 1);
}

int main(int args, char**argv) {
	cout<<"enter size of array: ";
	int size;
	cin>>size;
	vector <int> arr(size,0);
	input(arr);
	reverse(arr, 1, 4);
	display(arr);
	cout<<endl;
	rotate(arr, 3);
	display(arr);
	return 0;
}