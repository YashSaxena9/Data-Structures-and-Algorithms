/**
 * ______Naive approach______ :-
 * make an array of pairs which contain their value(first) and index(second)
 * sort the pair array on the basis of value(first)
 * use 2 iterators at beginning and at end
 * find 2 digits for two sum
 */

import java.util.Scanner;
import java.util.BitSet;

//  ================================= Solution ===================================
class pair {
    public int first = 0, second = 0;
    pair(int first, int second) {
        this.first = first;
        this.second = second;
    }
    pair(pair obj) {
        this.first = obj.first;
        this.second = obj.second;
    }
}

class Solution {
    private pair[] merge(pair[] left, pair[] right) {
        pair[] ans = new pair[left.length + right.length];
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;
        while (ptr1 < left.length || ptr2 < right.length) {
            if (ptr1 < left.length && ptr2 < right.length) {
                ans[ptr3++] = (left[ptr1].first <= right[ptr2].first) ? left[ptr1++] : right[ptr2++];
            }
            else if (ptr1 >= left.length){
                ans[ptr3++] = right[ptr2++];
            }
            else if (ptr2 >= right.length){
                ans[ptr3++] = left[ptr1++];
            }
        }
        return ans;
    }
    
    private pair[] mergeSort(pair[] arr, int si, int ei) {
        if (si == ei) {
            pair[] base = new pair[1];
            base[0] = arr[si];
            return base;
        }
        int mid = (si + ei) >> 1;
        pair[] left = mergeSort(arr, si, mid);
        pair[] right = mergeSort(arr, mid + 1, ei);
        return merge(left, right);
    }
    
    private int[] targetSum(pair[] arr, int target) {
        int si = 0, ei = arr.length - 1;
        while (si < ei) {
            int currValue = arr[si].first + arr[ei].first;
            if (currValue == target) {
                return new int[]{arr[si].second, arr[ei].second};
            }
            else if (arr[si].first + arr[ei].first > target) {
                ei--;
            }
            else {
                si++;
            }
        }
        return new int[]{-1, -1};
    }
    
    public int[] twoSum(int[] nums, int target) {
        pair[] numPair = new pair[nums.length];
        for (int i = 0; i < nums.length; i++) {
            numPair[i] = new pair(nums[i], i);
        }
        numPair = mergeSort(numPair, 0, nums.length - 1);
        return targetSum(numPair, target);     
    }
}
//  ===========================================================================

/**
 * twoSum
 */
public class twoSum {
    private static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {
        int[] nums = {2, 10, 15, 7, 11};
        Solution sol = new Solution();
        int[] ans = sol.twoSum(nums, 9);
        System.out.println(ans[0] + ", " + ans[1] + ": size = " + ans.length);
    }
}