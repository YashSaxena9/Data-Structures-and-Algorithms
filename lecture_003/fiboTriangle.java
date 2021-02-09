// creating the given pattern

// 0
// 1 1
// 2 3 5
// 8 13 21 34

import java.util.Scanner;

public class fiboTriangle {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("enter the number of rows: ");
		int rows = scn.nextInt();
		int nst = 1,first = 0, second = 1, sum = 0;
		for (int r = 1; r <= rows; r++) {
			for (int cst = 1; cst <= nst; cst++) {
				System.out.print(first + " ");
				sum = first + second;
				first = second;
				second = sum;
			}
			nst++;
			System.out.println();
		}
	}
}