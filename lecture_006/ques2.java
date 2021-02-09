//  dutch flag algorithm

//  sort {0,1,1,0,1,1,1,1,0,0,0,1,0,1,0,0,1,1,1,0,0,0,0,1,1,0,1,0,1,0} to sorted {0...., 1....} form
//  sort {0,1,2,0,1,2,1,1,0,0,0,1,0,2,0,0,1,1,1,0,2,2,0,1,1,0,1,0,2,0} to sorted {0...., 1...., 2....} form

/**
 * ques2
 */
import java.util.Scanner;

public class ques2 {
	public static Scanner scn = new Scanner(System.in);
	public static void main(String[] args) {
		// int[] arr = {0,1,1,1,0,0,1,0,1,1,1,1,0,0,0,1,1,0,0,0,1,1,0,0,0,1};
		int[] arr = {0,1,2,0,1,2,1,1,0,0,0,1,0,2,0,0,1,1,1,0,2,2,0,1,1,0,1,0,2,0};
		display(arr);
		System.out.println();
		sortZeroOneTwo(arr);
		display(arr);
	}

	public static void input(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			arr[i] = scn.nextInt();
		}
	}

	public static void display(int[] arr) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}

	public static void swap(int[] arr, int si, int ei) {
		int temp = arr[si];
		arr[si] = arr[ei];
		arr[ei] = temp;
	}
	public static void sortZeroOne(int[] arr) {
		int ptr = 0, itr = 0;
		while (itr < arr.length) {
			if (arr[itr] == 0) {
				swap(arr, ptr, itr);
				ptr++;
			}
			itr++;
		}
	}
	
	public static void sortZeroOneTwo(int[] arr) {
		int ptr1 = 0, ptr2 = arr.length - 1, itr = 0;
		while (itr <= ptr2) {
			if (arr[itr] == 0) {
				swap(arr, ptr1, itr);
				ptr1++;
				itr++;
			}
			else if(arr[itr] == 2) {
				swap(arr, itr, ptr2);
				ptr2--;		//  it++ not done because its possible that last entity is also 2
			}
			else {			//  for one's
				itr++;
			}
		}
	}
}