import java.util.ArrayList;
import java.util.LinkedList;
/**
 * BinaryTree
 */
public class BinaryTree {
    //  Node class can be private(preferable)
    public class Node implements Comparable<Node> {        //  inner class if private then not visible to client
        public int data;
        public Node left;
        public Node right;
        Node() {
            this(0, null, null);
        }
        Node(int data) {
            this(data, null, null);
        }
        Node(int data, Node left, Node right) {
            this.data = data;
            this.left = left;
            this.right = right;
        }
        @Override
        public String toString() {
            String str = "";
            str += (left == null) ? " . " : left.data;
            str += " -> " + data + " <- ";
            str += (right == null) ? " . " : right.data;
            str += "\n";
            if (left != null) {
                str += left.toString();
            }
            if (right != null) {
                str += right.toString();
            }
            return str;
        }

        /* ============================= comparable ===================================== */
        @Override
        public int compareTo(Node n) {
            return this.data - n.data;
        }
    }

    private Node root = new Node();     //  root node for our tree

    /* ========================== constructors ================================== */
    
    /**
     * default construction for a tree of single Node
     * with null/default values
     */
    BinaryTree() {
        //  default
    }

    /**
     * constructor to choose wheater to construct tree
     * from preOrder or lvlOrder
     * @param arr   traversal of array in preOrder or levelOrder
     * (must have -1 for null)
     * @param isPreord      boolean for array traversal type
     * (must be true for PreOrder and false for levelOrder)
     */
    BinaryTree(int[] arr, boolean isPreOrd) {
        if (isPreOrd) {
            this.root = preOrdConstruct(arr);
        } else {
            this.root = lvlConstruct(arr, 0);
        }
    }
    
    /**
     * constructor for tree construction from pre order by default
     * @param arr   pre Order traversal array with -1 for null
     */
    BinaryTree(int[] arr) {
        this.root = preOrdConstruct(arr);
    }
    
    private int idx = 0;
    private Node preOrdConstruct(int[] arr) {
        if (idx >= arr.length || arr[idx] == -1) {       //  null value found
            idx++;
            // if (idx == arr.length)  idx = 0;    //  index reset on out_of_bound(if idx is static)
            return null;
        }
        Node node = new Node(arr[idx++]);
        node.left = preOrdConstruct(arr);
        node.right = preOrdConstruct(arr);
        return node;
    }

    private Node lvlConstruct(int[] arr, int idx_itr) {
        if (idx_itr >= arr.length || arr[idx_itr] == -1) {
            return null;
        }
        Node node = new Node(arr[idx_itr]);
        node.left = lvlConstruct(arr, idx_itr * 2 + 1);
        node.right = lvlConstruct(arr, idx_itr * 2 + 2);
        return node;
    }
    
    /**
     * to make a binary tree from another "binary tree"
     * @param node
     */
    BinaryTree(BinaryTree node) {
        this.root = node.root;
    }

    /**
     * to make a binary tree from another "node of binary tree"
     * @param node
     */
    private BinaryTree(Node node) {
        this.root = node;
    }
    
    /* ========================== constructors end ================================== */
    
    /**
     * @return String  -   a string of preOrder traversal of tree
     * (null is represented by " . ")
     */
    @Override
    public String toString() {
        //  if we remove toString @override from Node class then uncomment below code
        //----------------------------------------------------------------------------
        /* 
        String str = "";
        str += (root.left != null) ? root.left.data : " . ";
        str += " -> " + root.data + " <- ";
        str += (root.right != null) ? root.right.data : " . ";
        str += "\n";
        if (root.left != null)
        str += (new BinaryTree(root.left)).toString();
        if (root.right != null)
        str += (new BinaryTree(root.right)).toString();
        return str;
         */
        return root.toString();
    }

    /**
     * to print the formed tree in preOrder
     */
    public void display() {
        display(this.root);
    }
    private void display(Node node) {
        if (node == null)   return;
        System.out.print((node.left != null) ? node.left.data : " . ");
        System.out.print(" -> " + node.data + " <- ");
        System.out.println((node.right != null) ? node.right.data : " . ");
        display(node.left);
        display(node.right);
    }

    /**
     * @return int - maximum integer value of tree
     */
    public int maxValue() {
        return maxValue(this.root);
    }

    private int maxValue(Node node) {
        if (node == null) {
            // return Integer.MIN_VALUE;
            return (int) -1e8;
        }
        return Math.max(Math.max(maxValue(node.left), maxValue(node.right)), node.data);
    }

    /**
     * @return int - minimum integer value of tree
     */
    public int minValue() {
        return minValue(this.root);
    }

    private int minValue(Node node) {
        if (node == null) {
            // return Integer.MAX_VALUE;
            return (int)1e8;
        }
        return Math.min(Math.min(minValue(node.left), minValue(node.right)), node.data);
    }

    /**
     * to find total number of nodes in tree
     * @return  int - size of tree
     */
    public int size() {
        return size(this.root);
    }

    private int size(Node node) {
        if (node == null) {
            return 0;
        }
        return size(node.left) + size(node.right) + 1;
    }

    /**
     * to find the presence of data in the tree
     * @param data  - data to find
     * @return  boolean (true if found, false if not)
     */
    public boolean find(int data) {
        return find(this.root, data);
    }

    private boolean find(Node node, int data) {
        if (node == null)   return false;
        return (node.data == data) || find(node.left, data) || find(node.right, data);
    }

    /**
     * maximum height of tree in terms of nodes count
     * @return  int
     */
    public int heightInNodes() {
        return height_nodes(this.root);
    }

    private int height_nodes(Node node) {
        if (node == null)       return 0;
        return Math.max(height_nodes(node.left), height_nodes(node.right)) + 1;
    }
    
    /**
     * maximum height of tree in terms of edges count
     * @return  int
     */
    public int heightInEdges() {
        return height_edges(this.root);
    }

    private int height_edges(Node node) {
        if (node == null)       return -1;
        return Math.max(height_edges(node.left), height_edges(node.right)) + 1;
    }

    /**
     * to display tree from level order traversal
     * without making actual tree
     * (the array must be of level order traversal and have -1 for null)
     * ------ can be used to get preview of tree ------
     * @param arr - array of level order traversal(with -1 for null)
     */
    public void pseudotreeDisplay(int[] arr) {
        displayWithoutMakingTree(arr, 0);
    }
    private void displayWithoutMakingTree(int[] arr, int vidx) {
        if (vidx >= arr.length || arr[vidx] == -1) {
            return;
        }
        StringBuilder str = new StringBuilder();
        str.append((vidx * 2 + 1 < arr.length && arr[vidx * 2 + 1] != -1) ? arr[vidx * 2 + 1] : " . ");
        str.append(" -> " + arr[vidx] + " <- ");
        str.append((vidx * 2 + 2 < arr.length && arr[vidx * 2 + 2] != -1) ? arr[vidx * 2 + 2] : " . ");
        System.out.println(str);        //  fires .toString() first
        displayWithoutMakingTree(arr, vidx * 2 + 1);
        displayWithoutMakingTree(arr, vidx * 2 + 2);
    }

    /**
     * this method returns a string of pre-order traversal of the tree
     * @return String
     */
    public String preOrder_return() {
        return preOrder_return(this.root);
    }
    private String preOrder_return(Node node) {
        if (node == null) {     //  base case of null
            // return "null ";
            return "";
        }
        StringBuilder str = new StringBuilder();
        str.append(node.data + " ");
        
        // if (node.left != null)
            str.append(preOrder_return(node.left));
        
        // if (node.right != null)
            str.append(preOrder_return(node.right));
        return str.toString();
    }

    /**
     * this method returns a string of in-order traversal of the tree
     * @return String
     */
    public String inOrder_return() {
        return inOrder_return(this.root);
    }
    private String inOrder_return(Node node) {
        if (node == null) {     //  base case of null
            // return "null ";
            return "";
        }
        StringBuilder str = new StringBuilder();
        // if (node.left != null)
            str.append(inOrder_return(node.left));

        str.append(node.data + " ");

        // if (node.right != null)
            str.append(inOrder_return(node.right));
        return str.toString();
    }

    /**
     * this method returns a string of post-order traversal of the tree
     * @return String
     */
    public String postOrder_return() {
        return postOrder_return(this.root);
    }
    private String postOrder_return(Node node) {
        if (node == null) {     //  base case of null
            // return "null ";
            return "";
        }
        StringBuilder str = new StringBuilder();
        // if (node.left != null)
        str.append(postOrder_return(node.left));
        
        // if (node.right != null)
        str.append(postOrder_return(node.right));
        
        str.append(node.data + " ");
        return str.toString();
    }

    /**
     * this method prints a string of pre-order traversal of the tree
     */
    public void preOrder_print() {
        preOrder_print(this.root);
        System.out.println();
    }
    private void preOrder_print(Node node) {
        if (node == null) {     //  base case of null
            return;
        }
        StringBuilder str = new StringBuilder();
        System.out.print(node.data + " ");
        
        // if (node.left != null)
            preOrder_print(node.left);
        
        // if (node.right != null)
            preOrder_print(node.right);
    }

    /**
     * this method prints a string of in-order traversal of the tree
     */
    public void inOrder_print() {
        inOrder_print(this.root);
        System.out.println();
    }
    private void inOrder_print(Node node) {
        if (node == null) {     //  base case of null
            return;
        }
        // if (node.left != null)
            inOrder_print(node.left);

        System.out.print(node.data + " ");

        // if (node.right != null)
            inOrder_print(node.right);
    }

    /**
     * this method prints a string of post-order traversal of the tree
     */
    public void postOrder_print() {
        postOrder_print(this.root);
        System.out.println();
    }
    private void postOrder_print(Node node) {
        if (node == null) {     //  base case of null
            return;
        }
        // if (node.left != null)
        postOrder_print(node.left);
        
        // if (node.right != null)
        postOrder_print(node.right);
        
        System.out.print(node.data + " ");
    }

    public void lvl_print() {
        System.out.println(lvl_print_2loop_Bfs(this.root));
        System.out.println(lvl_print_queWithNull(this.root));
    }
    private String lvl_print_2loop_Bfs(Node node) {
        LinkedList<Node> que = new LinkedList<>();
        StringBuilder ans = new StringBuilder();
        que.addLast(node);
        while (que.size() != 0) {
            int size = que.size();
            while (size-- > 0) {
                Node front = que.removeFirst();
                
                ans.append(front.data + " ");

                if (front.left != null) {
                    que.addLast(front.left);
                }
                if (front.right != null) {
                    que.addLast(front.right);
                }
            }
            ans.append("\n");
        }
        return ans.toString();
    }
    private String lvl_print_queWithNull(Node node) {
        LinkedList<Node> que = new LinkedList<>();
        StringBuilder ans = new StringBuilder();
        que.addLast(node);
        que.addLast(null);
        while (que.size() != 1) {       //  1 because null would be left 
            Node front = que.removeFirst();
            if (front == null) {
                que.addLast(null);
                ans.append("\n");
                continue;
            }
            ans.append(front.data + " ");

            if (front.left != null) {
                que.addLast(front.left);
            }
            if (front.right != null) {
                que.addLast(front.right);
            }
        }
        return ans.toString();
    }

    /* ======================================= traversals ========================================== */


    /* =================================== if Node Class is public ========================================= */
    /**
     * @return Node - node of maximum integer value of tree
     */
    public Node maxNode() {
        return maxNode(this.root);
    }

    private Node maxNode(Node node) {
        if (node == null) {
            return new Node((int)-1e9);
        }
        Node ans;
        Node currMax = node;
        Node leftMax = maxNode(node.left);
        Node rightMax = maxNode(node.right);
        if (leftMax.data > rightMax.data) {
            ans = leftMax;
        } else {
            ans = rightMax;
        }
        if (ans.data > currMax.data) {
            return ans;
        }
        return currMax;
    }

    /**
     * @return Node - node of minimum integer value of tree
     */
    public Node minNode() {
        return minNode(this.root);
    }

    private Node minNode(Node node) {
        if (node == null) {
            return new Node((int)1e9);
        }
        Node ans;
        Node currMin = node;
        Node leftMin = minNode(node.left);
        Node rightMin = minNode(node.right);
        if (leftMin.data < rightMin.data) {
            ans = leftMin;
        } else {
            ans = rightMin;
        }
        if (ans.data < currMin.data) {
            return ans;
        }
        return currMin;
    }

    /**
     * to find the presence of data in the tree
     * @param data  - data to find
     * @return  Node (node of found data)
     * ( --- will contain subtree with found data node as root --- )
     */
    public Node findNode(int data) {
        return findNode(this.root, data);
    }

    private Node findNode(Node node, int data) {
        if (node == null)   return null;
        if (node.data == data)  return node;
        Node recAns = findNode(node.left, data);
        if (recAns == null) {
            recAns = findNode(node.right, data);
        }
        return recAns;
    }

    /**
     * method to return path from node to root
     * @param data - data from which path is needed
     * @return int[] - array of parents/path
     */
    public int[] rootToNodePath(int data) {
        //  uncomment for getting "root to node path" arrayList of Nodes
        /* 
        ArrayList<Node> temp1 = rootToNodePath_self_List(this.root, data);
        for (Node n : temp1) {
            System.out.print(n.data + " ");
        } System.out.println();
        */
        /* 
        ArrayList<Node> temp2 = rootToNodePath_taught(this.root, data);
        for (Node n : temp2) {
            System.out.print(n.data + " ");
        } System.out.println();
         */
        return rootToNodePath_self_arr(this.root, data);
    }

    /**
     * this will return an array of integer values containing path
     * from node to root
     * @param node  - root node of tree
     * @param data  - data to be found
     * @return int[] - array of path/parents
     */
    private int[] rootToNodePath_self_arr(Node node, int data) {
        if (node == null) {
            return new int[0];
        }
        if (node.data ==  data) {
            int[] base = new int[1];
            base[0] = node.data;
            return base;
        }
        int[] recAns = null;
        recAns = rootToNodePath_self_arr(node.left, data);
        if (recAns.length == 0) {
            recAns = rootToNodePath_self_arr(node.right, data);
        }
        if (recAns.length != 0) {
            int[] ans = new int[recAns.length + 1];
            ans[recAns.length] = node.data;
            for (int i = 0; i < recAns.length; i++) {
                ans[i] = recAns[i];
            }
            return ans;
        } else {
            return recAns;
        }
    }
    
    /**
     * this will return an arraylist of Nodes containing path
     * from node to root
     * @param node  - root node of tree
     * @param data  - data to be found
     * @return list - arraylist of parents/path
     */
    private ArrayList<Node> rootToNodePath_self_List(Node node, int data) {
        if (node == null) {
            return new ArrayList<>();
        }
        if (node.data ==  data) {
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }
        ArrayList<Node> recAns = null;
        recAns = rootToNodePath_self_List(node.left, data);
        if (recAns.size() == 0) {
            recAns = rootToNodePath_self_List(node.right, data);
        }
        if (recAns.size() != 0) {
            recAns.add(node);
        }
        return recAns;
    }
    
    /**
     * this will return an arraylist of Nodes containing path
     * from node to root
     * @param node  - root node of tree
     * @param data  - data to be found
     * @return list - arraylist of parents/path
     */
    private ArrayList<Node> rootToNodePath_taught(Node node, int data) {
        /**
         * we are not using null as base case as we are
         * using this method in other methods too as a helper function
         * where we need empty arraylist for data not present in tree
         * (if "null" then it will generate null pointer exception)
         */
        if (node == null) {
            return new ArrayList<>();
            // return null;
        }
        if (node.data ==  data) {
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }
        ArrayList<Node> left = rootToNodePath_taught(node.left, data);
        if (left.size() != 0) {    //  can be a check of left != null, if we return "null" from upper base case
            left.add(node);
            return left;
        }
        ArrayList<Node> right = rootToNodePath_taught(node.right, data);
        if (right.size() != 0) {    //  can be a check of right != null, if we return "null" from upper base case
            right.add(node);
            return right;
        }
        // return null;
        return new ArrayList<>();
    }

    /**
     * this method will find the lowest common ancestor(LCA)
     * of two nodes in a binary tree
     * (for any two nodes, root node is a common ancestor always, 
     * but not necessary to be a lowest common ancestor)
     * @return int - value of lowest common ancestor
     */
    public int lowestCommAnces(int data1, int data2) {
        //  LCA
        
        return LCA_withMemorySpace(this.root, data1, data2).data;
        
        // LCA_noExtraSpace(this.root, data1, data2);
        // return LCA.data;
    }

    private Node LCA_withMemorySpace(Node node, int data1, int data2) {
        ArrayList<Node> path1 = rootToNodePath_taught(node, data1);
        ArrayList<Node> path2 = rootToNodePath_taught(node, data2);
        int idx1 = path1.size() - 1, idx2 = path2.size() - 1;
        Node ans = new Node();
        while (idx1 >= 0 && idx2 >= 0) {
            if (path1.get(idx1) != path2.get(idx2)) {
                break;
            }
            ans = path1.get(idx1);
            idx1--;
            idx2--;
        }
        return ans;
    }

    private Node LCA = null;        //  global for containing ans
    private boolean LCA_noExtraSpace(Node node, int data1, int data2) {
        if (node == null) {
            return false;
        }
        boolean self = node.data == data1 || node.data == data2;
        boolean left = LCA_noExtraSpace(node.left, data1, data2);
        if (LCA != null) {
            return true;
        }
        boolean right = LCA_noExtraSpace(node.right, data1, data2);
        if ((left && right) || (left && self) || (right && self)) {
            LCA = node;
        }
        return left || right || self;
    }

    
    //================================= k down print =====================================
    // nodes at 'K' radii from a given node
    // LeetCode 863. All Nodes Distance K in Binary Tree
    /**
     * if the tree is made flat and spread in planar 
     * having passed node/node.data as center
     * then, it prints all the nodes at K'th distance
     */
    public void print_k_Away(int data, int k) {
        k_Away_01(this.root, data, k);
    }
    
    private void k_Away_01(Node node, int data, int k_dis) {
        ArrayList<Node> nodePath = rootToNodePath_taught(node, data);
        Node pNode = null;       //  prevent node, not to visit in tree as already visited and path is printed from that
        for (int i = 0; i < nodePath.size(); i++) {
            print_k_down(nodePath.get(i), pNode, k_dis - i);
            pNode = nodePath.get(i);
        }
        // for (int i = nodePath.size() - 1; i >= 0; i--) {
        //     pNode = (i == 0) ? null : nodePath.get(i - 1);
        //     print_k_down(nodePath.get(i), pNode, k_dis - i);
        // }
    }
    
    private void print_k_down(Node node, Node pNode, int level) {
        if (node == null || node == pNode) {
            return;
        }
        if (level == 0) {
            System.out.print(node.data + " ");
            return;
        }
        print_k_down(node.left, pNode, level - 1);
        print_k_down(node.right, pNode, level - 1);
    }
    //================================= k down print end =====================================
    
    //================================= k down return =====================================
    // nodes at 'K' radii from a given node
    // LeetCode 863. All Nodes Distance K in Binary Tree
    /**
     * if the tree is made flat and spread in planar 
     * having passed node/node.data as center
     * then, it prints all the nodes at K'th distance
     */
    public int[] get_k_Away(int data, int k) {
        ArrayList<Node> ans = k_Away_02(this.root, data, k);
        int[] intAns = new int[ans.size()];
        for (int i = 0; i < ans.size(); i++) {
            intAns[i] = ans.get(i).data;
        }
        return intAns;
    }
    
    private ArrayList<Node> k_Away_02(Node node, int data, int k_dis) {
        ArrayList<Node> nodePath = rootToNodePath_taught(node, data);
        Node pNode = null;       //  prevent node, not to visit in tree as already visited and path is printed from that
        ArrayList<Node> listAns = new ArrayList<>();
        for (int i = 0; i < nodePath.size(); i++) {
            ArrayList<Node> nodeAns = return_k_down(nodePath.get(i), pNode, k_dis - i);
            listAns.addAll(nodeAns);
            pNode = nodePath.get(i);
        }
        return listAns;
    }
    
    private ArrayList<Node> return_k_down(Node node, Node pNode, int level) {
        if (node == null || node == pNode) {
            return new ArrayList<>();
        }
        if (level == 0) {
            ArrayList<Node> base = new ArrayList<>();
            base.add(node);
            return base;
        }
        ArrayList<Node> recAns = new ArrayList<>();
        recAns.addAll(return_k_down(node.left, pNode, level - 1));
        recAns.addAll(return_k_down(node.right, pNode, level - 1));
        return recAns;
    }
    //================================= k down return end =====================================

    //================================= k down no space method return =====================================
    // nodes at 'K' radii from a given node
    // LeetCode 863. All Nodes Distance K in Binary Tree
    /**
     * if the tree is made flat and spread in planar 
     * having passed node/node.data as center
     * then, it return an arrayList of all the nodes at K'th distance
     * @return List<Integer> - arrayList of data of nodes needed
     */
    public ArrayList<Integer> get_k_Away_noSpace(int data, int k) {
        return rootToNodePath_k_Away_return(this.root, data, k);
    }
    
    private int dis = -1;
    private ArrayList<Integer> rootToNodePath_k_Away_return(Node node, int data, int K) {
        if (node == null) {
            dis = -1;
            return new ArrayList<>();
        }
        if (node.data == data) {
            ArrayList<Integer> base = K_down_noSpace_return(node, null, K);
            dis = 1;
            return base;
        }
        ArrayList<Integer> left = rootToNodePath_k_Away_return(node.left, data, K);
        if (dis != -1) {
            left.addAll(K_down_noSpace_return(node, node.left, K - dis));
            dis += 1;
            return left;
        }
        ArrayList<Integer> right = rootToNodePath_k_Away_return(node.right, data, K);
        if (dis != -1) {
            right.addAll(K_down_noSpace_return(node, node.right, K - dis));
            dis += 1;
            return right;
        }
        dis = -1;
        return new ArrayList<>();
    }
    
    private ArrayList<Integer> K_down_noSpace_return(Node node, Node noAcessNode, int K) {
        if (node == null || node == noAcessNode) {
            return new ArrayList<>();
        }
        if (K == 0) {
            ArrayList<Integer> base = new ArrayList<>();
            base.add(node.data);
            return base;
        }
        ArrayList<Integer> recAns = new ArrayList<>();
        recAns.addAll(K_down_noSpace_return(node.left, noAcessNode, K - 1));
        recAns.addAll(K_down_noSpace_return(node.right, noAcessNode, K - 1));
        return recAns;
    }
    //================================= k down no space method return end =====================================

    //================================= k down no space return method =====================================
    // nodes at 'K' radii from a given node
    // LeetCode 863. All Nodes Distance K in Binary Tree
    /**
     * if the tree is made flat and spread in planar 
     * having passed node/node.data as center
     * then, it prints all the nodes at K'th distance
     */
    public void print_k_Away_noSpace(int data, int k) {
        rootToNodePath_k_Away(this.root, data, k);
    }

    private int rootToNodePath_k_Away(Node node, int data, int K) {
        if (node == null) {
            return -1;
        }
        if (node.data == data) {
            K_down_noSpace(node, null, K);
            return 1;
        }
        int leftDis = rootToNodePath_k_Away(node.left, data, K);
        if (leftDis != -1) {
            K_down_noSpace(node, node.left, K - leftDis);
            return leftDis + 1;
        }
        int rightDis = rootToNodePath_k_Away(node.right, data, K);
        if (rightDis != -1) {
            K_down_noSpace(node, node.right, K - rightDis);
            return rightDis + 1;
        }
        return -1;
    }
    
    private void K_down_noSpace(Node node, Node noAcessNode, int K) {
        if (node == null || node == noAcessNode) {
            return;
        }
        if (K == 0) {
            System.out.print(node.data + " ");
            return;
        }
        K_down_noSpace(node.left, noAcessNode, K - 1);
        K_down_noSpace(node.right, noAcessNode, K - 1);
    }
    //================================= k down no space method return end =====================================

}