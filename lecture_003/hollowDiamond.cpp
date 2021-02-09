//  hollow diamond pattern

// *******
// *** ***
// **   **
// *     *
// **   **
// *** ***
// *******

#include<iostream>
using namespace std;
int main(int args, char**argv) {
	cout<<"enter the number of rows to print: ";
	int rows;
	cin>>rows;
	int nst = 1, nsp = rows / 2; 					// only to be seen int the first row
	// number of stars and number of spaces before stars

	for ( int r = 1; r <= rows; r++) { 				//  put r = rows - 2 if we want border at side
		for (int csp = 1; csp <= nsp; csp++) {
			cout<<"*";
		}

		for (int cst = 1; cst <= nst; cst++) {
			cout<<" ";
		}

		for (int csp = 1; csp <= nsp; csp++)
		{
			cout << "*";
		}
		if (r <= rows / 2) { 						//  put rows/2 - 1 if we want a borderr at side
			nsp--;
			nst+=2;
		} else {
			nsp++;
			nst-=2;
		}
		cout<<endl;
	}
	return 0;
}