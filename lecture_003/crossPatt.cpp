//  creating the following pattern

// *   *
//  * *
//   *
//  * *
// *   *

#include<iostream>
using namespace std;
int main(int args, char**argv) {
	int rows;
	cout<<"enter the number of rows: ";
	cin>>rows;

	for (int r = 1; r <= rows; r++) {
		for (int c = 1; c <= rows; c++) {
			if ((r == c)||(r + c == rows + 1)) {
				cout<<"*";
			}
			else {
				cout<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}