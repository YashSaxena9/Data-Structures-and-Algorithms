//  find the missing pair int the array

import java.util.Scanner;

/**
 * shoePair
 */
public class shoePair {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		int[] arr = {1,1,2,2,3,3,4,4,5,5,7,8,8,9,9,10,10,15,15};
		System.out.println(shoePair(arr));
	}

	public static int shoePair(int[] arr) {
		if (arr.length % 2 == 0) {
			System.out.println("all paired");
			return -1;
		}
		int si = 0, ei = arr.length - 1;
		while (si <= ei) {
			int mid = (si + ei) / 2;
			if (si == ei) {
				return mid;
			}
			else if (mid % 2 == 0 && arr[mid] == arr[mid + 1]) {
				si = mid + 1;
			}
			else if (mid % 2 == 1 && arr[mid] == arr[mid - 1]) {
				si = mid + 1;
			}
			else {
				ei = mid - 1;
			}
		}
		return -1;
	}
}
