//  revision of recursion

#include <iostream>
using namespace std;

/*  ____________  increasing  ____________  */
void incre_(int num1, int num2) {
	if (num1 == num2) {
		cout<<num1<<endl;
		return;
	}
	cout<<num1<<endl;
	incre_(num1 + 1, num2);
}

int printIncre_(int num) {
	if (!num) {
		return num;
	}
	cout<<printIncre_(num - 1) + 1<<endl;
	return num;
}

/*  ____________  decreasing  ____________  */
void decre_(int num1, int num2) {
	if (num1 == num2) {
		cout<<num1<<endl;
		return;
	}
	decre_(num1 + 1, num2);
	cout<<num1<<endl;
}

int printDecre_(int num, int lim) {
	if (num == lim) {
		cout<<num<<endl;
		return num;
	}
	int recAns = printDecre_(num + 1, lim);
	cout<<recAns - 1<<endl;
	return num;
}
// int printDecre_(int num, int lim) {
// 	if (num == lim) {
// 		return num;
// 	}
// 	int recAns = printDecre_(num + 1, lim);
// 	cout<<recAns<<endl;
// 	return recAns - 1;
// }

/*  ____________  increasing decreasing  ____________  */
void incDec_(int num1, int num2) {
	if (num1 == num2) {
		cout<<num1<<endl;
		return;
	}
	cout<<num1<<endl;
	incDec_(num1 + 1, num2);
	cout<<num1<<endl;
}

/*  ____________  odd even  ____________  */
void oddEven_(int num1, int num2) {
	if (num1 == num2) {
		cout<<num1<<endl;
		return;
	}
	if (num1&1) {					//  odd
		cout<<num1<<endl;
	}
	oddEven_(num1 + 1, num2);
	if (!(num1&1)) {				//  even
		cout<<num1<<endl;
	}
}

/*  ____________  power  ____________  */
int pow_(int num, int exp) {
	if (!exp) {
		return 1;
	}
	int recAns = pow_(num, exp - 1);
	return recAns * num;
}

int powBetter_(int num, int exp) {
	if (!exp) {
		return 1;
	}
	int recAns = powBetter_(num, exp / 2);
	recAns *= recAns;
	if (exp & 1) {				//  incase power is odd 
		recAns *= num;
	}
	return recAns;
}

/*  ____________  factorial  ____________  */
int fact_(int num) {
	if (!num) {
		return 1;
	}
	return num*fact_(num - 1);
}

/*  ____________  solve  ____________  */
/*  ____________  solve  ____________  */
void solve() {
	// incre_(1,5);
	// decre_(1, 5);
	// incDec_(1,5);
	// oddEven_(1,10);
	// printIncre_(5);
	// printDecre_(1, 5);
	// cout<<pow_(2, 10)<<endl;
	// cout<<powBetter_(2, 10)<<endl;
	cout<<fact_(5)<<endl;
}
/*  ____________  solve  ____________  */
/*  ____________  solve  ____________  */



int main(int args, char**argv) {
	solve();
	return 0;
}