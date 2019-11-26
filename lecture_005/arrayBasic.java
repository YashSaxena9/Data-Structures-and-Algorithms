//  creating input method in array

//  make reverve() function and rotate(arr, k) function{no extra array}

//  reverse()
//  rotate(arr, k)

import java.util.Scanner;

/*
	//  Integer.MAX_VALUE  =  +ve infinity   //
	//  Integer.MIN_VALUE  =  -ve infinity   //
/*

/*
 	arrayBasic
*/
public class arrayBasic {

	//  now every function / method can use scn scanner for input
	public static Scanner scn = new Scanner(System.in);
	public static void main(String[] args) {
		
		System.out.print("enter the size of array: ");
		int size = scn.nextInt();
		int[] arr1 = new int[size];
		input(arr1);
		System.out.println();
		System.out.print(min(arr1));
		System.out.println();
		// System.out.println(min(arr1));
		// System.out.println(max(arr1));
		// int num = scn.nextInt();
		// System.out.print(find(arr1, num));
		// System.out.println();
		// int si = scn.nextInt();		//  starting index for reverse function
		// int ei = scn.nextInt();		//  ending index for reverse function
		// reverse(arr1, si, ei);
		// System.out.println();
		// display(arr1);
		// int lim = scn.nextInt();
		// rotate(arr1, lim);
		// System.out.println();
		// display(arr1);

	}

	public static void input(int[] arr1) {
		for(int i = 0; i < arr1.length; i++) {
			arr1[i] = scn.nextInt();
		}
	}

	public static void display(int[] arr1) {
		for(int i : arr1) {
			System.out.print(i + " ");
		}
	}

	public static void swap(int[] arr1, int si, int ei) {
		int temp = arr1[ei];
		arr1[ei] = arr1[si];
		arr1[si] = temp;
	}

	public static void reverse(int[] arr1, int si, int ei) {
		while(si < ei) {
		swap(arr1, si, ei);
		si++;
		ei--;
		}
	}

	public static void rotate(int[] arr1, int lim) {
		lim %= arr1.length;
		if (lim < 0) {
			lim += arr1.length;
		}
		reverse(arr1, 0, lim - 1);
		reverse(arr1, lim, arr1.length - 1);
		reverse(arr1, 0, arr1.length - 1);
	}

	public static boolean find(int[] arr1, int num) {
		for(int i : arr1) {
			if (i == num) {
				return true;
			}
		}
		return false;
	}

	public static int max(int[] arr1) {
		int max_ = arr1[0];
		for(int i : arr1) {
			if (i > max_) {
				max_ = i;
			}
		}
		return max_;
	}

	public static int min(int[] arr1) {
		int min_ = Integer.MAX_VALUE;
		for (int i : arr1) {
			if (i < min_) {
				min_ = i;
			}
		}
		return min_;
	}
}