import java.util.Scanner;
/**
 * mergeSort
 */
public class mergeSort {
    public static Scanner scn = new Scanner(System.in);
    
    public static void main(String[] args) {
        // int[] arr = {-1,6,5,7,8,9,6,56,42,-55,99,-99,-66,-2,1,444,78,44,5,3,2,8,96,-1,-2,-4,-7,-5,5,5,6,9};
        // display(mergeSort_(arr, 0, arr.length - 1));
        long start = System.currentTimeMillis();
        int[] arr = new int[100000];
        arr = mergeSort_(arr, 0, arr.length - 1);
        long end = System.currentTimeMillis();
        System.out.println(end - start);
    }

    public static void display(int[] arr) {
        for (int ele : arr) {
            System.out.print(ele + " ");
        }
        System.out.println();
    }

    public static int[] mergeArr(int[] arr1, int[] arr2) {
        int[] ans = new int[arr1.length + arr2.length];
        int ptr1 = 0, ptr2 = 0, ptr3 = 0;
        while (ptr1 < arr1.length || ptr2 < arr2.length) {
            if (ptr1 < arr1.length && ptr2 < arr2.length) {
                ans[ptr3++] = (arr1[ptr1] <= arr2[ptr2]) ? arr1[ptr1++] : arr2[ptr2++];
            }
            else if (ptr1 >= arr1.length){
                ans[ptr3++] = arr2[ptr2++];
            }
            else if (ptr2 >= arr2.length){
                ans[ptr3++] = arr1[ptr1++];
            }
        }
        return ans;
    }

    public static int[] mergeSort_(int[] arr, int si, int ei) {
        if (si == ei) {
            int[] base = new int[1];
            base[0] = arr[si];
            return base;
        }
        int mid = (si + ei)>>>1;
        int[] leftRec = mergeSort_(arr, si, mid);
        int[] rightRec = mergeSort_(arr, mid + 1, ei);
        return mergeArr(leftRec, rightRec);
    }
}