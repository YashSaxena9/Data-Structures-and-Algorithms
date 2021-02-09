import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
// import java.util.Queue;

// import jdk.nashorn.internal.runtime.arrays.ArrayLikeIterator;

public class BTree {

	private static class Node {
		private int data = 0;
		private Node left = null;
		private Node right = null;

		// Node(int data)
		// {
		// this.data=data;
		// }

		public Node(int data, Node left, Node right) {
			this.data = data;
			this.left = left;
			this.right = right;
		}
	}

	static Node root = null;

	private static void BTree(int[] arr) {
		root = construct(arr);
	}

	static int idx = 0;

	private static Node construct(int[] arr) {
		if (idx >= arr.length || arr[idx] == -1) {
			idx++;
			return null;
		}

		Node node = new Node(arr[idx], null, null);
		idx++;
		node.left = construct(arr);
		node.right = construct(arr);

		return node;
	}

	public void display() {
		display(root);
	}

	public static void display(Node node) {
		if (node == null) {
			return;
		}

		StringBuilder sb = new StringBuilder(); // JUST LIKE VECTOR

		sb.append(node.left != null ? node.left.data : " . ");
		sb.append("->" + node.data + "<-");
		sb.append(node.right != null ? node.right.data : " . ");
		System.out.println(sb.toString());
		display(node.left);
		display(node.right);
	}

	public static boolean find(Node node, int data) {
		if (node == null)
			return false;

		if (node.data == data)
			return true;

		return find(node.left, data) || find(node.right, data);
	}

	public static int max(Node node) {
		if (node == null)
			return Integer.MIN_VALUE;

		int maxn = node.data;
		int max1 = max(node.left);
		int max2 = max(node.right);

		return Math.max(maxn, Math.max(max1, max2));
	}

	public static int min(Node node) {
		if (node == null)
			return Integer.MAX_VALUE;

		int minn = node.data;
		int min1 = max(node.left);
		int min2 = max(node.right);

		return Math.min(minn, Math.min(min1, min2));
	}

	public static ArrayList<Node> rootToNodePath(Node node, int data) {
		if (node == null)
			return null;

		if (node.data == data) {
			ArrayList<Node> base = new ArrayList<>();
			base.add(node);
			return base;
		}

		ArrayList<Node> leftAns = rootToNodePath(node.left, data);
		if (leftAns != null) {
			leftAns.add(node);
			return leftAns;
		}

		ArrayList<Node> rightAns = rootToNodePath(node.right, data);
		if (rightAns != null) {
			rightAns.add(node);
			return rightAns;
		}
		return null;
	}

	public static boolean rootToNodePath_01(Node node, int data, ArrayList<Node> path) {
		if (node == null)
			return false;

		if (node.data == data) {
			path.add(node);
			return true;
		}

		if (rootToNodePath_01(node.left, data, path)) {
			path.add(node);
			return true;
		}

		if (rootToNodePath_01(node.right, data, path)) {
			path.add(node);
			return true;
		}
		return false;
	}

	public static void leafNodes(Node node) {
		if (node == null)
			return;

		if (node.left == null && node.right == null) {
			System.out.println(node.data + " ");
			return;
		}

		leafNodes(node.left);
		leafNodes(node.right);
	}

	public static void levelOrder_inLine(Node rootNode) {
		LinkedList<Node> myQueue = new LinkedList<>();
		myQueue.addLast(rootNode);
		while (!myQueue.isEmpty()) {				//  or (myQueue.size() != 0)
			Node node = myQueue.removeFirst();
			System.out.print(node.data + " ");
			if (node.left != null) {
				myQueue.addLast(node.left);
			}
			if (node.right != null) {
				myQueue.addLast(node.right);
			}
		}
	}

	public static void levelOrder_pyramid_withNull(Node rootNode) {
		LinkedList<Node> myQueue = new LinkedList<>();
		myQueue.addLast(rootNode);
		myQueue.addLast(null);
		while (!myQueue.isEmpty()) { 						// or (myQueue.size() != 0)
			Node node = myQueue.removeFirst();
			if (node == null && myQueue.size() > 0) {
				myQueue.addLast(null);
				System.out.println();
			}
			else {
				if(node!=null){
					System.out.print(node.data + " ");
					if (node.left != null) {
						myQueue.addLast(node.left);
					}
					if (node.right != null) {
						myQueue.addLast(node.right);
					}
				}
			}
		}
	}

	public static void levelOrder_pyramid(Node rootNode) {
		LinkedList<Node> myQueue = new LinkedList<>();
		myQueue.addLast(rootNode);
		while (!myQueue.isEmpty()) {
			int size = myQueue.size();
			while (size-- > 0) {
				Node node = myQueue.removeFirst();
				System.out.print(node.data + " ");
				if (node.left != null) {
					myQueue.addLast(node.left);
				}
				if (node.right != null) {
					myQueue.addLast(node.right);
				}	
			}
			System.out.println();	
		}
	}

	//  this will not work due to stack tray theory
	/*
	public static void swap_L_List(LinkedList<Node> queue1, LinkedList<Node> queue2) {
		LinkedList<Node> temp = new LinkedList<>();
		queue1 = queue2;
		queue2 = temp;
	}
	*/

	//  swap using array of linked list
	public static void swap(LinkedList<Node>[] arr) {
		LinkedList<Node> temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}

	public static void levelOrder_pyramid_2que(Node rootNode) {
		LinkedList<Node> queue1 = new LinkedList<>();
		LinkedList<Node> queue2 = new LinkedList<>();
		queue1.addLast(rootNode);
		while (!queue1.isEmpty()) {
			Node node = queue1.removeFirst();
			System.out.print(node.data + " ");
			if (node.left != null) {
				queue2.addLast(node.left);
			}
				if (node.right != null) {
				queue2.addLast(node.right);
			}
				if (queue1.size() == 0) {		//  normal swap function doesn't work due to stack saving
				System.out.println();
				//  swap in function itself
				/*
				LinkedList<Node> temp = queue1;
				queue1 = queue2;
				queue2 = temp;
				*/

				//  by using array of linked list
				LinkedList<Node>[] arr = new LinkedList[2];
				arr[0] = queue1;
				arr[1] = queue2;
				swap(arr);
				queue1 = arr[0];
				queue2 = arr[1];
			}
		}
	}

	// public static void levelOrder_pyramid_zigZag(Node rootNode) {
		// LinkedList<Node> queue1 = new LinkedList<>();
		// LinkedList<Node> queue2 = new LinkedList<>();
		// queue1.addLast(rootNode);
		// while (!queue1.isEmpty()) {
		// 	Node node = queue1.removeFirst();
		// 	System.out.print(node.data + " ");
		// 	if (node.left != null) {
		// 		queue2.addLast(node.left);
		// 	}
		// 	if (node.right != null) {
		// 		queue2.addLast(node.right);
		// 	}
		// 	if (queue1.size() == 0) { // normal swap function doesn't work due to stack saving
		// 		System.out.println();
		// 		// swap in function itself
		// 		/*
		// 		 * LinkedList<Node> temp = queue1; queue1 = queue2; queue2 = temp;
		// 		 */

		// 		// by using array of linked list
		// 		LinkedList<Node>[] arr = new LinkedList[2];
		// 		arr[0] = queue1;
		// 		arr[1] = queue2;
		// 		swap(arr);
		// 		queue1 = arr[0];
		// 		queue2 = arr[1];
		// 	}
		// }

		public static Node commAnces_01(Node root,int data1, int data2) {
			ArrayList<Node> path1 = rootToNodePath(root, data1);
			ArrayList<Node> path2 = rootToNodePath(root, data2);
			if (path1 == null || path2 == null) {
				return null;
			}
			int size = path1.size() <= path2.size() ? path1.size() : path2.size();

			int i = size - 1;
			for (; i >= 0; i--) {
				if (path1.get(i) != path2.get(i) && i != size - 1) {
					return path1.get(i + 1);
				}
			}
			if (i == 0) {
				return path1.get(i);
			}
			return null;
		}

		public static Node LCA = null;
		public static boolean commAnces_02(Node node,int data1, int data2) {
			if (node == null) {
				return false;
			}
			boolean selfDone = node.data == data1 || node.data == data2;
			boolean left = commAnces_02(node.left, data1, data2);
			if (LCA != null) {
				return true;
			}
			boolean right = commAnces_02(node.right, data1, data2);
			if ((left && right) || (left && selfDone) || (right && selfDone)) {
				LCA = node;
			}
			return left || right || selfDone;
		}

		//  pair class
		public static class Pair {
			int min;
			int max;
			boolean isBst;
			int countBst;
			public Pair() {
				min = Integer.MAX_VALUE;
				max = Integer.MIN_VALUE;
				isBst = true;
				countBst = 0;
			}
		}

		public static Pair binSearchCheck(Node node) {
			if (node == null) {
				return new Pair();
			}
			Pair myPair = new Pair();
			myPair.isBst = false;
			Pair left = binSearchCheck(node.left);
			Pair right = binSearchCheck(node.right);
			if (left.isBst && right.isBst && left.max <= node.data && right.min >= node.data) {
				myPair.isBst = true;
				myPair.countBst = 1;
			}
			myPair.min = Math.min(node.data, Math.min(left.min, right.min));
			myPair.max = Math.max(node.data, Math.max(left.max, right.max));
			myPair.countBst += left.countBst + right.countBst;
			return myPair;
		}

	public static void main(String[] args) {
		// int[] arr = { 10, 20, 40, 80, -1, -1, 90, -1, -1, 50, 100, -1, -1, -1, 30, 60, -1, 110, -1, -1, 70, 120, -1, -1, -1 };
		// int[] arr = {10,20,40,-1,-1,50,-1,-1,30,60,1110,1120,-1,1130,-1,-1,-1,-1,70,80,-1,-1,90,100,-1,110,-1,-1,-1};
		int[] arr = {10,30,10,-1,20,-1,-1,40,-1,-1,80,70,60,-1,-1,-1,90};
		BTree(arr);
		
		// System.out.println(find(root, 50));
		// System.out.println(max(root));
		// System.out.println(min(root));

		// ArrayList<Node> ans = new ArrayList<>();
		// ans = rootToNodePath(root, 110);
		// Collections.reverse(ans);
		// for(Node node : ans)
		// {
		// System.out.println(node.data + " ");
		// }

		// ArrayList<Node> ans = new ArrayList<>();
		// rootToNodePath_01(root, 110, ans);
		// Collections.reverse(ans);
		// for(Node node : ans)
		// {
		// System.out.println(node.data + " ");
		// }

		// leafNodes(root);
		// levelOrder_pyramid_withNull(root);
		// levelOrder_pyramid(root);
		// levelOrder_pyramid_2que(root);
		// System.out.println(commAnces_01(root, 1110, 70).data);
		// if (commAnces_02(root, 1110, 70)) {
		// 	System.out.println(LCA.data);
		// }
		System.out.println(binSearchCheck(root).countBst);
	}
}
