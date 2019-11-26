//  print in wave like iteration
// matrix =  1  2  3  4
// 	    	 5  6  7  8
//  		 9 10 11 12
//  		13 14 15 16

// output =  1 2 3 4 8 7 6 5 9 10 11 12 16 15 14 13

/**
 * wavePrint
 */
import java.util.Scanner;

public class wavePrint {

	public static Scanner scn = new Scanner(System.in);
	public static void main(String[] args) {

		int row = scn.nextInt();
		int col = scn.nextInt();
		int[][] arr = new int[row][col];
		input(arr);
		System.out.println();
		display_V_Wave(arr);		
	}

	public static void input(int[][] arr) {
		for (int row = 0; row < arr.length; row++) {
			for (int col = 0; col < arr[0].length; col++) {
				arr[row][col] = scn.nextInt();
			}
		}
	}

	public static void display(int[][] arr) {
		for (int[] i : arr) {
			for (int j : i) {
				System.out.print(j + " ");
			}
			System.out.println();
		}
	}

	public static void display_H_Wave(int[][] arr) {
		for (int row = 0; row < arr.length; row++) {
			if (row % 2 == 0) {
				for (int col = 0; col < arr[0].length; col++) {
					System.out.print(arr[row][col] + " ");
				}
			}
			if (row % 2 == 1) {
				for (int col = arr[0].length - 1; col >= 0; col--) {
					System.out.print(arr[row][col] + " ");
				}
			}
		}
		System.out.println();
	}

	public static void display_V_Wave(int[][] arr) {
		for (int col = 0; col < arr[0].length; col++) {
			if (col % 2 == 0) {
				for (int row = 0; row < arr.length; row++) {
					System.out.print(arr[row][col] + " ");
				}
			}
			if (col % 2 == 1) {
				for (int row = arr.length - 1; row >= 0; row--) {
					System.out.print(arr[row][col] + " ");
				}
			}
		}
		System.out.println();
	}
}