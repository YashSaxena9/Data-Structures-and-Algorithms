// making and learning about multi dimentional arrays ( /matrices)

/**
 * multiDimArray
 */
import java.util.Scanner;

public class multiDimArray {

	public static Scanner scn = new Scanner(System.in);
	public static void main(String[] args) {
		
		/*
			//  3D array of size (n * m * p)
			int[][][] arr = new int[n][m][p];
		*/

		//  2D array
		int row = scn.nextInt();
		int col = scn.nextInt();
		int[][] arr = new int[row][col];
		input(arr);
		System.out.println();
		System.out.println(max_(arr));
		display(arr);
		System.out.println();
		System.out.print("enter data to find: ");
		int data = scn.nextInt();
		System.out.println(find(arr, data));
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

	public static boolean find(int[][] arr, int data) {
		for (int[] ar : arr) {
			for (int i : ar) {
				if (i == data) {
					return true;
				}
			}
		}
		return false;
	}

	public static int max_(int[][] arr) {
		int temp = arr[0][0];
		for (int[] ar : arr) {
			for (int i : ar) {
				if (temp < i) {
					temp = i;
				}
			}
		}
		return temp;
	}

	public static int min_(int[][] arr) {
		int temp = arr[0][0];
		for (int[] ar : arr) {
			for (int i : ar) {
				if (temp > i) {
					temp = i;
				}
			}
		}
		return temp;
	}

}