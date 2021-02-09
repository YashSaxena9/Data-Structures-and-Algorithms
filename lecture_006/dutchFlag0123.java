// use dutch flag to sort array with only 0,1,2,3

import java.util.Scanner;

public class dutchFlag0123 {
	public static Scanner scn = new Scanner(System.in);
	
	public static void main(String[] args) {
		
		System.out.print("enter the size: ");
		int size = scn.nextInt();
		int[] arr = new int[size];
		input(arr);
		display(arr);
		sortDutchFlag(arr);
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
		System.out.println();
	}

	public static int countThree(int[] arr) {
		int count = 0;
		for (int i : arr) {
			if (i == 3) {
				count++;
			}
		}
		return count;
	}

	public static void swap(int[] arr, int num1, int num2) {
		int temp = arr[num1];
		arr[num1] = arr[num2];
		arr[num2] = temp;
	}

	public static void sortDutchFlag(int[] arr) {
		int threes = countThree(arr);
		int ptr1 = 0, ptr2 = arr.length - threes - 1 , ptr3 = arr.length - 1, itr = 0;
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
			else if (arr[itr] == 3) {
				swap(arr, itr, ptr3);
				ptr3--;
			}
			else {
				itr++;
			}
		}
	}
}