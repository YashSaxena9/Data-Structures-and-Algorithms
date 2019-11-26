import java.util.Scanner;
public class sieveAlgo {
    public static Scanner scn = new Scanner(System.in);

    public static void main(String[] args) {
        int limit = scn.nextInt();
        boolean[] arr = new boolean[limit + 1];
        sieve_allPrime(arr);
    }

    public static void sieve_allPrime(boolean[] arr) {
        for (int i = 2; i <= Math.sqrt(arr.length); i++) {
            if (!arr[i]) {
                int num = i;
                while (num < arr.length) {
                    num * 
                }
            }
        }
    }

}