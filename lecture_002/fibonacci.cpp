//  fibonacci series

#include<iostream>

using namespace std;
int main(int args, char**argv){
	int n, next = 1, prev = 0, sum = 0;
	cout<<"enter the n no. : ";
	cin>>n;

	if (n >= 1)
	{
		cout<<prev<<" ";
		if (n == 1)
		{
			return 0;
		}
	}

	if (n >= 2)
	{
		cout<<next<<" ";
		if (n == 2)
		{
			return 0;
		}
	}

	for (int i = 3; i <= n; i++)
	{
		sum = prev + next;
		prev = next;
		next = sum;
		cout<<sum<<" ";
	}
	cout<<endl;
	cout<<"Nth digit is : \n"<<sum<<endl;
	return 0;
}