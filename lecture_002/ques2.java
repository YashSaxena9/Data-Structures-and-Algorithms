// homework question //

//  print the given pattern

//    1
//   232
//  34543
// 4567654
//  34543
//   232
//    1

import java.util.Scanner;

public class ques2 {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("enter the number of rows: ");
		int rows;
		rows = scn.nextInt();
		int nst = 1, nsp = (rows / 2); // only to be seen int the first row
		// number of stars and number of spaces before stars

		for (int r = 1; r <= rows; r++) {
			for (int csp = 1; csp <= nsp; csp++) {
				System.out.print(" ");
			}
			int val;
			if (r <= rows / 2) {
				val = r;
			} else {
				val = rows - r + 1;
			}
			for (int cst = 1; cst <= nst; cst++) {
				System.out.print(val);
				if (cst <= nst / 2) {
					val++;
				} else {
					val--;
				}
			}
			if (r <= rows / 2) {
				nsp--;
				nst += 2;
			} else {
				nsp++;
				nst -= 2;
			}
			System.out.println();
		}
	}
}
