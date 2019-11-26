import java.util.Scanner;

public class timeComplex {

    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {
        int[] arr = new int[10000];
        long start = System.currentTimeMillis();
        arr = mergeSort(arr, 0, arr.length - 1);
        long mid = System.currentTimeMillis();
        bubbleSort(arr);
        long end = System.currentTimeMillis();
        System.out.println("merge : " + (mid - start));
        System.out.println("bubble : " + (end - mid));
    }
    
    //  ____ bubble sort _____
    public static void swap_(int[] arr, int idx1, int idx2) {
        arr[idx1] = arr[idx1] ^ arr[idx2] ^ (arr[idx2] = arr[idx1]);
    }
    
    public static void bubbleSort(int[] arr) {
        int val = 1;
        while (val <= arr.length - 1) {
            for (int i = 0; i < arr.length - val; i++) {
                if (arr[i] > arr[i + 1]) {
                    swap_(arr, i, i + 1);
                }
            }
            val++;
        }
    }
    
    //  ____ merge sort _____
    public static int[] merge(int[] arr1, int[] arr2) {
        int[] ans = new int[arr1.length + arr2.length];
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;
        while (ptr1 != arr1.length || ptr2 != arr2.length) {
            if (ptr1 != arr1.length && ptr2 != arr2.length) {
                ans[ptr3++] = (arr1[ptr1] <= arr2[ptr2]) ? arr1[ptr1++] : arr2[ptr2++];
            }
            else if (ptr1 >= arr1.length) {
                ans[ptr3++] = arr2[ptr2++];
            }
            else if (ptr2 >= arr2.length) {
                ans[ptr3++] = arr1[ptr1++];
            }
        }
        return ans;
    }
    
    public static int[] mergeSort(int[] arr, int si, int ei) {
        if (si == ei) {
            int[] base = new int[1];
            base[0] = arr[si];
            return base;
        }
        int mid = (si + ei) >> 1;
        int[] left = mergeSort(arr, si, mid);
        int[] right = mergeSort(arr, mid + 1, ei);
        return merge(left, right);
    }
}