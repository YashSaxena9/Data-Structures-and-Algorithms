//  basic and methods of vectors

#include<iostream>
#include<vector>		//  header file to use vectors
using namespace std;

void display(vector<int> &arr) {
	for (int i : arr) {
		cout<<i<<" ";
	}
	cout<<endl;
}

int main(int args, char**argv) {
	vector<int> arr1 = {1,2,3};
	vector<int> arr2(5,2);
	
	arr2.push_back(10);
	display(arr2);

	arr2.pop_back();
	display(arr2);

	if (arr2.empty()) {
		cout<<"is empty";
	}

	cout<<"capacity(doubles if push_back is used):"<<arr2.capacity()<<endl;
	cout<<"Size of arr(current size , <= capacity):"<<arr2.size()<<endl;
	cout<<"maximum size a vector can attain without 0(n) operation of copying :"<<arr2.max_size()<<endl;

	cout<<"front:"<<arr2.front()<<endl;
	cout<<"back:"<<arr2.back()<<endl;

	return 0;
}