package RatInMaze;
import java.util.Scanner;

public class ratInMaze {
    Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {
        // int[][] maze = new int[][] {
        //     {1, 0, 0, 0},
        //         {1, 1, 0, 1},
        //         {0, 1, 0, 0},
        //         {1, 1, 1, 1}
        // };
        int[][] maze = new int[4][4];
        // System.out.println(mazePath_noDiag(maze, 0, 0, ""));
        // System.out.println(mazePath_withDiag(maze, 0, 0, ""));
        System.out.println(mazePath_withDiag_multi(maze, 0, 0, ""));
    }

    public static int mazePath_noDiag(int[][] maze, int row, int col, String ans) {
        if (row == maze.length - 1 && col == maze[0].length - 1) {
            System.out.println(ans);
            return 1;
        }
        if (row >= maze.length || col >= maze[0].length) {
            return 0;
        }
        int count = 0;
        count += mazePath_noDiag(maze, row + 1, col, ans + "D");
        count += mazePath_noDiag(maze, row, col + 1, ans + "R");
        return count;
    }

    // ==============================================================
    boolean isSafe(int[][] maze, int r, int c) {
        if (r < 0 || c < 0 || r >= maze.length || c >= maze[0].length) {
            return false;
        }
        return true;
    }
    
    public static int mazePath_withDiag(int[][] maze, int row, int col, String ans) {
        if (row == maze.length - 1 && col == maze[0].length - 1) {
            System.out.println(ans);
            return 1;
        }
        if (row >= maze.length || col >= maze.length) {
            return 0;
        }
        int count = 0;
        count += mazePath_withDiag(maze, row + 1, col, ans + "S ");
        count += mazePath_withDiag(maze, row, col + 1, ans + "E ");
        count += mazePath_withDiag(maze, row + 1, col + 1, ans + "SE ");
        return count;
    }
    
    public static int mazePath_withDiag_multi(int[][] maze, int row, int col, String ans) {
        if (row == maze.length - 1 && col == maze[0].length - 1) {
            System.out.println(ans);
            return 1;
        }
        if (row >= maze.length || col >= maze.length) {
            return 0;
        }
        int count = 0;
        for (int i = 1; i < maze.length; i++) {
            count += mazePath_withDiag_multi(maze, row + i, col, ans + "S" + i + " ");
        }
        for (int j = 1; j < maze[0].length; j++) {
            count += mazePath_withDiag_multi(maze, row, col + j, ans + "E" + j + " ");
        }
        for (int i = 1, j = 1; i < maze.length && j < maze[0].length; i++, j++) {
            count += mazePath_withDiag_multi(maze, row + i, col + j, ans + "SE" + i + " ");
        }
        return count;
    }
}