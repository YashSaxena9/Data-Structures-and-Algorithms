// assume 2 arrays are given , add them and subtract them in a third array without converting them to actual numbers
// pure array addition and subtraction
http://marketplace.eclipse.org/marketplace-client-intro?mpc_install=1403812
import java.util.Scanner;

public class arrayAddSub {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		int[] arr1 = {1,0,0,0,0};
		int[] arr2 = {9,9,9,9};
		// addByArray(arr1, arr2);
		subByArray(arr1, arr2);
	}

	public static void display(int[] arr) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}

	/* addition */
	public static void addByArray(int[] arr1, int[] arr2) {
		int itr3 = arr1.length < arr2.length? arr2.length : arr1.length;
		int[] sumArr = new int[itr3 + 1];
		int itr2 = arr2.length - 1;
		int itr1 = arr1.length - 1;
		int carry = 0;
		
		while (itr1 >= 0 || itr2 >= 0 || carry != 0) {
			int ans = carry;
			if (itr1 >= 0) ans += arr1[itr1];
			if (itr2 >= 0) ans += arr2[itr2];
			int rem = ans % 10;
			carry = ans / 10;
			sumArr[itr3] = rem;
			itr1--;
			itr2--;
			itr3--;
		}
		
		display(sumArr);
	}

	public static int arrToNum(int[] arr) {
		int itr = arr.length - 1;
		int num = arr[itr];
		while (itr > 0) {
			num = num*10 + arr[itr];
			itr--;
		}
		return num;
	}

	public static int[] numToArr(int num, int arrSize) {
		int[] numArr = new int[arrSize];
		for (int i = arrSize - 1; i >= 0; i--) {
			numArr[i] = num % 10;
			num /= 10;
		}
		return numArr;
	}

	public static void addByNumber(int[] arr1, int[] arr2) {
		int num1 = arrToNum(arr1);
		int num2 = arrToNum(arr2);
		int sum_ = num1 + num2;
		int[] sumArr = numToArr(sum_, arr1.length < arr2.length? arr2.length + 1: arr1.length + 1);
		display(sumArr);
	}

	/* subtraction */
	public static void subByArray(int[] arr1, int[] arr2) {
		int itr3 = arr1.length < arr2.length? arr2.length : arr1.length;
		int[] sumArr = new int[itr3];
		int itr2 = arr2.length - 1;
		int itr1 = arr1.length - 1;
		int borrow = 0;
		
		while (itr1 >= 0 || itr2 >= 0) {
			int ans = borrow;
			borrow = 0;
			if (itr1 >= 0) ans += arr1[itr1];
			if (itr2 >= 0) ans -= arr2[itr2];
			if (ans < 0) {
				ans += 10;
				borrow = -1;
			}
			sumArr[itr3 - 1] = ans;
			itr1--;
			itr2--;
			itr3--;
		}
		
		display(sumArr);
	}
}