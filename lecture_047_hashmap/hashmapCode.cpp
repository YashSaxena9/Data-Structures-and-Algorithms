#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void longestSeries_dispersed(vector<int>& arr) {
    unordered_map<int, bool> map;
    for (int ele : arr) {
        map[ele] = true;
    }
    int size = -1;
    int number = -1;
    for (auto kv_pair : map) {      //  for (int keys : map.keySet())
        if (kv_pair.second) {       //  if (map.get(keys))
            if (map.find(kv_pair.first - 1) != map.end()) {     //  if present
                map[kv_pair.first] = false;
            }
        }
    }
    for (auto keys : map) {
        if (keys.second) {
            int num = keys.first + 1;
            int smallSize = 1;
            while (map.find(num) != map.end()) {
                smallSize++;
                num++;
            }

            if (smallSize > size) {
                size = smallSize;
                number = keys.first;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        cout << number + i << " ";
    } cout << endl;
}

int main(int args, char**argv) {
    vector<int> arr = {0, 1, 2, 100, 99, 98, 97, 96, 95, 94, 12, 3, 4, 5, 10, 8};
    longestSeries_dispersed(arr);
    return 0;
}