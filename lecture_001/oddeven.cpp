#include<iostream>
//verified
using namespace std;
int main(int argc, char**argv){
	int a;
	cout<<"enter no. : ";
	cin>>a;
	if(a % 2){
		cout<<a<<" is odd";
	}
	else{
		cout<<a<<" is even";
	}
	return 0;
}