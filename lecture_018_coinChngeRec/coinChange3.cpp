//  coin change problems
//  combinations and permutations
//  can use value of coin infinite times
//  use subsequence method (will add or will not add opportunity)

#include<iostream>
#include<vector>
#include<string>
using namespace std;

/* __________ print all combinations to make target number using subsequence __________ */
int allComb_(vector<int> &ques, int vidx, int target, string ans) {
	if (vidx == ques.size() || target <= 0) {
		if (target == 0) {
			cout<<ans<<endl;
			return 1;
		}
		return 0;
	}
	int count = 0;

	count += allComb_(ques, vidx, target - ques[vidx], ans + to_string(ques[vidx]) + " ");
	count += allComb_(ques, vidx + 1, target, ans);
	return count;
}

/* __________ print all permutations to make target number using subsequence __________ */
int allPerm_(vector<int> &ques, int vidx, int target, string ans) {
	if (vidx == ques.size() || target <= 0) {
		if (target == 0) {
			cout<<ans<<endl;
			return 1;
		}
		return 0;
	}
	int count = 0;

	count += allPerm_(ques, 0, target - ques[vidx], ans + to_string(ques[vidx]) + " ");
	count += allPerm_(ques, vidx + 1, target, ans);
	return count;
}

/* __________ solve __________ */
void solve() {
	vector<int> arr = {2, 3, 5, 7};
	// int count = allComb_(arr, 0, 10, "");
	// cout<<count<<endl;
	int count = allPerm_(arr, 0, 10, "");
	cout<<count<<endl;
}

/* __________ main __________ */
int main(int args, char**argv) {
	solve();
	return 0;
}