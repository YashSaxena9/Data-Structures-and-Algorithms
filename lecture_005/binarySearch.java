


//  binary search

import java.util.Scanner;

public class binarySearch {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		int[] arr = new int[10];
		input(arr);
		int var = scn.nextInt();
		System.out.println(binSearch(arr, var));
		System.out.println(upperBinSearch(arr, var));
		System.out.println(lowerBinSearch(arr, var));
	}


	public static void input(int[] arr) {
		for (int i = 0; i < arr.length; i++) {
			arr[i] = scn.nextInt();
		}
	}

	//  binary search
	public static int binSearch(int[] arr, int var) {
		int upperBound = 0;					//  starting index
		int lowerBound = arr.length;		//  ending index
		while(lowerBound > upperBound) {
			int middle = (upperBound + lowerBound)/2;
			if (arr[middle] == var) {
				return middle;
			}
			else if (arr[middle] < var) {
				upperBound = middle + 1;
			}
			else if (arr[middle] > var) {
				lowerBound = middle - 1;
			}
		}

		if(lowerBound == -1){
			return upperBound;
		}
		else if(upperBound == arr.length) {
			return lowerBound;
		}
		else if (var - arr[lowerBound] <= arr[upperBound] - var){
			return lowerBound;
		}
		return -1;		//  element doesn't exist
	}

	//  upper bound binary search
	public static int upperBinSearch(int[] arr, int var) {
		int upperBound = 0;					//  starting index
		int lowerBound = arr.length - 1;		//  ending index
		while(lowerBound > upperBound) {
			int middle = (upperBound + lowerBound)/2;
			if (arr[middle] == var) {
				if (middle + 1 < arr.length && arr[middle + 1] == arr[middle]) {
					upperBound = middle + 1;
				}
				else{
					return middle;
				}
			}
			else if (arr[middle] < var) {
				upperBound = middle + 1;
			}
			else if (arr[middle] > var) {
				lowerBound = middle - 1;
			}
		}
		return -1;		//  element doesn't exist
	}

	// lower bound binary search
	public static int lowerBinSearch(int[] arr, int var) {
		int upperBound = 0; // starting index
		int lowerBound = arr.length - 1; // ending index
		while (lowerBound >= upperBound) {
			int middle = (upperBound + lowerBound) / 2;
			if (arr[middle] == var) {
				if (middle - 1 >= 0 && arr[middle - 1] == arr[middle]) {
					lowerBound = middle - 1;
				}
				else {
					return middle;
				}
			} else if (arr[middle] < var) {
				upperBound = middle + 1;
			} else if (arr[middle] > var) {
				lowerBound = middle - 1;
			}
		}
		return -1; // element doesn't exist
	}
	
}