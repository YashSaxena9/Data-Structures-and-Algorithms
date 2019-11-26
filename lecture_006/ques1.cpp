// in an array , if the frequency of an elements occurence is greater than size/2 (freq. > size/2) then print that number in O(n) time complexity

// array = [2,2,2,3,3,5,2,6,7,2]
// in interview of Wheelsi

// make in 2 functions

#include<iostream>
#include<vector>
using namespace std;

int findPotential(vector <int> &arr) {
	int count = 1, suspect = arr[0];
	for (int i : arr) {
		if (i == suspect) {
			count++;
		}
		else {
			count--;
		}
		if (count == 0) {
			suspect = i;
			count++;
		}
	}
	return suspect;
}

bool checkSolution(vector <int> &arr, int data) {
	int count = 0;
	for (int i : arr) {
		if (i == data) {
			count++;
		}
	}
	if (count > arr.size() / 2) {
		return true;
	}
	return false;
}

int main(int args, char**argv) {
	vector<int> arr = {3, 3, 4, 2, 4, 4, 2, 4, 4, 3, 4, 4, 4, 4, 4};
	int suspect = findPotential(arr);
	if (checkSolution(arr, suspect)) {
		cout<< "answer is :" << suspect<<endl;
	}
	else {
		cout<<"no solution"<<endl;
	}
	return 0;
}