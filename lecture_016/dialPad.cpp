#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector <string> charPad = {"+", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

int dialPad(string strQues, string ans) {
	if (strQues.size() == 0) {
		cout<<ans<<" ";
		return 1;
	}	
	char ch = strQues[0];
	string restOfQues = strQues.substr(1);
	string code = charPad[ch - '0'];
	int count = 0;
	for (int i = 0; i < code.size(); i++) {
		count += dialPad(restOfQues, ans + code[i]);
	}
	return count;
}

int main(int args, char**argv) {
	string numInput;
	cin>>numInput;
	int count = dialPad(numInput, "");
	cout<<count;
	return 0;
}