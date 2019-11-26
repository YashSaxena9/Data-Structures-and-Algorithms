//  printing given pattern
// 1						1C0
// 1 1						1C0 1C1
// 1 2 1					2C0 2C1 2C2
// 1 3 3 1					3C0 3C1 3C2 3C3
// 1 4 6 4 1				4C0 4C1 4C2 4C3 4C4
// 1 5 10 10 5 1			5C0 5C1 5C2 5C3 5C4 5C5

import java.util.Scanner;

public class pascalTriangle{
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int rows = scn.nextInt();

        for (int r = 0; r <= rows; r++) {
            
            int num = 1;
            
            for (int c = 0; c <= r; c++) {
                System.out.print(num + " ");
                num = (r - c)*num/(c + 1);
            }
            
            System.out.println();
        } 
    }
}