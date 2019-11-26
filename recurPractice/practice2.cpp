#include<iostream>
#include<vector>
#include<string>
using namespace std;

unsigned int pow_(unsigned int num, unsigned int po) {
	if (po == 0)		return 1;
	unsigned int ans = pow_(num, po / 2);
	ans *= ans;
	if (po % 2 == 1) {
		ans *= num;
	}
	return ans;
}

unsigned int find_S(unsigned int n, unsigned int k) {
	int mod_ = 10000007;
	if (n == 1) {
		return 1;
	}
	unsigned int ans = (pow_(n, k) % mod_) + find_S(n - 1, k);
	return ans;
}


unsigned int find_P(unsigned int n) {
	int mod_ = 10000007;
	if (n == 1) {
		return 1;
	}
	unsigned int ans = (pow_(n, n) % mod_) + find_P(n - 1);
	return ans;
}

unsigned int find_Z(int n, int k) {
	unsigned int sn = find_S(n, k);
	unsigned int pn = find_P(n);
	return sn + pn;
}

int main(int args, char**argv) {
	int tc;
	cin>>tc;
	for (int i = 1; i < tc; i++) {
		unsigned int n, k;
		cin>>n>>k;
		long long int ans = find_Z(n, k) + find_Z(n - 1, k) - 2 * find_Z(n - 2, k);
		cout<<ans<<endl;
	}
	return 0;
}