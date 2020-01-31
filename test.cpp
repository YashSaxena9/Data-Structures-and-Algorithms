#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<pair<int, int>> merge(vector<pair<int, int>>& left, vector<pair<int, int>>& right) {
        vector<pair<int, int>> ans(left.size() + right.size());
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;
        while (ptr1 < left.size() || ptr2 < right.size()) {
            if (ptr1 < left.size() && ptr2 < right.size()) {
                ans[ptr3++] = (left[ptr1] <= right[ptr2]) ? left[ptr1++] : right[ptr2++];
            }
            else if (ptr1 >= left.size()){
                ans[ptr3++] = right[ptr2++];
            }
            else if (ptr2 >= right.size()){
                ans[ptr3++] = left[ptr1++];
            }
        }
        return ans;
    }
    
    vector<pair<int, int>> mergeSort(vector<pair<int, int>>& arr, int si, int ei) {
        if (si == ei) {
            return {arr[si]};
        }
        int mid = (si + ei) >> 1;
        vector<pair<int, int>> left = mergeSort(arr, si, mid);
        vector<pair<int, int>> right = mergeSort(arr, mid + 1, ei);
        return merge(left, right);
    }
    
    vector<int> targetSum(vector<pair<int, int>>& arr, int target) {
        int si = 0, ei = arr.size() - 1;
        while (si < ei) {
            int currValue = arr[si].first + arr[ei].first;
            if (currValue == target) {
                return {arr[si].second, arr[ei].second};
            }
            else if (arr[si].first + arr[ei].first > target) {
                ei--;
            }
            else {
                si++;
            }
        }
        return {-1, -1};
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> numPair(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            numPair[i] = {nums[i], i};
        }
        numPair = mergeSort(numPair, 0, nums.size() - 1);
        return targetSum(numPair, target);
    }
};

int main(int args, char**argv) {
    Solution twoSum_;
    vector<int> nums = {2, 7, 10, 15};
    int tar = 12;
    vector<int> ans = twoSum_.twoSum(nums, tar);
    cout << ans[0] << " " << ans[1] << " , size : " << ans.size() << endl;
}