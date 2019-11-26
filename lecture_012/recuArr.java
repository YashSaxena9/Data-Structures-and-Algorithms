//  recursion on dynamic array

import java.util.ArrayList;
import java.util.Scanner;

public class recuArr {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		// ArrayList <Integer> arr = new ArrayList<>();
		int[] arr1 = {-2, 16, 100, 1, -19, 13, -12, 5, 100, 1, -19, 100, 16, 13, 14, 13};
		// input(arr);
		System.out.println(lastIdx(arr1, 0, 100));
		display(allIdx(arr1, 0, 100, 0));
		// System.out.println("max value, index: " + lastMax(arr, arr.size() - 1));
	}

	public static void input(ArrayList <Integer> arr) {
		int size_ = scn.nextInt();
		for (int i = 0; i < size_; i++) {
			int val = scn.nextInt();
			arr.add(val);
		}
	}

	public static void display(int[] arr) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
		System.out.println();
	}

	// public static int lastMax(ArrayList <Integer> arr, int idx) {
	// 	if (idx < 0) {
	// 		return Integer.MIN_VALUE;
	// 	}
	// 	int next_ = lastMax(arr, idx - 1);
	// 	if (Math.max(arr.get(next_), arr.get(idx)) == arr.get(next_)) {
	// 		return next_;
	// 	}
	// 	return idx;
	// }

	public static int lastIdx(int[] arr, int idx, int data) {
		if (arr.length == idx) {
			return -1;
		}
		int recAns = lastIdx(arr, idx + 1, data);
		if (recAns != -1) {
			return recAns;
		}
		else {
			return (arr[idx] == data ? idx : -1);
		}
		// return  -1;
	} 

	public static int[] allIdx(int[] arr, int idx, int data, int count) {
		if (idx == arr.length) {
			int[] baseArr = new int[count];
			return baseArr;
		}
		if (arr[idx] == data) {
			count++;
		}
		int[] recAns = allIdx(arr, idx + 1, data, count);
		if (arr[idx] == data) {
			recAns[count - 1] = idx;
		}
		return recAns;
	}

}