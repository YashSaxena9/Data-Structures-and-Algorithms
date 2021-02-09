//  finding all prime numbers upto given limit
//  in complexity O( n^2), O( n * n/2) and O( n * sq.root(n))

#include<iostream>
using namespace std;


//  O(n^2) complexity
void isPrime1(int num) {
	int count = 0;
	for (int i = 2; i < num; i++) {
		if (num % i == 0) {
			count++;
			break;
		}
	}
	if (count == 0) {
		cout<<num<<" ";
	}
}


//  O(n * n/2) complexity
void isPrime2(int num) {
	int count = 0;
	for (int i = 2; i <= num/2; i++) {
		if (num % i == 0) {
			count++;
			break;
		}
	}
	if (count == 0) {
		cout<<num<<" ";
	}
}


//  O(n * sq.root(n)) complexity
void isPrime3(int num) {
	int count = 0;
	for (int i = 2; i*i <= num; i++) {
		if (num % i == 0) {
			count++;
			break;
		}
	}
	if (count == 0) {
		cout<<num<<" ";
	}
}

int main(int args, char**argv) {
	cout<<"enter the limit: ";
	int lim;
	cin>>lim;
	for (int i = 1; i <= lim; i++) {
		isPrime3(i);
	}
	cout<<endl;
	return 0;
}