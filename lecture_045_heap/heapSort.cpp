#include<iostream>
#include<vector>
using namespace std;

int compareTo(vector<int>& arr, int idx1, int idx2, bool isMax) {
    if (isMax) {
        return arr[idx1] - arr[idx2];
    } else {
        return arr[idx2] - arr[idx1];
    }
}

void downHeapify(vector<int>& arr, int idx, int lidx, bool isMax) {
    int currIdx = idx;
    int lci = 2 * idx + 1;
    int rci = 2 * idx + 2;
    if (lci < lidx && compareTo(arr, lci, currIdx, isMax) > 0) {
        currIdx = lci;
    }
    if (rci < lidx && compareTo(arr, rci, currIdx, isMax) > 0) {
        currIdx = rci;
    }
    if (currIdx != idx) {
        swap(arr[currIdx], arr[idx]);
        downHeapify(arr, currIdx, lidx, isMax);
    }
}

void heapSort(vector<int>& arr, bool inInc = true) {
    bool isMax = inInc;
    int n = arr.size() - 1;
    for (int i = n; i >= 0; i--) {
        downHeapify(arr, i, n + 1, isMax);
    }
    // for (int ele : arr) {
    //     cout << ele << " ";
    // }cout << endl;

    for (int i = 0; i <= n; i++) {
        swap(arr[0], arr[n - i]);
        downHeapify(arr, 0, n - i, isMax);
    }
}

int main(int args, char**argv) {
    vector<int> arr = {10, 20, 30, -2, -3, -4, 5, 6, 7, 8, 9, 22, 11, 13};
    heapSort(arr, true);
    // heapSort(arr, false);
    for (int ele : arr) {
        cout << ele << " ";
    }cout << endl;
    return 0;
}