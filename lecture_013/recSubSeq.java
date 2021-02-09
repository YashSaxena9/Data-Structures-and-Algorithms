//  string and arrayList questions

import java.util.Scanner;
import java.util.ArrayList;

public class recSubSeq {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		solve();
	}

	public static void solve() {
		// basic();
		// permInit_();
		// mergePathCall();
		mergePathProCall();
	}

	/*  _______________ basic _______________  */
	public static void basic() {
		System.out.println(subSeq("1234"));
	}

	public static ArrayList<String> subSeq(String str) {
		if (str.length() == 0) {
			ArrayList<String> base = new ArrayList<>();
			base.add("");
			return base;
		}
		
		char ch = str.charAt(0);
		String restStr = str.substring(1);
		ArrayList<String> recAns = subSeq(restStr);
		ArrayList<String> ans = new ArrayList<>();

		for (String s : recAns) {
			ans.add(s);					//  not adding char
			ans.add(ch + s);			//  adding char 
		}
		return ans;
	}

	/*  _______________ permutations _______________  */
	public static void permInit_() {
		System.out.println(perm_("123"));
	}
	
	public static ArrayList<String> perm_(String str) {
		if (str.length() == 0) {
			ArrayList<String> base = new ArrayList<>();
			base.add("");
			return base;
		}
		
		char ch = str.charAt(0);
		String restStr = str.substring(1);
		ArrayList<String> recAns = perm_(restStr);
		ArrayList<String> ans = new ArrayList<>();

		for (String s : recAns) {
			for (int i = 0; i <= s.length(); i++) {
				String before = s.substring(0, i);
				String after = s.substring(i);
				String fin_ = before + ch + after;
				ans.add(fin_);
			}
		}
		return ans;
	}

	/*  _______________ start to stop on board(H, V) _______________  */
	public static void mergePathCall() {
		System.out.println(mergePath(0, 0, 2, 2));
	}

	public static ArrayList<String> mergePath(int si, int ei, int sp, int ep) {
		if (si == sp && ei == ep) {
			ArrayList<String> base = new ArrayList<>();
			base.add("");
			return base;
		}

		ArrayList<String> myAns = new ArrayList<>();

		if (ei + 1 <= ep) {
			ArrayList<String> hRecAns = mergePath(si, ei + 1, sp, ep);
			for (String str : hRecAns) {
				myAns.add("H" + str);
			}
		}

		if (si + 1 <= sp) {
			ArrayList<String> vRecAns = mergePath(si + 1, ei, sp, ep);
			for (String str : vRecAns) {
				myAns.add("V" + str);
			}
		}
		return myAns;
	}

	/*  _______________ start to stop on board(H, V, D) _______________  */
	public static void mergePathProCall() {
		System.out.println(mergePathPro(0, 0, 2, 2));
	}

	public static ArrayList<String> mergePathPro(int si, int ei, int sp, int ep) {
		if (si == sp && ei == ep) {
			ArrayList<String> base = new ArrayList<>();
			base.add("");
			return base;
		}

		ArrayList<String> myAns = new ArrayList<>();

		if (ei + 1 <= ep) {
			ArrayList<String> hRecAns = mergePathPro(si, ei + 1, sp, ep);
			for (String str : hRecAns) {
				myAns.add("H" + str);
			}
		}

		if (ei + 1 <= ep && si + 1 <= sp) {
			ArrayList<String> DRecAns = mergePathPro(si + 1, ei + 1, sp, ep);
			for (String str : DRecAns) {
				myAns.add("D" + str);
			}
		}

		if (si + 1 <= sp) {
			ArrayList<String> vRecAns = mergePathPro(si + 1, ei, sp, ep);
			for (String str : vRecAns) {
				myAns.add("V" + str);
			}
		}
		return myAns;
	}
}