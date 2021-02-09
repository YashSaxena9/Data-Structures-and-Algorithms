//  find all sub arrays

#include <iostream>
#include <vector>
using namespace std;

void input(vector <int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		cin>>arr[i];
	}
}

void subarr(vector <int> &arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i; j < arr.size(); j++) {
			for (int k = i; k <= j; k++) {
				cout<< arr[k]<<" ";
			}
			cout<<endl;
		}
	}
}

int main(int args, char**argv) {
	int size;
	cout<<"enter size of array: ";
	cin>>size;
	vector <int> arr(size);
	cout<<"enter the array: ";
	input(arr);
	subarr(arr);
	return 0;
}

/*
	#  Output
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
1 2 3 4 5 6 
1 2 3 4 5 6 7 
1 2 3 4 5 6 7 8 
2 
2 3 
2 3 4 
2 3 4 5 
2 3 4 5 6 
2 3 4 5 6 7 
2 3 4 5 6 7 8 
3 
3 4 
3 4 5 
3 4 5 6 
3 4 5 6 7 
3 4 5 6 7 8 
4 
4 5 
4 5 6 
4 5 6 7 
4 5 6 7 8 
5 
5 6 
5 6 7 
5 6 7 8 
6 
6 7 
6 7 8 
7 
7 8 
8 

*/