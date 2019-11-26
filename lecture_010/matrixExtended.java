//  iterate matrix diagonally and orint upper triangle
//  transverse the matrix

/**
 * matrixExtended
 */
import java.util.Scanner;

public class matrixExtended {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		char[][] arr = {{'a','b','c','d'},
						{'e','f','g','h'},
						{'i','j','k','l'},
						{'m','n','o','p'}};
		printDiag(arr);
		System.out.println();
		rotate90_clockwise(arr);
		display(arr);
	}

	public static void printDiag(char[][] arr) {
		for (int gap = 0; gap < arr[0].length; gap++) {
			for (int row = 0, col = gap; row < arr.length && col < arr[0].length; row++, col++) {
				System.out.print(arr[row][col] + " ");
			}
			System.out.println();
		}
	}

	public static void display(char[][] arr) {
		for (char[] ar : arr) {
			for (char c : ar) {
				System.out.print(c + " ");
			}
			System.out.println();
		}
	}
	
	public static void transMat(char[][] arr) {
		for (int r = 0; r < arr.length; r++) {
			for (int c = r; c < arr[0].length; c++) {
				char temp = arr[r][c];
				arr[r][c] = arr[c][r];
				arr[c][r] = temp;
			}
		}
	}

	public static void rotate90_clockwise(char[][] arr) {
		transMat(arr);
		int c1 = 0, c2 = arr[0].length - 1;
		while (c1 < c2) {
			for (int r = 0; r < arr.length; r++) {
				char temp = arr[r][c1];
				arr[r][c1] = arr[r][c2];
				arr[r][c2] = temp;
			}
			c1++;
			c2--;
		}
	}
}