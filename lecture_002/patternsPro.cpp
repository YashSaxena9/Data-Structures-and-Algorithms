// triangle, side triangle and diamond

// *	        			*			   *
// **	        		   **			  ***
// ***	        		  ***			 *****
// ****        			 ****			  ***
// *****        		*****			   *

#include<iostream>
using namespace std;
int main(int args, char**argv) {



// /*
// 	//  pattern 1
// 	// 	*	   
// 	//  **	  
// 	//  ***	 
// 	//  **** 
// 	//  *****

// 	cout<<"enter the number of rows: ";
// 	int rows1;
// 	cin>>rows1;
// 	int nst = 1, nsp = 0;		//  only to be seen int the first row
// 	//  number of stars and number of spaces before stars

// 	for(int r = 1; r<=rows1; r++) {
// 								/*  this loop is not required as there are no spaces before stars  */
// 										// for(int csp = 1; csp<=nsp; csp++) {
// 										// 	cout<<" ";
// 										// }

// 		for(int cst = 1; cst<=nst; cst++) {
// 			cout<<"*";
// 		}
// 								/*  this is not required as nsp(number of spaces before stars is already 0)  */
// 										// nsp--;	
// 		nst++;
// 		cout<<endl;
// 	}
// */





// /*
// 	//  pattern 2
// 	//      *
// 	//     **
// 	//    ***
// 	//   ****
// 	//  *****

// 	cout<<"enter the number of rows: ";
// 	int rows2;
// 	cin >> rows2;
// 	int nst = 1, nsp = rows2 - 1; //  only to be seen int the first row
// 	//  number of stars and number of spaces before stars

// 	for (int r = 1; r <= rows2; r++)
// 	{
// 		for(int csp = 1; csp <= nsp; csp++) {
// 			cout<<" ";
// 		}

// 		for (int cst = 1; cst <= nst; cst++)
// 		{
// 			cout << "*";
// 		}

// 		nsp--;
// 		nst++;
// 		cout << endl;
// 	}
// */





// /*
// 	//  pattern 3
// 	//   *  
// 	//  ***
// 	// *****
// 	//  ***
// 	//   *

// 	cout<<"enter the number of rows: ";
// 	int rows3;
// 	cin>>rows3;
// 	int nst = 1, nsp = (rows3 / 2);		//  only to be seen int the first row
// 	//  number of stars and number of spaces before stars

// 	for(int r = 1; r<=rows3; r++) {
// 		for(int csp = 1; csp<=nsp; csp++) {
// 			cout<<" ";
// 		}

// 		for(int cst = 1; cst<=nst; cst++) {
// 			cout<<"*";
// 		}
// 		if (r <= rows3 / 2) {
// 			nsp--;
// 			nst += 2;
// 		}else {
// 			nsp++;
// 			nst -= 2;
// 		}

// 		cout<<endl;
// 	}
// */


	return 0;
}