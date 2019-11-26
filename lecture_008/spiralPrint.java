//  print in spiral like iteration
// matrix =  1  2  3  4
// 	    	 5  6  7  8
//  		 9 10 11 12
//  		13 14 15 16

// output =  1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10

/**
 * spiralPrint
 */
import java.util.Scanner;

public class spiralPrint {

	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {

		int row = scn.nextInt();
		int col = scn.nextInt();
		int[][] arr = new int[row][col];
		input(arr);
		System.out.println();
		display_spiral_H(arr);		
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
	
	public static void display_spiral_H(int[][] arr) {
		int minrow = 0, mincol = 0;
		int maxrow = arr.length - 1, maxcol = arr.length - 1;
		int tot_ele = arr.length * arr[0].length, count = 0;
		while (count < tot_ele) {
			for (int col = mincol; col <= maxcol && count < tot_ele; col++) {
				System.out.print(arr[minrow][col] + " ");
				count++;
			}
			minrow++;
			
			for (int row = minrow; row <= maxrow && count < tot_ele; row++) {
				System.out.print(arr[row][maxcol] + " ");
				count++;
			}
			maxcol--;
			
			for (int col = maxcol; col >= mincol && count < tot_ele; col--) {
				System.out.print(arr[maxrow][col] + " ");
				count++;
			}
			maxrow--;

			for (int row = maxrow; row >= minrow && count < tot_ele; row--) {
				System.out.print(arr[row][mincol] + " ");
				count++;
			}
			mincol++;
		}
		System.out.println();
	}
	
	public static void display_spiral_V(int[][] arr) {
		int minrow = 0, mincol = 0;
		int maxrow = arr.length - 1, maxcol = arr.length - 1;
		int tot_ele = arr.length * arr[0].length, count = 0;
		while (count < tot_ele) {
			for (int row = minrow; row <= maxrow && count < tot_ele; row++) {
				System.out.print(arr[row][mincol] + " ");
				count++;
			}
			mincol++;

			for (int col = mincol; col <= maxcol && count < tot_ele; col++) {
				System.out.print(arr[maxrow][col] + " ");
				count++;
			}
			maxrow--;	

			for (int row = maxrow; row >= minrow && count < tot_ele; row--) {
				System.out.print(arr[row][maxcol] + " ");
				count++;
			}
			maxcol--;

			for (int col = maxcol; col >= mincol && count < tot_ele; col--) {
				System.out.print(arr[minrow][col] + " ");
				count++;
			}
			minrow++;
		}
		System.out.println();
	}

}