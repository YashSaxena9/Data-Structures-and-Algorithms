#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subSeq_comb(string ques, string ans) {
    if (ques.length() == 0) {
        cout<<ans<<" ";
        return;
    }
    char ch = ques[0];
    string restStr = ques.substr(1);
    subSeq_comb(restStr, ans);
    subSeq_comb(restStr, ans + ch);
}

// with duplicacy
void subSeq_perm01(string ques, string ans) {
    if (ques.length() == 0) {
        cout<<ans<<" ";
        return;
    }
    char ch = ques[0];
    string restStr = ques.substr(1);
    for (int i = 0; i <= ans.length(); i++) {
        string left = ans.substr(0, i);
        string right = ans.substr(i);
        subSeq_perm01(restStr, left + ch + right);
    }
    // subSeq_perm01(restStr, ans);
}

// without duplicacy in ques (not good)
void subSeq_perm02(string ques, string ans, int flag) {
    if (ques.length() == 0) {
        cout<<ans<<" ";
        return;
    }
    char ch = ques[0];
    int pos = (ch - 'a');
    string restStr = ques.substr(1);
    for (int i = 0; i <= ans.length(); i++) {    
        if (!(1 & (flag<<pos))) {
            string left = ans.substr(0, i);
            string right = ans.substr(i);
            
            flag |= (1<<pos);
            subSeq_perm02(restStr, left + ch + right, flag);
            flag &= ~(1<<pos);
        }
        else {
            subSeq_perm02(restStr, ans, flag);
            break;
        }
    }
    // subSeq_perm02(restStr, ans);
}

int subSeq_perm03(string str, string ans) {
    if (str.length() == 0) {
        cout<<ans<<" ";
        return 1;
    }
    int count = 0;
    // vector<bool> vis(26, false);
    int vis = 0;

    for (int i = 0; i < str.length(); i++) {
        if (!(1 & (vis<<(str[i] - 'a')))) {
            // vis[str[i] - 'a'] = true;
            vis |= (1<<(str[i] - 'a'));
            string nstr = str.substr(0, i) + str.substr(i + 1);
            count += subSeq_perm03(nstr, ans + str[i]);
            //  no marking false as the permutation should not repeat;
        }
    }
    return count;
}

int main(int args, char**argv) {
    // subSeq_comb("abc", "");
    // subSeq_perm01("aba", "");
    // subSeq_perm02("aba", "", 0);
    cout<<subSeq_perm03("aba", "")<<endl;
    return 0;
}
