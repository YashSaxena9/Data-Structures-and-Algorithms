//  finding all prime numbers upto given limit
//  in complexity O( n^2), O( n * n/2) and O( n * sq.root(n))

import java.util.Scanner;
/**
 * primeNumber
 */
public class primeNumber {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		System.out.print("enter the limit: ");
		int lim = scn.nextInt();
		for (int i = 1; i <= lim; i++) {
			isPrime3(i);
		}
		System.out.println();
	}


	//  O( n^2) complexity
	public static void isPrime1(int num) {
		int count = 0
		for (int i = 2; i < num; i++) {
			if (num % i == 0) {
				count++;
				break;
			}
		}
		if (count == 0) {
			System.out.print(num + " ");
		}
	}


	//  O( n * n/2) complexity
	public static void isPrime2(int num) {
		int count = 0;
		for (int i = 2; i <= num/2; i++) {
			if (num % i == 0) {
				count++;
				break;
			}
		}
		if (count == 0) {
			System.out.print(num + " ");
		}
	}


	//  O( n * sq.root(n)) complexity
	public static void isPrime3(int num) {
		int count = 0;
		for (int i = 2; i*i <= num; i++) {
			if (num % i == 0) {
				count++;
				break;
			}
		}
		if (count == 0) {
			System.out.print(num + " ");
		}
	}
} 