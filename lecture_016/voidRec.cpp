//  using recursion in void/int type functions 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*  __________ maze path __________  */
int mazePath(int sr, int sc, int er, int ec, string ans) {
	if (sr == er && sc == ec) {
		cout<<ans<<endl;
		return 0;
	}
	int count = 0;
	if (sr + 1 <= er) {
		count += mazePath(sr + 1, sc, er, ec, ans + "V") + 1;		//  + 1 to add height
	}
	if (sc + 1 <= ec) {
		count += mazePath(sr, sc + 1, er, ec, ans + "H") + 1;		//  + 1 to add height
	}
	return count;
}		//  return sum of all height

/*  __________ maze path with diagonal __________  */
int mazePathPlus(int sr, int sc, int er, int ec, string ans) {
	if (sr == er && sc == ec) {
		cout<<ans<<endl;
		return 0;
	}
	int leftHeight = 0, rightHeight = 0, diagHeight = 0;
	if (sr + 1 <= er) {
		leftHeight= mazePathPlus(sr + 1, sc, er, ec, ans + "V");
	}

	if (sr + 1 <= er && sc + 1 <= ec) {
		rightHeight= mazePathPlus(sr + 1, sc + 1, er, ec, ans + "D");
	}

	if (sc + 1 <= ec) {
		diagHeight = mazePathPlus(sr, sc + 1, er, ec, ans + "H");
	}
	return max(max(leftHeight + 1, rightHeight + 1), diagHeight + 1);
}		//  return the largest height of the branch

string mazePathPlus_string(int sr, int sc, int er, int ec, string ans) {
	if (sr == er && sc == ec) {
		// cout<<ans<<endl;
		return ans;
	}
	string leftHeight = "", rightHeight = "", diagHeight = "";
	if (sr + 1 <= er) {
		leftHeight= mazePathPlus_string(sr + 1, sc, er, ec, ans + "V");
	}

	if (sr + 1 <= er && sc + 1 <= ec) {
		rightHeight= mazePathPlus_string(sr + 1, sc + 1, er, ec, ans + "D");
	}

	if (sc + 1 <= ec) {
		diagHeight = mazePathPlus_string(sr, sc + 1, er, ec, ans + "H");
	}


	if (leftHeight.length() > rightHeight.length()) {
		if (leftHeight.length() > diagHeight.length()) {
			return leftHeight;
		}
		else {
			return diagHeight;
		}
	}
	else {
		if (rightHeight.length() > diagHeight.length()) {
			return rightHeight;
		}
		else {
			return diagHeight;
		}
	}
}		//  return the largest branch/path in form of string

/*  __________ maze path multimove with diagonal __________  */
int multiMazePath(int sr, int sc, int er, int ec, string ans) {
	if (sr == er && sc == ec) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	for (int jump = 1; sr + jump <= er; jump++) {
		count += multiMazePath(sr + jump, sc, er, ec, ans + "V" + to_string(jump));
	}

	for (int jump = 1; sr + jump <= er && sc + jump <= ec; jump++) {
		count += multiMazePath(sr + jump, sc + jump, er, ec, ans + "D" + to_string(jump));
	}

	for (int jump = 1; sc + jump <= ec; jump++) {
		count += multiMazePath(sr, sc + jump, er, ec, ans + "H" + to_string(jump));
	}

	return count;
}		//  return total no. of terms

/*  __________ board path __________  */
int functionCalling_boardPath = 0;
int boardPath(int ques, int ans, string ansStr) {
	functionCalling_boardPath++;				//  static variable
	if (ques == ans) {
		cout<<ansStr<<endl;
		return 1;
	}
	int count = 0;
	for (int dice = 1; dice <= 6 && ans + dice <= ques; dice++) {
		count += boardPath(ques, ans + dice, ansStr + to_string(dice));
	}
	return count;
}

/*  __________ solve __________  */
void solve() {
	string cases = mazePathPlus_string(0, 0, 2, 2, "");
	cout<<"total cases: "<<cases<<endl;
	// cout<<"function called: "<<functionCalling_boardPath<<endl;
}

/*  __________ main __________  */
int main(int args, char**argv) {
	solve();
	return 0;
}