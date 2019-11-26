//  find a^b using recursion
#include <iostream>
using namespace std;

//  complexity  O(N)
int power_(int num, int po) {
	if (po == 0)			return 1;
	return power_(num, po - 1) * num;
}

//  complexity  O(log N)
int powBtr_(int num, int po) {
	if (po == 0)		return 1;
	int ans = powBtr_(num, po / 2);
	ans *= ans;
	if (po % 2 == 1) {
		ans *= num;
	}
	return ans;
}

int fibRec(int num) {
	if (num <= 1) {
		return num;
	}
	return fibRec(num - 1) + fibRec(num - 2);

	//  return num<=1; 
}


int main(int args, char**argv) {
	int num, po = 0;
	cin>>num>>po;
	cout<<power_(num, po)<<endl;
	cout<<powBtr_(num, po)<<endl;
	return 0;
}