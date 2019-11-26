//  create a program to do simple mathematics
//  adding matrices

import java.util.Scanner;

public class matrixMath {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		int row1 = 0, col1 = 0;
		int row2 = 0, col2 = 0;
		row1 = scn.nextInt();
		col1 = scn.nextInt();
		row2 = scn.nextInt();
		col2 = scn.nextInt();
		int[][] mat1 = new int[row1][col1];
		int[][] mat2 = new int[row2][col2];
		
		input(mat1);
		System.out.println();
		input(mat2);
		System.out.println(" mul: ");		
		int[][] mulMat_ = mul_(mat1, mat2);
		display(mulMat_);
	}

	public static void input(int[][] matrix) {
		for (int r = 0; r < matrix.length; r++) {
			for (int c = 0; c < matrix[0].length; c++) {
				matrix[r][c] = scn.nextInt();
			}
		}
	}

	public static void display(int[][] matrix) {
		for (int[] arr : matrix) {
			for (int ar : arr) {
				System.out.print(ar + " ");
			}
			System.out.println();
		}
	}
	
	public static int[][] sum_(int[][] mat1, int[][] mat2) {
		int[][] sumMat_ = new int[mat1.length][mat1[0].length];
		for (int r = 0; r < mat1.length; r++) {
			for (int c = 0; c < mat1[0].length; c++) {
				sumMat_[r][c] = mat1[r][c] + mat2[r][c];
			}
		}
		return sumMat_;
	}

	public static int[][] mul_(int[][] mat1, int[][] mat2) {
		int[][] mulMat_ = new int[mat1.length][mat2[0].length];
		if (mat1[0].length == mat2.length) {
			for (int r = 0; r < mulMat_.length; r++) {
				for (int c = 0; c < mulMat_[0].length; c++) {
					for (int val = 0; val < mat1[0].length; val++) {
						mulMat_[r][c] += mat1[r][val] * mat2[val][c];
					}
				}
			}
			return mulMat_;
		}
		return mulMat_;
	}
}