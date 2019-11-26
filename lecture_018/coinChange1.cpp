//  coin change problems
//  combinations and permutations
//  can use value of coin infinite time

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
		count += allComb_(ques, i, target - ques[i], ans + to_string(ques[i]) + " ");
	}
	return count;
}

/* __________ print all permutations to make target number __________ */
int allPerm_(vector<int> &ques, int vidx, int target, string ans) {
	if (vidx == ques.size() || target <= 0) {
		if (target == 0) {
			cout<<ans<<endl;
			return 1;
		}
		return 0;
	}
	int count = 0;

	for (int i = 0; i < ques.size(); i++) {
		count += allPerm_(ques, i, target - ques[i], ans + to_string(ques[i]) + " ");
	}
	return count;
}

/* __________ solve __________ */
void solve() {
	vector <int> arr = {2, 3, 5, 7};
	int count = allPerm_(arr, 0, 10, "");
	cout<<count<<endl;
}

/* __________ main __________ */
int main(int args, char**argv) {
	solve();
	return 0;
}