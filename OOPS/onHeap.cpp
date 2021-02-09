#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<int>* yash = new vector<int>(6,8);
    // vector<int> yashi(6,8);
    vector<int> yashi(10000,8);
    for (int i : *yash) {
        cout << i << " ";
    }
    cout << sizeof(yash);
    cout << sizeof(yashi);

    
    int *arr = new int[5] {
        5,6,6,4
    };
    cout << arr[2] << endl;
    delete [] arr;
    return 0;
}