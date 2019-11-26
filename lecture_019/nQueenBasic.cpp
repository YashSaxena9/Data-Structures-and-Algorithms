#include<iostream>
#include<vector>
using namespace std;

/* __________ n queen fundamentals (combinations) __________ */
int fund_N_QueenComb(int size, int idx, int queenCount, int totQueens, string ans) {
	if (queenCount > totQueens) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	for (int i = idx; i < size; i++) {
		count += fund_N_QueenComb(size, i + 1, queenCount + 1, totQueens, ans + "q" + to_string(queenCount) + "b" + to_string(i) + " ");
	}
	return count;
}

/* __________ n queen fundamentals (permutations) __________ */
int fund_N_QueenPerm(int size, int bit_, int queenCount, int totQueens, string ans) {
	if (queenCount > totQueens) {
		cout<<ans<<endl;
		return 1;
	}
	int count = 0;
	for (int i = 0; i < size; i++) {
		if ((bit_ & (1 << i)) == 0) {
			bit_ = (bit_ | (1 << i));
			count += fund_N_QueenPerm(size, bit_, queenCount + 1, totQueens, ans + "q" + to_string(queenCount) + "b" + to_string(i) + " ");
			bit_ = (bit_ & (~(1 << i)));
		} 
	}
	return count;
}

/* __________ solve __________ */
void solve() {
	// int count = fund_N_QueenComb(6, 0, 1, 3, "");
	int count = fund_N_QueenPerm(6, 0, 1, 3, "");
	cout<<count<<endl;
}

int main(int args, char**argv) {
	solve();
	return 0;
}