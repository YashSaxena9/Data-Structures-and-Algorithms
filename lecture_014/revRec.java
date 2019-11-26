import java.util.Scanner;
import java.util.ArrayList;

/**
 * revRec
 */
public class revRec {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		solve();
	}

	public static void solve() {
		/*
			System.out.println(printSpaceString("abc"));
			//  output = [a_b_c, a_bc, ab_c, abc]
		*/

		/*
		System.out.println(printAllBinary(3));
		//  [000, 001, 010, 011, 100, 101, 110, 111]
		*/
	}

	/* _______________ print string with spaces at every cut _______________ */
	public static ArrayList<String> printSpaceString(String str) {
		if (str.length() == 0) {
			ArrayList<String> base = new ArrayList<>();
			base.add("");
			return base;
		}
		String restStr = str.substring(0, str.length() - 1);
		char end = str.charAt(str.length() - 1);
		ArrayList<String> recAns = printSpaceString(restStr);
		ArrayList<String> myAns = new ArrayList<>();
		for (String s : recAns) {
			if (s != "") {
				myAns.add(s + "_" + end);
			}
			myAns.add(s + end);	
		}
		return myAns;
	}

	/* _______________ print all possible binary numbers under given digits _______________ */
	public static ArrayList<String> printAllBinary(int num) {
		if (num == 0) {
			ArrayList<String> base = new ArrayList<>();
			base.add("");
			return base;
		}
		ArrayList<String> recAns = printAllBinary(num - 1);
		ArrayList<String> myAns = new ArrayList<>();
		for (String str : recAns) {
			myAns.add(str + "0");
			myAns.add(str + "1");
		}
		return myAns;
	}
}