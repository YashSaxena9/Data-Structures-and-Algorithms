//  AVL tree
import java.util.Scanner;
import java.util.ArrayList;

/**
 * AVL_Tree
 */
public class AVL_Tree {
	public static class Node {
		private int data = 0;
		private Node left = null;
		private Node right = null;

		private int balance = 0;
		private int height = -1;			//  default height for a null node
		private int freq = 1;

		Node(int data) {
			this.data = data;
		}

		Node(int data, Node left, Node right) {
			this.data = data;
			this.left = left;
			this.right = right;
		}
	}
	static Node root = null;

	public static void AVL_Tree(int[] arr) {
		root = construct(arr, 0, arr.length - 1);
	} 
	public static Node construct(int[] arr, int si, int ei) {		//  always a balanced BST / AVL tree is made as we use middle of an array
		//  tree is created by level order
		if (si > ei) {
			return null;
		}
		int mid = ((si + ei) >> 1);
		Node node = new Node(arr[mid]);
		node.left = construct(arr, si, mid - 1);
		node.right = construct(arr, mid + 1, ei);
		getFactors(node);			//  we need update the factors(height, balance) for all nodes while creating (including leaf nodes)
		return node;
	}

	public static void display(Node node) {
		if (node == null) {
			return;
		}
		StringBuilder sb = new StringBuilder();
		sb.append((node.left != null) ? node.left.data : " . ");
		sb.append(" -> " + node.data + " <- ");
		sb.append((node.right != null) ? node.right.data : " . ");
		sb.append("\t\t h: " + node.height + " b: " + node.balance + " freq: " + node.freq);
		System.out.println(sb.toString());
		display(node.left);
		display(node.right);
	}

	public static int maxInt(Node node) {
		Node curr = node;
		while (curr.right != null) {
			curr = curr.right;
		}
		return curr.data;
	}

	public static int minInt(Node node) {
		Node curr = node;
		while (curr.left != null) {
			curr = curr.left;
		}
		return curr.data;
	}
	
	public static int getHeight(Node node) {
		if (node == null) {
			return -1;
		}
		int lh = -1;
		int rh = -1;
		if (node.left != null) {
			lh = node.left.height;
		}
		if (node.right != null) {
			rh = node.right.height;
		}
		return Math.max(lh, rh) + 1;
	}

	public static int getBalance(Node node) {
		if (node == null) {
			return 0;
		}
		int lh = -1;
		int rh = -1;
		if (node.left != null) {
			lh = node.left.height;
		}
		if (node.right != null) {
			rh = node.right.height;
		}
		return lh - rh;			//  left - right or else rotation algo should be reversed
	}

	public static void getFactors(Node node) {			//  to call in one line
		node.height = getHeight(node);
		node.balance = getBalance(node);
	}

	public static Node leftLeft(Node node) {			//  right rotation
		Node temp = node.left;
		Node subTree = temp.right;
		temp.right = node;
		node.left = subTree;
		getFactors(node);
		getFactors(temp);
		return temp;
	}

	public static Node rightRight(Node node) {			//  left rotation
		Node temp = node.right;
		Node subTree = temp.left;
		temp.left = node;
		node.right = subTree;
		getFactors(node);
		getFactors(temp);
		return temp;
	}

	public static Node updateFactor(Node node) {
		if (getBalance(node) > 1) {
			if (getBalance(node.left) > 0) {
				node = leftLeft(node);
			}
			else {
				node.left = rightRight(node.left);
				node = leftLeft(node);
			}
		}
		else if (getBalance(node) < -1) {
			if (getBalance(node.right) < 0) {
				node = rightRight(node);
			}
			else {
				node.right = leftLeft(node.right);
				node = rightRight(node);
			}
		}
		return node;
	}

	public static Node addNode(Node node, int data) {
		if (node == null) {
			Node base = new Node(data);
			getFactors(base);
			return base;
		}
		if (node.data == data) {
			node.freq++;
			return node;
		}
		else if (node.data < data) {
			node.right = addNode(node.right, data);
		}
		else {
			node.left = addNode(node.left, data);
		}
		getFactors(node);
		node = updateFactor(node);
		return node;
	}

	//  delete node
	public static Node delNode(Node node, int data) {
		if (node == null) {
			return node;
		}
		if (node.data < data) {
			node.right = delNode(node.right, data);
		}
		else if (node.data > data) {
			node.left = delNode(node.left, data);
		}
		else {
			if (node.freq > 1) {
				node.freq--;
			}
			else {
				if (node.left == null && node.right == null) {
					return null;
				}
				else if (node.left == null || node.right == null) {
					Node n = node.left != null ? node.left : node.right;
					return n;
				}
				int max_ = maxInt(node.left);
				node.data = max_;
				node.left = delNode(node.left, max_);
			}
		}
		getFactors(node);
		node = updateFactor(node);
		return node;
	}
	public static void main(String[] args) {
		int[] arr = {10,20,30,40,50,60,70,80,90,100,110,120,130,140};
		AVL_Tree(arr);
		display(root);
		System.out.println();
		addNode(root, 150);
		addNode(root, 180);
		display(root);
		System.out.println();
		delNode(root, 180);
		delNode(root, 150);
		delNode(root, 100);
		delNode(root, 80);
		delNode(root, 90);
		display(root);
	}
}