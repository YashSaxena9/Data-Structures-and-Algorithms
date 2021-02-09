import java.util.ArrayList;
import java.util.LinkedList;

/**
 * genTree
 */
public class genTree {

	//  class for creating a node of generic tree type
	public static class Node {
		private int data = 0;
		ArrayList<Node> childs = new ArrayList<>();

		Node(int data) {
			this.data = data;
		}

		Node(int data, ArrayList<Node> arr) {
			this.data = data;
			this.childs = arr;
		}
	}

	static Node root = null;

	//  constructor
	public static Node Construct(int[] arr) {
		LinkedList<Node> st = new LinkedList<>();
		for (int i = 0; i < arr.length - 1; i++) {
			if (arr[i] != -1) {
				Node node = new Node(arr[i]);
				st.addFirst(node);
			}
			else {
				Node rchild = st.removeFirst();
				st.getFirst().childs.add(rchild);
			}
		}
		return st.removeFirst();
	}
	
	//  display
	public static void display(Node node) {
		StringBuilder sb = new StringBuilder();
		sb.append(node.data + " -> [");
		for (Node child : node.childs) {
			sb.append(child.data + ", ");
		}
		sb.append("]");
		System.out.println(sb.toString());
		for (Node child : node.childs) {
			display(child);
		}
	}

	public static int max_ = Integer.MIN_VALUE;
	public static int maxInt(Node node) {
		if (node.data > max_) {
			max_ = node.data;
		}
		for (Node child : node.childs) {
			maxInt(child);
		}
		return max_;
	}

	public static int min_ = Integer.MAX_VALUE;
	public static int minInt(Node node) {
		if (node.data < min_) {
			min_ = node.data;
		}
		for (Node child : node.childs) {
			minInt(child);
		}
		return min_;
	}


//  collection.sort(array)
	public static void main(String[] args) {
		int[] arr = {10,20,30,-1,40,-1,-1,50,60,70,-1,80,-1,-1,90,100,-1,110,-1,-1,120,-1,-1,30,-1,-1};
		root = Construct(arr);
		display(root);
	}
}