//  all numbers in an array repeat K times and only one number is present in array which does not repeat and is unique, find that number!

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(int args, char **argv) {
	vector<int> arr = {336,2,3,4,5,2,4,3,5};
	int repeat_ = 2, ans_ = 0;
	vector<int> temp(32,0);
	for(int i = 0; i < 32; i++) {
		for (int ar : arr) {
			temp[i] += ((ar & (1 << i)) >> i); 
		}
		(temp[i] % repeat_) != 0? ans_ |= (1<<i) : ans_ &= (~(1<<i));
		// ans_ ^= ((temp[i] % repeat_) << i);					//  this also works as our ans_ is 0;
	}
	cout<<ans_<<endl;
	return 0;
}