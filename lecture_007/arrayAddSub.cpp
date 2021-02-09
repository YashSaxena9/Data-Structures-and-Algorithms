//  assume 2 arrays are given , add them and subtract them in a third array without converting them to actual numbers
//  pure array addition and subtraction

#include <iostream>
#include <vector>
using namespace std;

void display(vector <int> &arr) {
	for (int i : arr) {
		cout<<i<<" ";
	}
	cout<<endl;
}

void addByNumber(vector<int> &arr1, vector<int> &arr2) {
	int num1 = 0;
	for (int i = 0; i < arr1.size(); i++) {
		num1 *= 10;
		num1 += arr1[i];
	}

	int num2 = 0;
	for (int i = 0; i < arr2.size(); i++) {
		num2 *= 10;
		num2 += arr2[i];
	}

	num1 += num2;
	num2 = num1;
	
	int count = 0;
	while(num2) {
		num2 /= 10;
		count++; 
	}
	
	vector <int> ans(count);
	int idx = count - 1;
	while(num1 != 0) {
		int rem = num1 % 10;
		num1 /= 10;
		ans[idx] = rem;
		idx--;
	}
	
	display(ans);

}

void addByArray(vector <int> &arr1, vector <int> &arr2) {
	int carry = 0;
	int itr3 = arr1.size() < arr2.size() ? arr2.size(): arr1.size();
	vector<int> ans_arr(itr3+1);
	int itr1 = arr1.size() - 1, itr2 = arr2.size() - 1 ;
	
	while( itr1 >= 0 && itr2 >= 0) {
		int ans = arr1[itr1] + arr2[itr2] + carry;
		int rem = ans % 10;
		 carry = ans / 10;
		ans_arr[itr3] = rem;
		itr3--;
		itr2--;
		itr1--;
	}

	while (itr1 >= 0) {
		int ans = arr1[itr1] + carry;
		int rem = ans % 10;
		carry = ans / 10;
		ans_arr[itr3] = rem;
		itr3--;
		itr1--;
	}
	
	while (itr2 >= 0) {
		int ans = arr2[itr2] + carry;
		int rem = ans % 10;
		 carry = ans / 10;
		ans_arr[itr3] = rem;
		itr3--;
		itr2--;
	}
	
	display(ans_arr);
}

/* subtraction */
void subByArray(vector<int> &arr1, vector<int> &arr2) {
	int itr3 = arr1.size() < arr2.size()? arr2.size() : arr1.size();
	vector<int> sumArr(itr3, 0);
	int itr2 = arr2.size() - 1;
	int itr1 = arr1.size() - 1;
	int borrow = 0;
	
	while (itr1 >= 0 || itr2 >= 0) {
		int ans = borrow;
		borrow = 0;
		if (itr1 >= 0) ans += arr1[itr1];
		if (itr2 >= 0) ans -= arr2[itr2];
		if (ans < 0) {
			ans += 10;
			borrow = -1;
		}
		sumArr[itr3 - 1] = ans;
		itr1--;
		itr2--;
		itr3--;
	}
	
	display(sumArr);
}

int main(int args, char**argv)
{
	vector <int> arr1 = {1,6,8,9};
	vector <int> arr2 = {3,2};
	// addByArray(arr1, arr2);
	// addByNumber(arr1,arr2);
	subByArray(arr1, arr2);
	return 0;
}
