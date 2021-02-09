//  print tree path
//  node(as pre for previous) > pre > node(In) > post > node(as post)

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int printTreePath(int num) {
	if (num == 1 || num == 0) {
		cout<<"base : "<<num<<endl;
		return num;
	}
	int ans = 0;
	cout<<"pre : "<<num<<endl;
	ans += printTreePath(num - 1);
	cout<<"In : "<<num<<endl;
	ans +=printTreePath(num - 2);
	cout<<"post : "<<num<<endl;
	
	return ans + 3;
}

int main(int args, char**argv) {
	printTreePath(5);
	return 0;
}