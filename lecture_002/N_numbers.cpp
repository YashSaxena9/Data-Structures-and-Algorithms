//  1 to N numbers

#include<iostream>
using namespace std;
int main(int args, char**argv)
{
    int n;
    cout<<"enter the nth number: ";
    cin>>n;

    //  for loop 
    for(int i = 1; i <= n; i++){            //  here int i has scope upto end of the loop, not beyond that
        cout<<i<<endl;
    }
    //  end of for loop

    return 0;
}