//  in an array , if the frequency of an elements occurence is greater than size/2 (freq. > size/2) then print that number in O(n) time complexity

//  array = [2,2,2,3,3,5,2,6,7,2]
//  in interview of Wheelsi

//  make in 2 functions

/**
 * ques1
 */
public class ques1 {

	public static void main(String[] args) {
		int[] arr = {3,3,4,2,4,4,2,4,4};
		int data = isPotential(arr);
		if (isReallyAns(arr, data)) {
			System.out.println("solution is: " + data);
		}
		else {
			System.out.println(-1);
		}
		
	}

	public static int isPotential(int[] arr) {
		int suspect = arr[0];
		int count = 1;
		// to check potential solution
		for (int i = 1; i < arr.length; i++) { // i = 1 as we suspect first element as potential solution
			if (suspect == arr[i]) {
				count++;
			}
			else {
				count--;
			}

			if (count == 0) {
				suspect = arr[i];
				count = 1;
			}
		}
		return suspect;
	}

	public static boolean isReallyAns(int[] arr, int data) {
		int count = 0;

		// to verify potential solution
		// data = suspect
		for (int i : arr) {
			if (i == data) {
				count++;
			}
		}

		if (count > arr.length / 2) {
			return true;
		}
		return false;
	}
}