//  create a program to do simple mathematics
//  adding matrices

#include <iostream>
#include <vector>
using namespace std;

void input(vector <vector <int>> & matrix) {
	for (int r = 0; r < matrix.size(); r++) {
		for (int c = 0; c < matrix[0].size(); c++) {
			cin>>matrix[r][c];
		}
	}
}

void display(vector<vector<int>>& matrix) {
	for (vector <int> arr : matrix) {
		for (int ar : arr) {
			cout<<ar<<" ";
		}
		cout<<endl;
	}
}

vector<vector <int>> sum_(vector <vector <int>> &mat1, vector <vector <int>> &mat2) {
	vector <vector <int>> sumMat_(mat1.size(), vector <int> (mat1[0].size()));
	for (int r = 0; r < mat1.size(); r++) {
		for (int c = 0; c < mat1[0].size(); c++) {
			sumMat_[r][c] = mat1[r][c] + mat2[r][c];
		}
	}
	return sumMat_;
}

vector<vector<int>> mul_(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
	vector<vector<int>> mulMat_(mat1.size(), vector<int>(mat2[0].size(),0));

	if (mat1[0].size() == mat2.size()) {
		for (int r = 0; r < mulMat_.size(); r++) {
			for (int c = 0; c < mulMat_[0].size(); c++) {
				for (int val = 0; val < mat1[0].size(); val++) {
					mulMat_[r][c] += mat1[r][val] * mat2[val][c];
				}
			}
		}
	//	 display(mulMat_);
		return mulMat_;
	}
	return mulMat_;
}

int main (int args, char**argv) {
	int row1 = 0, col1 = 0, row2 = 0, col2 = 0;
	cin>>row1;
	cin>>col1;
	cin>>row2;
	cin>>col2;
	vector <vector <int>> mat1 (row1, vector <int> (col1, 0));
	vector <vector <int>> mat2(row2, vector<int>(col2, 0));

	input(mat1);
	cout<<endl;
	input(mat2);
	cout<<"mul: "<<endl;
	//display(mat1);
	//display(mat2);
	vector <vector <int>> mulMat_ = mul_(mat1, mat2);
	display(mulMat_);
	
	return 0;
}