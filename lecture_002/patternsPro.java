import java.util.Scanner;

public class patternsPro {
	public static void main(String[] args) {
		Scanner scn = new Scanner(System.in);
		
		
		// /*
		// // pattern 1
		// // *
		// // **
		// // ***
		// // ****
		// // *****

		// System.out.print("enter the number of rows: ");
		// int rows1;
		// rows1 = scn.nextInt();
		// int nst = 1, nsp = 0; // only to be seen int the first row
		// // number of stars and number of spaces before stars

		// for(int r = 1; r<=rows1; r++) {
		// 	/* this loop is not required as there are no spaces before stars */
		// 	// for(int csp = 1; csp<=nsp; csp++) {
		// 	// System.out.print(" ");
		// 	// }

		// 	for(int cst = 1; cst<=nst; cst++) {
		// 		System.out.print("*");
		// 	}
		// 	/* this is not required as nsp(number of spaces before stars is already 0) */
		// 	// nsp--;
		// 	nst++;
		// 	System.out.println();
		// }
		// */
		




		// /*
		// // pattern 2
		// // *
		// // **
		// // ***
		// // ****
		// // *****

		// System.out.print("enter the number of rows: ");
		// int rows2;
		// rows2 = scn.nextInt();
		// int nst = 1, nsp = rows2 - 1; // only to be seen int the first row
		// // number of stars and number of spaces before stars

		// for (int r = 1; r <= rows2; r++) {
		// 	for(int csp = 1; csp <= nsp; csp++) {
		// 		System.out.print(" ");
		// 	}

		// 	for (int cst = 1; cst <= nst; cst++) {
		// 		System.out.print("*");
		// 	}

		// 	nsp--;
		// 	nst++;
		// 	System.out.println();
		// }
		// */





		// pattern 3
		// 	 *
		// 	***
		// *****
		//  ***
		//   *

		System.out.print("enter the number of rows: ");
		int rows3;
		rows3 = scn.nextInt();
		int nst = 1, nsp = (rows3 / 2); // only to be seen int the first row
		// number of stars and number of spaces before stars

		for(int r = 1; r<=rows3; r++) {
			for(int csp = 1; csp<=nsp; csp++) {
				System.out.print(" ");
			}

			for(int cst = 1; cst<=nst; cst++) {
				System.out.print("*");
			}
			if (r <= rows3 / 2) {
				nsp--;
				nst += 2;
			}else {
				nsp++;
				nst -= 2;
			}

			System.out.println();
		}
		
	}
}