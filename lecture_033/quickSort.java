import java.util.Scanner;
public class quickSort {
    public static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {
        int[] arr = {8,1,3,4,7,9,6,4,5,2,1,-4,-9,2,1,3,1,5,4,44,55,99,-7,-99};
        
        // int[] arr={0};
        // quickSort_(arr, 0, arr.length - 1);
        // display(arr);
        // long start = System.currentTimeMillis();
        // int[] arr = new int[100000];
        quickSort_(arr, 0, arr.length - 1);
        // long end = System.currentTimeMillis();
        // System.out.println(end - start);
    }
    
    public static void display(int[] arr) {
        for (int ele : arr) {
            System.out.print(ele + " ");
        }
        System.out.println();
    }

    public static void swap_(int[] arr, int idx1, int idx2) {
        //  swap two numbers in given array
        arr[idx1] = arr[idx1] ^ arr[idx2] ^ (arr[idx2] = arr[idx1]);
    }

    public static void quickSort_(int[] arr, int si, int ei) {
        if (si >= ei) {
            return ;
        }
        int piviot = arr[(ei+si)>>1];
        int pidx = piviotIdx(arr, si, ei, piviot);
        quickSort_(arr, si, pidx - 1);
        quickSort_(arr, pidx + 1, ei);
    }

    public static int piviotIdx(int[] arr, int si, int ei, int piviot) {
        int pidx = si, itr = si;
        while (itr <= ei) {
            if (arr[itr] <= piviot) {
                swap_(arr, pidx, itr);
                pidx++;
            }
            itr++;
        }
        return pidx - 1;
    }
}