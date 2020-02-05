import java.util.Scanner;
import java.util.ArrayList;
public class binTree {
    public static class Node {
        int data;
        Node left;
        Node right;
        public Node() {
            this(0, null, null);
        }

        public Node(int data) {
            this(data, null, null);
        }

        public Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }

        @Override
        public String toString() {
            String str = "";
            str += ((left != null ? left.data : "."));
            str += (" -> " + data + " <- ");
            str += ((right != null ? right.data : "."));
            str += "\n";
            if (left != null)
                str += left.toString();
            if (right != null)
                str += right.toString();
            return str;
        }
    }

    private static int idx = 0;
    public static Node createTree(int[] arr) {
        if (idx == arr.length || arr[idx] == -1) {
            idx++;
            return null;
        }
        Node node = new Node(arr[idx]);
        idx++;
        node.left = createTree(arr);
        node.right = createTree(arr);
        return node;
    }

    public static void display(Node node) {
        if (node == null)
            return;
        System.out.print((node.left != null ? node.left.data : "."));
        System.out.print(" -> " + node.data + " <- ");
        System.out.println((node.right != null ? node.right.data : "."));
        display(node.left); // display(2*idx+1);
        display(node.right); // display(2*idx+2);
    }

    // basic.============================

    public static int maximumInTree(Node node) {
        if (node == null)
            return (int) -1e8;

        int lmax = maximumInTree(node.left);
        int rmax = maximumInTree(node.right);
        int oMax = Math.max(lmax, rmax);

        return Math.max(node.data, oMax);
    }
    
    public static int minimumInTree(Node node) {
        if (node == null)
            return (int) 1e8;

        int lmin = minimumInTree(node.left);
        int rmin = minimumInTree(node.right);
        int oMin = Math.min(lmin, rmin);

        return Math.min(node.data, oMin);
    }

    public static boolean find(Node node, int data) {
        if (node == null)
            return false;
        if (node.data == data)
            return true;
        boolean res = false;
        res = res || find(node.left, data);
        res = res || find(node.right, data);
        return res;
    }
    
    public static int size(Node node) {
        if (node == null)
        return 0;
        return size(node.left) + size(node.right) + 1;
        
    }
    
    public static int height(Node node) {
        if (node == null)
        return -1;
        return Math.max(height(node.left), height(node.right)) + 1;
        
    }

    public static ArrayList<Node> rootToNodePath(Node node, int data) {
        if (node == null) {
            return new ArrayList<>();
        }
        if (node.data == data) {
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }
        ArrayList<Node> recAns;
        recAns = rootToNodePath(node.left, data);
        if (recAns.size() == 0) {
            recAns = rootToNodePath(node.right, data);
        }
        if (recAns.size() != 0) {
            recAns.add(node);
        }
        return recAns;
    }

    public static Node LowestCommAnces(Node root, int data1, int data2) {
        ArrayList<Node> path1 = rootToNodePath(root, data1);
        ArrayList<Node> path2 = rootToNodePath(root, data2);
        int i = path1.size() - 1, j = path2.size() - 1;
        Node ans = new Node(-1);
        while (i >= 0 && j >= 0) {
            if (path1.get(i) != path2.get(j)) {
                break;
            }
            ans = path1.get(i);
            i--;
            j--;
        }
        return ans;
    }
    
    //================================= k down =====================================
    // nodes at 'K' radii from a given node
    // LeetCode 863. All Nodes Distance K in Binary Tree
    public static void K_Down(Node node, Node pNode, int level) {
        if (node == null || node == pNode) {
            return;
        }
        if (level == 0) {
            System.out.print(node.data + " ");
        }
        K_Down(node.left, pNode, level - 1);
        K_Down(node.right, pNode, level - 1);
    }

    public static void K_Away(Node root, int data, int k_value) {   //  root ~== node
        ArrayList<Node> path = rootToNodePath(root, data);
        Node pnode = null;
        for (int i = 0; i < path.size(); i++) {
            K_Down(path.get(i), pnode, k_value - i);
            pnode = path.get(i);
        }
    }

    public static int K_Away_btr(Node node, int data, int k_value) {
        if (node == null) {
            return -1;
        }
        if (node.data == data) {
            K_Down(node, null, k_value);
            return 1;
        }
        int leftDis = K_Away_btr(node.left, data, k_value);
        if (leftDis != -1) {
            K_Down(node, node.left, k_value - leftDis);
            return leftDis + 1;
        }
        int rightDis = K_Away_btr(node.right, data, k_value);
        if (rightDis != -1) {
            K_Down(node, node.right, k_value - rightDis);
            return rightDis + 1;
        }
        return -1;
    }
    //================================= k down end =====================================

    public static void displayNodeList(ArrayList<Node> arr) {
        for (Node n : arr) {
            System.out.print(n.data + " ");
        }
        System.out.println();
    }
    
    public static void solve() {
        int[] tree1 = {
            10, 20, 30, 40, -1, -1, 50, -1, -1, 60, -1, 70, -1, -1, 80, 90, 100, 120, -1, -1, 130, -1, -1, 110, -1, -1, 140, -1, -1
        };
        int[] tree2 = {
            10, 20, 30, -1, -1, 40, 50, -1, -1, 60, -1, -1, 70, 80, 100, -1, -1, 110, 140, -1, -1, -1, 90, -1, -1
        };
        int[] tree3 = {
            10, 20, 30, -1, -1, 40, 50, -1, -1, 60, -1, -1, 70, 80, 100, 101, 102, -1, -1, -1, -1, 
            110, 140, 139, -1, 142, 146, -1, -1, -1, 141, 143, 147, -1, -1, 148, -1, -1, -1, -1, 90, 
            191, -1, -1, 180, 190, -1, -1, 200, -1, -1
        };
        Node root = createTree(tree3);
        // System.out.println(root);
        // displayNodeList(rootToNodePath(root, 100));
        // System.out.println(LowestCommAnces(root, 100, 110).data);
        // K_Away(root, 110, 4);
        K_Away_btr(root, 110, 4);
    }

    public static void main(String[] args) {
        solve();
    }
}