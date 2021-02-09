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
	
	public static int maxInt(Node node) {
		int max_ = Integer.MIN_VALUE;
		for (Node child : node.childs) {
			max_ = Math.max(maxInt(child), max_);
		}
		return Math.max(max_, node.data);
	}

	public static int minInt(Node node) {
        int min_ = Integer.MAX_VALUE;
        
		for (Node child : node.childs) {
			min_ = Math.min(minInt(child), min_);
		}
		return Math.min(min_, node.data);
    }
    
    public static int size(Node node) {
        int size_ = 0;
        for (Node child : node.childs) {
            size_ += size(child);
        }
        return size_ + 1;
    }

    public static int height(Node node) {
        int height_ = -1;
        for (Node child : node.childs) {
            int recHei_ = height(child);
            height_ = Math.max(height_, recHei_);
        }
        return height_ + 1;
    }

    public static boolean find(Node node, int data) {
        if (node.data == data) {
            return true;
        }
        boolean ans = false;
        for (Node child : node.childs) {
            ans = ans || find(child, data);
        }
        return ans;
    }
    
    //  foldable
    public static boolean isFoldable(Node node1, Node node2) {
        if ((node1 == null && node2 != null) || (node1 != null && node2 == null)) {
            return false;
        }
        if (node1.data != node2.data) {
            return false;
        }
        if (node1.childs.size() != node2.childs.size()) {
            return false;
        }
        for (int i = 0, j = node2.childs.size() - 1; i < node1.childs.size(); i++, j--) {
            Node child1 = node1.childs.get(i);
            Node child2 = node2.childs.get(j);
            boolean res = isFoldable(child1, child2);
            if (!res) {
                return false;
            }
        }
        return true;
    }

    //  falttern the tree
    public static void flatten_01(Node node) {
        ArrayList<Node> ch = new ArrayList<>();
        for (Node n : node.childs) {
            flatten_01(n);
            ch.add(n);
            //  choice of methods
            for (int i = n.childs.size() - 1; i >=0; i--) {
                ch.add(n.childs.remove(n.childs.size() - 1));
            }
            /*
                ch.addAll(n.childs);
                n.childs = new ArrayList<>();
            */
        }
        node.childs = ch;
    }

    //  flattern the tree method 2
    public static void flatten_02_sub(Node node, ArrayList<Node> child) {
        child.add(node);
        for (Node n : node.childs) {
            flatten_02_sub(n, child);
        }
        node.childs = new ArrayList<>();
    }
    public static void flatten_02(Node node) {
        ArrayList<Node> child = new ArrayList<>();
        flatten_02_sub(node, child);
        child.remove(0);
        node.childs = child;
    }

    public static boolean delLeaves(Node node) {
        if (node.childs.size() == 0) {
            return true;
        }
        boolean isLeaf = false;
        for (int i = node.childs.size() - 1; i >= 0; i--) {
            isLeaf = delLeaves(node.childs.get(i));
            if (isLeaf) {
                node.childs.remove(i);
            }
        }
        return false;
    }

    public static void removeLeaves(Node node) {
        for (int i = node.childs.size() - 1; i >= 0; i--) {
            Node child = node.childs.get(i);
            if (child.childs.size() == 0) {
                node.childs.remove(i);
                continue;
            }
            removeLeaves(child);
        }
    }

    public static Node linearise(Node node) {
        if (node.childs.size() == 0) {
            return node;
        }
        Node lastTail = linearise(node.childs.get(node.childs.size() - 1));
        for (int i = node.childs.size() - 1; i > 0; i--) {
            Node secondLastTail = linearise(node.childs.get(i - 1));
            secondLastTail.childs.add(node.childs.remove(i));
        }
        return lastTail;
    }

//  collection.sort(array)
	public static void main(String[] args) {
		int[] arr1 = {10,20,30,-1,40,-1,-1,50,60,70,-1,80,-1,-1,90,100,-1,110,-1,-1,120,-1,-1,130,-1,-1};
		// int[] arr2 = {10,20,30,-1,40,-1,-1,50,60,70,-1,80,-1,-1,90,-1,60,80,-1,70,-1,-1,-1,20,40,-1,30,-1,-1,-1};
		root = Construct(arr1);
        display(root);
        System.out.println(maxInt(root));
        System.out.println(minInt(root));
        System.out.println(size(root));
        System.out.println(height(root));
        System.out.println(find(root, 100));
        System.out.println(isFoldable(root, root));
        Node tail = linearise(root);
        display(root);
        System.out.println("tail is : " + tail.data);
	}
}