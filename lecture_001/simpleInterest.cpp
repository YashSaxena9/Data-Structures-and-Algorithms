#include<iostream>

using namespace std;
int main(int args, char** argv)
{
    // int p = 1000;
    // int r = 2;
    // int t = 3;

    //  with user input:-
    int p, r, t;
    cin>>p>>r>>t;
    //  end:-

    int si = ((p * r * t)/100);
    cout<<"Simple interest: "<<si<<endl;                 //  endl takes cursor to next line
}