public class addSubArray {
	public static void main(String[] args) {
		int[] arr1 = {9,9,9,9};
		int[] arr2 = {1};
		addArr(arr1, arr2);
		System.out.println();
		subArr(arr1, arr2);
	}

	public static void display(int[] arr) {
		for (int i : arr) {
			System.out.print(i + " ");
		}
	}

	public static void addArr(int[] arr1, int[] arr2) {
		int carry = 0;
		int itr1 = arr1.length - 1;
		int itr2 = arr2.length - 1;
		int itr3 = arr1.length < arr2.length? arr2.length : arr1.length;
		int[] sum_ = new int[itr3 + 1];

		while (itr1 >= 0 && itr2 >= 0) {
			int ans = arr1[itr1] + arr2[itr2] + carry;
			int rem = ans % 10;
			carry = ans / 10;
			sum_[itr3] = rem;
			itr1--;
			itr2--;
			itr3--;
		}
		while (itr1 >= 0) {
			int ans = arr1[itr1] + carry;
			int rem = ans % 10;
			carry = ans / 10;
			sum_[itr3] = rem;
			itr1--;
			itr3--;
		}
		while (itr2 >= 0) {
			int ans = arr2[itr2] + carry;
			int rem = ans % 10;
			carry = ans / 10;
			sum_[itr3] = rem;
			itr2--;
			itr3--;
		}
		sum_[0] = carry;
		display(sum_);
	}

	public static void subArr(int[] arr1, int[] arr2) {
		int borrow = 0;
		int itr1 = arr1.length - 1;
		int itr2 = arr2.length - 1;
		int itr3 = arr1.length < arr2.length ? arr2.length : arr1.length;
		int[] sum_ = new int[itr3];

		while (itr1 >= 0 && itr2 >= 0) {
			int ans = arr1[itr1] - arr2[itr2] + borrow * 10;
			int rem = ans % 10;
			borrow = ans / 10;
			sum_[itr3] = rem;
			itr1--;
			itr2--;
			itr3--;
		}
	}
}
