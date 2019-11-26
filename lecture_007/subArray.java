//  find all subarrays

import java.util.Scanner;
/**
 * subArray
 */
public class subArray {

	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		// int[] arr = new int[10];
		int[] arr = {1,2,3,4,5,6,7,8};
		subStr(arr);

	}

	public static void subStr(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			for (int j = i; j < arr.length; j++) {
				for (int k = i; k <= j; k++) {
					System.out.print(arr[k] + " ");
				}
				System.out.println();
			}
		}
	}
}

/*
	#  Output
1 
1 2 
1 2 3 
1 2 3 4 
1 2 3 4 5 
1 2 3 4 5 6 
1 2 3 4 5 6 7 
1 2 3 4 5 6 7 8 
2 
2 3 
2 3 4 
2 3 4 5 
2 3 4 5 6 
2 3 4 5 6 7 
2 3 4 5 6 7 8 
3 
3 4 
3 4 5 
3 4 5 6 
3 4 5 6 7 
3 4 5 6 7 8 
4 
4 5 
4 5 6 
4 5 6 7 
4 5 6 7 8 
5 
5 6 
5 6 7 
5 6 7 8 
6 
6 7 
6 7 8 
7 
7 8 
8 

*/