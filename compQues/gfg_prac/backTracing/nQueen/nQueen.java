import java.util.Scanner;
/**
 * nQueen
 */
public class nQueen {
    Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {
        boolean[][] arr = new boolean[8][8];
        System.out.println(nQueen_sol(arr, 0, 8, ""));
    }
    
    public static boolean isSafe(boolean[][] arr, int r, int c) {
        int[] dir_r = {1,-1,1,-1,0,0,1,-1};
        int[] dir_c = {0,0,-1,1,1,-1,1,-1};
        for (int i = 0; i < dir_r.length; i++) {
            for (int rad = 0; rad < Math.max(arr.length, arr[0].length); rad++) {
                int x = r + rad * dir_r[i];
                int y = c + rad * dir_c[i];
                if (x < 0 || y < 0 || x >= arr.length || y >= arr[0].length) {
                    break;
                }
                if (arr[x][y]) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void display(boolean[][] arr) {
        for (boolean[] ar : arr) {
            for (boolean a : ar) {
                String ans = (a) ? "Q" : ".";
                System.out.print(ans + " ");
            }
            System.out.println();
        }
        System.out.println("\n***********************\n");
    }

    public static int nQueen_sol(boolean[][] board, int vidx, int tnq, String ans) {
        if (tnq == 0) {
            // System.out.println(ans);
            display(board);
            return 1;
        }
        int count = 0;
        for (int i = vidx; i < board.length * board[0].length; i++) {
            int r = i / board[0].length;
            int c = i % board[0].length;
            if (isSafe(board, r, c)) {
                board[r][c] = true;
                count += nQueen_sol(board, i + 1, tnq - 1, ans + "(" + r + ", "+ c + ") ");
                board[r][c] = false;
            }
        }
        return count;
    }
}