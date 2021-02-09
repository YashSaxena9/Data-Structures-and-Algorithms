//  coin change problems
//  combinations and permutations
//  can use value of coin only once
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

	count += allComb_(ques, vidx + 1, target - ques[vidx], ans + to_string(ques[vidx]) + " ");
	count += allComb_(ques, vidx + 1, target, ans);
	return count;
}

/* __________ print all permutations to make target number using subsequence __________ */
int allPerm_(vector<int> &ques, vector<bool> &isDone, int vidx, int target, string ans) {
	if (vidx == ques.size() || target <= 0) {
		if (target == 0) {
			cout<<ans<<endl;
			return 1;
		}
		return 0;
	}
	int count = 0;

	if (!isDone[vidx]) {
		isDone[vidx] = true;
		count += allPerm_(ques, isDone, 0, target - ques[vidx], ans + to_string(ques[vidx]) + " ");
		isDone[vidx] = false;
	}
	count += allPerm_(ques, isDone, vidx + 1, target, ans);
	return count;
}

/* __________ solve __________ */
void solve() {
	// vector<int> arr = {2, 3, 5, 7};
	// int count = allComb_(arr, 0, 10, "");
	// cout<<count<<endl;
	vector<int> arr = {2, 3, 5, 7};
	vector<bool> isDone(arr.size(), false);
	int count = allPerm_(arr, isDone, 0, 10, "");
	cout<<count<<endl;
}

/* __________ main __________ */
int main(int args, char**argv) {
	solve();
	return 0;
}