//  print the given pattern

//    1
//   212
//  32123
// 4321234
//  32123
//   212
//    1

import java.util.Scanner;

public class pattDecDiamond {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		System.out.print("enter the number of rows: ");
		int rows = scn.nextInt();

		int nst = 1, nsp = rows / 2;
		for (int r = 1; r <= rows; r++) {
			for (int csp = 1; csp <= nsp; csp++) {
				System.out.print(" ");
			}
			int val = r;
			if (r > rows / 2) {
				val = (rows - r + 1);
			}
			for (int cst = 1; cst <= nst; cst++) {
				System.out.print(val);
				if (cst <= nst / 2) {
					val--;
				}
				else {
					val++;
				}

			}
			if (r <= rows / 2) {
				nsp--;
				nst += 2;
			}
			else {
				nsp++;
				nst -= 2;
			}
			System.out.println();
		}
	}
}