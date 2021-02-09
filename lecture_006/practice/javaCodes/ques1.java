// in an array , if the frequency of an elements occurence is greater than size/2 (freq. > size/2) then print that number in O(n) time complexity

// array = [2,2,2,3,3,5,2,6,7,2]
// in interview of Wheelsi

// make in 2 functions

/**
 * ques1
 */
public class ques1 {

	public static void main(String[] args) {
		int[] arr = { 3, 3, 4, 2, 4, 4, 2, 4, 4, 3, 4, 4};
		// input(arr);
		int data = findPotenial(arr);
		if (checkPotential(arr, data)) {
			System.out.println(" solution is :" + data);
		}
		else {
			System.out.println("no solution");
		}

	}

	public static int findPotenial(int[] arr) {
		//  finding potential solution suspects
		int count = 1, suspect = arr[0];
		for (int i = 1; i < arr.length; i++) {
			if (arr[i] == arr[i - 1]) {
				count++;
			}
			else {
				count--;
			}
			if (count == 0) {
				suspect = arr[i];
				count++;
			}
		}
		return suspect;
	}

	public static boolean checkPotential(int[] arr, int data) {
		//  iterating again to count potenial solution data occurence
		int count = 0;
		for(int i : arr) {
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