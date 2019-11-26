//  creating the following pattern

// *   *
//  * * 
//   * 
//  * * 
// *   *

import java.util.Scanner;

public class crossPatt {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("enter the number of rows: ");
		int rows = scn.nextInt();

		for(int r = 1; r <= rows; r++) {
			for(int c =1; c <= rows; c++) {
				if ((r == c)||(r + c == rows + 1)) {
					System.out.print("*");
				}
				else {
					System.out.print(" ");
				}
			}
			System.out.println();
		}

	}
}