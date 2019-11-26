//  basics of recursion
//  mathematical induction is used

import java.util.Scanner;

public class recursion_basic {
	public static Scanner scn = new Scanner(System.in);
	public static void main(String[] args) {
		int num = scn.nextInt();
		solve(num);
	}
	
	/* __________ solve __________ */
	public static void solve(int num) {
		//  calling functions
		// System.out.println("increasing:");
		// increasing_(1, num);
		
		// System.out.println("decreasing_:");
		// decreasing_(1, num);
		
		System.out.println("increasing then decreasing:");
		inc_dec(1, num);
		
		System.out.println("first odd then even:");
		odd_even(1, num);
	}
	
	/* __________ increasing order numbers __________ */
	public static void increasing_(int start, int end) {
		if (start > end)	return;				//  checking invalid condition
		
		increasing_(start, end - 1);				//  faith	//  function calling itself
		
		System.out.println(end);				//  handling last case
	}

	/* __________ decreasing order numbers __________ */
	public static void decreasing_(int start, int end) {
		if (start > end)	return;				//  checking invalid condition
		
		System.out.println(end);				//  handling last case
		
		decreasing_(start, end - 1);				//  faith	//  function calling itself
	}

	/* __________ increasing and then decreasing __________ */
	public static void inc_dec(int start, int end) {
		if (start == end) {				//  checking invalid condition
			System.out.println(start);
			return;
		}
		
		System.out.println(start);
		
		inc_dec(start + 1, end);				//  faith	//  function calling itself
		
		System.out.println(start);
	}
	
	/*
	public static void inc_dec(int start, int end) {
		if (start > end)	return;				//  checking invalid condition
		
		System.out.println(start);
		
		inc_dec(start + 1, end);				//  faith	//  function calling itself

		if (start != end) {
			System.out.println(start);
		}
	}
	*/

	/* __________ odd increasing and then even decreasing __________ */
	public static void odd_even(int start, int end) {
		// if (start > end)			return;
		if (start == end) { // checking invalid condition
			System.out.println(start);
			return;
		}
		
		if (start % 2 == 1) {
			System.out.println(start);
		}
		
		odd_even(start + 1, end);
		
		if (start % 2 == 0) {
			System.out.println(start);
		}
	}

	/* __________ odd decreasing __________ */
	public static void odd_(int start, int end) {
		if (start > end)	return;				//  checking invalid condition
		
		odd_(start, end - 1);					// faith // function calling itself
		
		if (end % 2 == 1) {
			System.out.println(end);			//  handling last case
		}
	}

	/* __________ even decreasing __________ */
	public static void even_(int start, int end) {
		if (start > end)	return;				//  checking invalid condition
		
		if (end % 2 == 0) {
			System.out.println(end);			//  handling last case
		}
		
		even_(start, end - 1);					// faith // function calling itself
	}

}