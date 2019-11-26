//  patterns
//  self tried


#include<iostream>
using namespace std;
int main(int args, char**argv){
    
    //  pattern:-
    // *
    // **
    // ***
    // ****
    // *****

    for (int i = 1; i<=5; i++){
        for (int j = 1; j <= i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //     *
    //    **
    //   ***
    //  ****
    // *****

    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5; j++){
            if (j<=5-i){
                cout << "  ";
            }
            else{
                cout<<"* ";
            }
        }
        cout<<endl;
    }

    return 0;
}