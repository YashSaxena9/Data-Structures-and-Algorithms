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
    
    public static int height(Node node) {   //  in terms of edges
        if (node == null) {
            return -1;  //  make it 0 for in terms of nodes
        }
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

    //  we call root to node path here
    public static void K_Away(Node root, int data, int k_value) {   //  root ~== node
        ArrayList<Node> path = rootToNodePath(root, data);
        Node pnode = null;
        for (int i = 0; i < path.size(); i++) {
            K_Down(path.get(i), pnode, k_value - i);
            pnode = path.get(i);
        }
    }

    //  no need for root to node path call
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

    public static int diameter(Node node) {     //  in terms of edges
        if (node == null) {
            return 0;
        }
        int ld = diameter(node.left);
        int rd = diameter(node.right);
        int lh = height(node.left);     //  height in terms of edges
        int rh = height(node.right);
        return Math.max(Math.max(ld, rd), lh + rh + 2);
    }
    
    public static int[] diameter_btr_edges(Node node) {     //  in terms of edges
        if (node == null) {
            return new int[]{0, -1};
        }
        int[] ld = diameter_btr_edges(node.left);
        int[] rd = diameter_btr_edges(node.right);
        int[] myAns = new int[2];
        myAns[0] = Math.max(Math.max(ld[0], rd[0]), ld[1] + rd[1] + 2);
        myAns[1] = Math.max(ld[1], rd[1]) + 1;
        return myAns;
    }
    
    public static int[] diameter_btr_nodes(Node node) {     //  in terms of nodes
        if (node == null) {
            return new int[]{0, 0};
        }
        int[] ld = diameter_btr_nodes(node.left);
        int[] rd = diameter_btr_nodes(node.right);
        int[] myAns = new int[2];
        myAns[0] = Math.max(Math.max(ld[0], rd[0]), ld[1] + rd[1] + 1);
        myAns[1] = Math.max(ld[1], rd[1]) + 1;
        return myAns;
    }

    public static int MaxSum = 0;
    public static int leafToLeafSum(Node node) {        //  leaf to leaf largest sum(path starts from one leaf and ends to other5)
        if (node == null) {
            return Integer.MIN_VALUE;
        }
        if (node.left == null && node.right == null) {
            return node.data;
        }
        int lMaxSum = leafToLeafSum(node.left);
        int rMaxSum = leafToLeafSum(node.right);
        if (node.left != null && node.right != null) {
            MaxSum = Math.max(MaxSum, lMaxSum + rMaxSum + node.data);
        }
        return Math.max(lMaxSum, rMaxSum) + node.data;
    }

    public static void displayNodeList(ArrayList<Node> arr) {
        for (Node n : arr) {
            System.out.print(n.data + " ");
        }
        System.out.println();
    }

    //  ==============================================================================================================================================================
    /**
     * BST
     */
    public static Node makeBST(int[] arr, int si, int ei) {
        if (si > ei) {
            return null;
        }
        int mid = (si + ei) >> 1;
        Node node = new Node(arr[mid]);
        node.left = makeBST(arr, si, mid - 1);
        node.right = makeBST(arr, mid + 1, ei);
        return node;
    }

    public static boolean findInBST(Node node, int data) {
        if (node == null) {
            return false;
        }
        if (node.data == data) {
            return true;
        }
        if (data < node.data) {
            return findInBST(node.left, data);
        } else {
            return findInBST(node.right, data);
        }
    }
    
    //  ==============================================================================================================================================================
    
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
        Node root = createTree(tree1);
        // System.out.println(root);
        // displayNodeList(rootToNodePath(root, 100));
        // System.out.println(LowestCommAnces(root, 100, 110).data);
        // K_Away(root, 110, 4);
        // K_Away_btr(root, 110, 4);
        // System.out.println(diameter(root));
        // System.out.println(diameter_btr_edges(root)[0]);
        // System.out.println(diameter_btr_nodes(root)[0]);
        // leafToLeafSum(root);    System.out.println(MaxSum);

        /**
         * BST
         */
        int[] arr = new int[10];
        for (int i = 0; i < 10; i++) {
            arr[i] = (i + 1) * 10;
        }
        Node bst = makeBST(arr, 0, arr.length - 1);
        System.out.println(bst);
        System.out.println(findInBST(bst, 80));
    }

    public static void main(String[] args) {
        solve();
    }
}