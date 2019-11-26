//  in an array of 0 and 1 , we enter horizontally from [0,0] at every encounter of 1, we change direction by 90deg. clokwise
//  the point when we exit matrix that last value of matrix is the exit point...print it

#include<iostream>
#include<vector>
using namespace std;

void exitPoint(vector<vector<int>> &mat_) {
	int dir_ = 0;		//  direction ({0 : left},{1 : down},{2 : right},{3 : up})
	int row = 0, col = 0;
	cout<<"exit point is: "<<endl;
	while(true) {
		dir_ = (dir_ + mat_[row][col]) % 4;
		if (dir_ == 0) {
			col++;
			if (col == mat_[0].size()) {
				cout<<"row: "<<row<<", col: "<<col - 1<<endl;
				return;
			}		
		}
		else if (dir_ == 1) {
			row++;
			if (row == mat_.size()) {
				cout<<"row: "<<row - 1<<", col: "<<col<<endl;
				return;
			}			
		}
		else if (dir_ == 2) {
			col--;
			if (col == -1) {
				cout<<"row: "<<row<<", col: "<<col + 1<<endl;
				return;
			}					
		}
		else {
			row--;
			if (row == -1) {
				cout<<"row: "<<row + 1<<", col: "<<col<<endl;
				return;
			}					
		}
	}
}

int main(int args, char**argv) {
	vector<vector<int>> mat_ = {
		{0,0,0,0,1},
		{1,0,0,1,0},
		{0,0,0,0,0},
		{0,1,0,1,0},
		{1,0,0,0,1}
	};
	exitPoint(mat_);
	return 0;
}