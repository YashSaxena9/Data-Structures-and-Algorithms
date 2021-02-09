//  for a random bit
// bit ON ---> ON
// bit OFF ---> OFF

// and if 

// bit OFF ---> OFF
// bit ON ---> OFF

#include<iostream>
using namespace std;

void ONBits(int &n, int k) {
	int mask = (1<<k);
	n |= mask;

	//  n|=(1<<k);			//  one line solution

}

void OFFBits(int &n, int k)
{
	int mask = (~(1 << k));
	n &= mask;

	//  n&=(~(1<<k));			//  one line solution
}

int main(int args, char** argv) {
	int num = 89;
	ONBits(num, 7);
	cout << num << endl;
	OFFBits(num, 3);
	cout<<num<<endl;
	return 0;
}