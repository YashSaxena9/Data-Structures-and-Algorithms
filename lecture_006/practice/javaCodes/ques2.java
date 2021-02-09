// dutch flag algorithm

// sort {0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1,0,1,0} to sorted {0...., 1....} form
// sort {0,1,2,0,1,2,1,1,0,0,0,1,0,2,0,0,1,1,1,0,2,2,0,1,1,0,1,0,2,0} to sorted {0...., 1...., 2....} form

/**
 * ques2
 */
import java.util.Scanner;

public class ques2 {
	public static Scanner scn = new Scanner(System.in);
	public static void main(String[] args) {
		int[] arr1 = { 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1 };
		int[] arr2 = { 0, 1, 2, 0, 1, 2, 1, 1, 0, 0, 0, 1, 0, 2, 0, 0, 1, 1, 1, 0, 2, 2, 0, 1, 1, 0, 1, 0, 2, 0 };
		display(arr2);
		System.out.println();
		zeroOneTwo(arr2);
		display(arr2);
		System.out.println();
	}
	public static void swap(int[] arr, int num1, int num2) {
		int temp = arr[num1];
		arr[num1] = arr[num2];
		arr[num2] = temp;
	}

	public static void zeroOne(int[] arr) {
		int ptr = 0, itr = 0;
		while (itr < arr.length) {
			if (arr[itr] == 0) {
				swap(arr, itr, ptr);
				ptr++;
			}
			itr++;
		}
	}
	
	public static void zeroOneTwo(int[] arr) {
		int ptr1 = 0,ptr2 = arr.length - 1, itr = 0;
		while (itr <= ptr2) {
			if (arr[itr] == 0) {
				swap(arr, itr, ptr1);
				ptr1++;
				itr++;
			}
			else if (arr[itr] == 2) {
				swap(arr, itr, ptr2);
				ptr2--;
			}
			else{
				itr++;
			}
		}
	}

	public static void display(int[] arr) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}
}