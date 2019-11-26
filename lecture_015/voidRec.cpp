#include <iostream>
#include <vector>
#include <string>
using namespace std;

/* __________ sub Sequence __________ */
/*
void subSequence(string str, string ans) {
	if (str.size() == 0) {
		cout<<ans<<",";
		return;
	}
	char ch = str[0];
	string rest_str = str.substr(1);
	subSequence(rest_str, ans + ch);
	subSequence(rest_str, ans);
}
*/

int subSequence(string str, string ans) {
	if (str.size() == 0) {
		cout<<ans<<"	";
		return 1;
	}
	char ch = str[0];
	string rest_str = str.substr(1);
	int count = 0;
	count += subSequence(rest_str, ans + ch);
	count += subSequence(rest_str, ans);
	return count;
}

/* __________ permutation __________ */
// void 

/* __________ solve __________ */
void solve() {
	int ans = subSequence("abc","");
	cout<<"\n"<<ans<<endl;
}

/* __________ main __________ */
int main(int args, char**argv) {
	solve();	
	return 0;
}