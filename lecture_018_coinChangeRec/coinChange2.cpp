//  coin change problems
//  combinations and permutations
//  can use value of coin only once

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* __________ print all combinations to make target number __________ */
int allComb_(vector<int> &ques, int vidx, int target, string ans) {
	if (vidx == ques.size() || target <= 0) {
		if (target == 0) {
			cout<<ans<<endl;
			return 1;
		}
		return 0;
	}
	int count = 0;

	for (int i = vidx; i < ques.size(); i++) {
		count += allComb_(ques, i + 1, target - ques[i], ans + to_string(ques[i]) + " ");
	}
	return count;
}

/* __________ print all permutations to make target number __________ */
int allPerm_(vector<int> &ques, vector<bool> &isDone, int target, string ans) {
	if (target == 0) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;

	for (int i = 0; i < ques.size(); i++) {
		if (target - ques[i] >= 0 && !isDone[i]) {
			isDone[i] = true;
			count += allPerm_(ques, isDone, target - ques[i], ans + to_string(ques[i]) + " ");
			isDone[i] = false;
		}
	}
	return count;
}

/* __________ solve __________ */
void solve() {
	// vector <int> arr = {2, 3, 5, 7};
	// int count = allComb_(arr, 0, 10, "");
	vector<int> arr = {2, 3, 5, 7};
	vector<bool> isDone(arr.size(), false);
	int count = allPerm_(arr, isDone, 10, "");
	cout<<count<<endl;
}

/* __________ main __________ */
int main(int args, char**argv) {
	solve();
	return 0;
}