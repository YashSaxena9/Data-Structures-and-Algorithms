import java.util.Scanner;

public class hollowDiamond {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        // *******
        // *** ***
        // **   **
        // *     *
        // **   **
        // *** ***
        // *******

        System.out.print("enter the number of rows: ");
        int rows3;
        rows3 = scn.nextInt();
        int nst = 1, nsp = (rows3 / 2); // only to be seen int the first row
        // number of stars and number of spaces before stars

        for (int r = 1; r <= rows3 - 2; r++) {              //  remove - 2 to remove borders  //
            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print("*");
            }

            for (int cst = 1; cst <= nst; cst++) {
                System.out.print(" ");
            }

            for (int csp = 1; csp <= nsp; csp++) {
                System.out.print("*");
            }
            if (r <= (rows3 / 2) - 1) {                    //  remove - 1 for no side borders  //
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