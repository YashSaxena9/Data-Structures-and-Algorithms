//  print tree path
//  node(as pre for previous) > pre > node(In) > post > node(as post)
import java.util.Scanner;

public class treePath {
	public static Scanner scn = new Scanner(System.in);
	
	public static void main(String[] args) {
		printTreePath(5);	
	}
	
	public static int printTreePath(int num) {
		if (num == 1 || num == 0) {
			System.out.println("base : " + num);
			return num;
		}
		int ans = 0;
		System.out.println("pre : " + num);
		ans += printTreePath(num - 1);
		System.out.println("In : " + num);
		ans +=printTreePath(num - 2);
		System.out.println("post : " + num);
		
		return ans + 3;
	}
}