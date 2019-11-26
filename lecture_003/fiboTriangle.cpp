//  creating the given pattern

// 0
// 1  1
// 2  3  5
// 8 13 21 34

#include<iostream>

using namespace std;
int main(int args, char**argv) {
    cout<<"enter the number of rows";
    int rows;
    cin>>rows;
    int nst = 1;
    int val1 = 0, val2 = 1, temp;
    for(int r = 1; r <= rows; r++){
        
        for (int cst = 1; cst <= nst; cst++){
            cout<<val1<<" ";
            temp = val1 + val2;
            val1 = val2;
            val2 = temp;
        }
        nst++;
        cout<<endl;
    }

    return 0;
}