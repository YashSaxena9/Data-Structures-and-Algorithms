//  multiple loops in horizontal , vertical and diagonal directions are possible

import java.util.ArrayList;
import java.util.Scanner;

/**
 * mazePathPlus
 */
public class mazePathPlus {
	public static Scanner scn = new Scanner(System.in);

	public static void main(String[] args) {
		solve();
	}
	
	//  __________ solve __________  //
	public static void solve() {
		// System.out.println(mazePathPlus(0, 0, 2, 2));
		System.out.println(boardPath(0, 10).size());
	}

	//  __________ maze path problem with multiple moves __________  //
	public static ArrayList<String> mazePathPlus(int sr, int sc, int er, int ec) {
		if (sr == er && sc == ec) {
			ArrayList<String> base = new ArrayList<>();
			base.add("");
			return base;
		}
		ArrayList<String> ans = new ArrayList<>();
		for (int i = 1; i <= ec; i++) {
			if (sc + i <= ec) {
				ArrayList<String> horiRecAns = mazePathPlus(sr, sc + i, er, ec);
				for (String s : horiRecAns) {
					ans.add("H" + i + s);
				}
			}
		}
		for (int i = 1; i <= er; i++) {
			if (sr + i <= er) {
				ArrayList<String> vertRecAns = mazePathPlus(sr + i, sc, er, ec);
				for (String s : vertRecAns) {
					ans.add("V" + i + s);
				}
			}
		}
		for (int i = 1; i <= er || i <= ec; i++) {
			if (sr + i <= er && sc + i <= ec) {
				ArrayList<String> diagRecAns = mazePathPlus(sr + i, sc + i, er, ec);
				for (String s : diagRecAns) {
					ans.add("D" + i + s);
				}
			}
		}
		return ans;
	}

	//  __________ find all permutations in ludo to make sum 10 __________  //
	public static ArrayList<String> boardPath(int si, int ei) {
		if (si == ei) {
			ArrayList<String> base = new ArrayList<>();
			base.add("");
			return base;
		}
		ArrayList<String> ans = new ArrayList<>();
		for (int i = 1; si + i <= ei && i <= 6; i++) {
			ArrayList<String> recAns = boardPath(si + i, ei);
			for (String s : recAns) {
				ans.add(s + i);
			}
		}
		return ans;
	}
}