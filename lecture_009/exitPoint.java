//  in an array of 0 and 1 , we enter horizontally from [0,0] at every encounter of 1, we change direction by 90deg. clokwise
//  the point when we exit matrix that last value of matrix is the exit point...print it

import java.util.Scanner;
import java.util.ArrayList;

/**
 * exitPoint
 */
public class exitPoint {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		int[][] mat_ = {
			{0,0,0,0,1},
			{1,0,0,1,0},
			{0,0,0,0,0},
			{0,1,0,1,0},
			{1,0,0,0,1}
		};
		exitPoint(mat_);
	}

	public static void exitPoint(int[][] mat_) {
		int dir_ = 0;
		int row = 0, col = 0;
		System.out.println("exit point is :");
		while (true) {
			dir_ = (dir_ + mat_[row][col]) % 4;
			if (dir_ == 0) {
				col++;
				if (col == mat_[0].length) {
					System.out.println("row: " + row + ", col: " + (col - 1));
					return;
				}
			}
			else if (dir_ == 1) {
				row++;
				if (row == mat_.length) {
					System.out.println("row: " + (row - 1) + ", col: " + col);
					return;
				}
			}
			else if (dir_ == 2) {
				col--;
				if (col == -1) {
					System.out.println("row: " + row + ", col: " + (col + 1));
					return;
				}
			}
			else {
				row--;
				if (row == -1) {
					System.out.println("row: " + (row + 1) + ", col: " + col);
					return;
				}
			}
		}
	}
}