#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<string> words = {".,:;", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wux", "yz", "@$&", "-_;"};

int keyPad_(string ques, string ans) {
    if (ques.length() == 0) {
        cout<<ans<<" ";
        return 1;
    }
    int ch = ques[0] - '0';
    int count = 0;
    string code_ = words[ch];
    for (int i = 0 ; i < code_.length(); i++) {
        count += keyPad_(ques.substr(1), ans + code_[i]);
    }
        //  for double digit number
    if (ques.length() >= 2) {
        ch = ch * 10 + (int)(ques[1] - '0');
        if (ch >= 10 && ch <= 11) {
            code_ = words[ch];
            for (int i = 0 ; i < code_.length(); i++) {
                count += keyPad_(ques.substr(2), ans + code_[i]);
            }
        }
    }
    return count;
}

int main(int args, char**argv) {
    cout<<keyPad_("1011", "")<<endl;
    return 0;
}
