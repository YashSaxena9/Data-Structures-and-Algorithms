//  print the given pattern

//    1
//   212
//  32123
// 4321234
//  32123
//   212
//    1

#include<iostream>
using namespace std;
int main(int args, char**argv) {
	cout<<"enter the number of rows: ";
	int rows;
	cin>>rows;
	int nst = 1, nsp = (rows / 2);		//  only to be seen int the first row
	//  number of stars and number of spaces before stars

	for(int r = 1; r<=rows; r++) {
		for(int csp = 1; csp<=nsp; csp++) {
			cout<<" ";
		}
		int val;
		if (r <= rows/2) {
			val = r;
		}
		else{
			val = rows - r +1;
		}
		for(int cst = 1; cst<=nst; cst++) {
			cout<<val;
			if(cst <= nst/2){
				val--;
			}else{
				val++;
			}
		}
		if (r <= rows / 2) {
			nsp--;
			nst += 2;
		}else {
			nsp++;
			nst -= 2;
		}

		cout<<endl;
	}
	return 0;
}