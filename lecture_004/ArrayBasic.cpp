//  first lecture on array and vectors(using as array)
//  array and vector basics

#include<iostream>
#include<vector>
using namespace std;


//  here vector is passed with reference(using &)
void input(vector <int> &arr) {
					// int temp;
					// cin>>temp;
					// arr.push_back(temp);
	int temp;
	for(int i = 0; i < arr.size(); i++) {
		cin>>temp;
		arr[i] = temp;
		// cout<<arr.size();
	}
	cout<<endl;
}

void display(vector<int> &arr) {
	for(int i = 0; i < arr.size(); i++) {
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


bool find(vector<int> &arr, int data) {
	for(int i = 0; i < arr.size(); i++) {
		if (arr[i] == data) {
			return true;
		}
	}
}

int maximum(vector<int> &arr) {
	int temp = arr[0];
	for(int i : arr) {
		if (temp < i) {
			temp = i;
		}
	}
	return temp;
}

int minimum(vector<int> &arr)
{
	int temp = arr[0];
	for (int i : arr)
	{
		if (temp > i)
		{
			temp = i;
		}
	}
	return temp;
}

int main(int args, char**argv)
	{
		// vector <int> arr;
		vector<int> arr(10);
		input(arr);
		cout << "done" << endl;
		display(arr);
		cout << "done" << endl;

		int data;
		cout<<"enter the data to find: ";
		cin>>data;
		cout<<bool(find(arr, data));
		cout<<endl;
		cout<<"maximum value element: "<<maximum(arr);
		cout<<endl;
		cout<<"minimum value element: "<<minimum(arr);
		return 0;
}