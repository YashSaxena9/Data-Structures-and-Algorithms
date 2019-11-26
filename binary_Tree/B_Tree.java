// import java.util.Scanner;
import java.util.Collections;
import java.util.LinkedList;
import java.util.ArrayList;
/**
 * B_Tree
 */
public class B_Tree {
	public class Node {
		private int data = 0;
		private Node left = null;
		private Node right = null;

		//  default constructor 
		//  Node name = new Node();
		Node () {
			this.data = 0;
			this.left = null;
			this.right = null;
		}
		
		Node (int data) {
			this.data = data;
		}

		Node (int data, Node left, Node right) {
			this.data = data;
			this.left = left;
			this.right = right;
		}
	}

	Node root = null;					//  main root of the tree

	//  constructor dusing static index
	//  -1 in array means no branch
	public B_Tree(int[] arr) {
		root = construct_static(arr);
	}

	private static int idx = 0;

	private Node construct_static(int[] arr) {
		if (idx >= arr.length || arr[idx] == -1) {
			idx++;
			return null;
		}

		Node node = new Node(arr[idx], null, null);

		idx++;
		node.left = construct_static(arr);
		node.right = construct_static(arr);

		return node;
	}

	//  constructor without static index
	//  -1 in array means no branch
	public B_Tree(int[] arr, Node idx) {
		root = construct(arr, idx);
	}

	private Node construct(int[] arr, Node idx) {
		if (idx.data >= arr.length || arr[idx.data] == -1) {
			idx.data++;
			return null;
		}

		Node node = new Node(arr[idx.data], null, null);

		idx.data++;
		node.left = construct(arr, idx);
		node.right = construct(arr, idx);

		return node;
	}

	//  function to display tree
	//  pre-order triversal
	public void display() {
		display(this.root);
	}

	private void display(Node node) {
		if (node == null) {
			return;
		}
		StringBuilder sb = new StringBuilder();
		sb.append(node.left == null?" * ":node.left.data);
		sb.append(" -> " + node.data + " <- ");
		sb.append(node.right == null ? " * " : node.right.data);
		System.out.println(sb.toString());

		display(node.left);
		display(node.right);
	}

	//  triversals
	public void preOrder() {
		preOrder(this.root);
	}

	private void preOrder(Node node) {
		if (node == null) {
			return;
		}
		System.out.print(node.data + " ");
		preOrder(node.left);
		preOrder(node.right);
	}
	
	public void inOrder() {
		inOrder(this.root);
	}

	private void inOrder(Node node) {
		if (node == null) {
			return;
		}
		inOrder(node.left);
		System.out.print(node.data + " ");
		inOrder(node.right);
	}
	
	public void postOrder() {
		postOrder(this.root);
	}

	private void postOrder(Node node) {
		if (node == null) {
			return;
		}
		postOrder(node.left);
		postOrder(node.right);
		System.out.print(node.data + " ");
	}

	//  find element in tree
	public boolean find(int data) {
		return find(this.root, data);
	}

	private boolean find(Node node, int data) {
		if (node == null) {
			return false;
		}
		if (node.data == data) {
			return true;
		}
		return find(node.left, data) || find(node.right, data);
	}

	//  maximum element
	public int max() {
		return max(this.root);
	}

	private int max(Node node) {
		if (node == null) {
			return Integer.MIN_VALUE;
		}
		return Math.max(max(node.left), Math.max(node.data, max(node.right)));
	}

	//  minimum element
	public int min() {
		return min(this.root);
	}

	private int min(Node node) {
		if (node == null) {
			return Integer.MAX_VALUE;
		}
		return Math.min(min(node.left), Math.min(node.data, min(node.right)));
	}

	//  node to root path(without return type)
	public void shortestPath(int data) {
		ArrayList<Node> ans = new ArrayList<>();
		if (!shortestPath(this.root, data, ans)) {
			System.out.println("not found");
			return;
		}
		for (Node node : ans) {
			System.out.println(node.data + " ");
		}
		return;
	}

	private boolean shortestPath(Node node, int data, ArrayList<Node> path) {
		if (node == null) {
			return false;
		}
		if (node.data == data) {
			path.add(node);
			return true;
		}
		if (shortestPath(node.left, data, path)) {
			path.add(node);
			return true;
		}
		if (shortestPath(node.right, data, path)) {
			path.add(node);
			return true;
		}
		return false;
	}

	//  node to root path(with return type)
	public void shortestPath_return(int data) {
		ArrayList<Node> ans = shortestPath_return(this.root, data);
		if (ans == null) {
			System.out.println("no path found");
			return;
		}
		Collections.reverse(ans);
		for (Node node : ans) {
			System.out.print(node.data + " ");
		}
		System.out.println();
	}

	private ArrayList<Node> shortestPath_return(Node node, int data) {
		if (node == null) {
			return null;			//  can be used for any non-primitive data types
		}
		if (node.data == data) {
			ArrayList<Node> base = new ArrayList<>();
			base.add(node);
			return base;
		}
		ArrayList<Node> leftAns = shortestPath_return(node.left, data);
		if (leftAns != null) {
			leftAns.add(node);
			return leftAns;
		}
		ArrayList<Node> rightAns = shortestPath_return(node.right, data);
		if (rightAns != null) {
			rightAns.add(node);
			return rightAns;
		}
		return null;
	}

	//  print all leaf nodes (nodes with no branch)
	public void leafNodes() {
		leafNodes(this.root);
		System.out.println();
	}

	private void leafNodes(Node node) {
		if (node == null) {
			return;
		}
		if (node.left == null && node.right == null) {
			System.out.print(node.data + " ");
			return;
		}
		leafNodes(node.left);
		leafNodes(node.right);
	}

	public void lvlOrder_inLine() {
		lvlOrder_inLine(this.root);
	}

	private void lvlOrder_inLine(Node node) {
		LinkedList<Node> myQueue = new LinkedList<>();
		myQueue.addLast(node);
		while(!myQueue.isEmpty()) {
			Node proc = myQueue.removeFirst();
			System.out.print(proc.data + " ");
			if (proc.left != null) {
				myQueue.addLast(proc.left);
			}
			if (proc.right != null) {
				myQueue.addLast(proc.right);
			}

		}
		System.out.println();
	}

	public void lvlOrder_pyramid_withNull() {
		lvlOrder_pyramid_withNull(this.root);
	}

	private void lvlOrder_pyramid_withNull(Node node) {
		LinkedList<Node> myQueue = new LinkedList<>();
		myQueue.add(node);
		myQueue.add(null);
		while(!myQueue.isEmpty()) {
			Node proc = myQueue.removeFirst();
			if (proc == null && myQueue.size() > 0) {
				System.out.println();
				myQueue.addLast(null);
			}
			else {
				if (proc != null) {
					System.out.print(proc.data + " ");
					if (proc.left != null) {
						myQueue.addLast(proc.left);
					}
					if (proc.right != null) {
						myQueue.addLast(proc.right);
					}
				}
			}
		}
		System.out.println();
	}

	public void lvlOrder_pyramid() {
		lvlOrder_pyramid(this.root);
	}

	private void lvlOrder_pyramid(Node node) {
		LinkedList<Node> myQueue = new LinkedList<>();
		myQueue.add(node);
		while(!myQueue.isEmpty()) {
			int size_ = myQueue.size();
			while (size_-- > 0) {
				Node proc = myQueue.removeFirst();
				System.out.print(proc.data + " ");
				if (proc.left != null) {
					myQueue.addLast(proc.left);
				}
				if (proc.right != null) {
					myQueue.addLast(proc.right);
				}
			}
			System.out.println();
		}
	}

	public void lvlOrder_pyramid_2que() {
		lvlOrder_pyramid_2que(this.root);
	}

	// swap using array of linked list
	public static void swap(LinkedList<Node>[] arr) {
		LinkedList<Node> temp = arr[0];
		arr[0] = arr[1];
		arr[1] = temp;
	}

	private void lvlOrder_pyramid_2que(Node node) {
		LinkedList<Node> queue1 = new LinkedList<>();
		LinkedList<Node> queue2 = new LinkedList<>();
		queue1.addLast(node);
		while (!queue1.isEmpty()) {
			Node proc = queue1.removeFirst();
			System.out.print(proc.data + " ");
			if (proc.left != null) {
				queue2.addLast(proc.left);
			}
			if (proc.right != null) {
				queue2.addLast(proc.right);
			}
			if (queue1.size() == 0) {
				System.out.println();
				// by using array of linked list
				/*
				LinkedList<Node>[] arr = new LinkedList[2];
				arr[0] = queue1;
				arr[1] = queue2;
				swap(arr);
				queue1 = arr[0];
				queue2 = arr[1];
				*/

				//  by swapping in function itself
				LinkedList<Node> temp = queue1;
				queue1 = queue2;
				queue2 = temp;
			}
		}
	}
}