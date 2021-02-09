//  word break problem

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool isWord;

int wordBreak(vector<string> &dict, string statement, string ans) {
	if (statement.length() == 0) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	for (int i = 1; i <= statement.length(); i++) {
		string str = statement.substr(0, i);
		if (isWordPresent(dict, str)) {
			count += wordBreak(dict, ststement.substr(i), ans + str + " ");
		}
	}
	return count;
}

void solve() {

}

int main(int args, char**argv) {
	solve();
	return 0;
}