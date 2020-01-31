//  there are 2 non repeating and differnt numbers in an array and other numbers repeat twice in the array, find those non repeating numbers!

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int args, char**argv) {
	vector<int> arr = {7,2,3,4,5,2,4,3,5,7,890,345};
	int temp = 0;
	for (int j = 0; j < arr.size(); j++) {
		temp = (temp ^ arr[j]);
	}
	int set1 = 0, set2 = 0, sigBit = 0;
	for (int i = 0; i < 32; i++) {
		if ((temp & (1 << i)) != 0) {
			sigBit = (temp & (1 << i));
			break;
		}
	}
	for (int ar : arr) {
		if ((ar & sigBit) == 0) {
			set1 ^= ar;
		}
		else {
			set2 ^= ar;
		}
	}
	cout<<set1<<" "<<set2<<endl;
	return 0;
}