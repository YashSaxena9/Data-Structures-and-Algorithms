/**
 * avlTree
 */
public class avlTree {
    public static class Node {
        int data;
        Node left;
        Node right;

        int height = -1;    //  for avl
        int bal = 0;        //  for avl

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
            str += ((left != null ? left.data + " (" + left.bal + ") " : "."));
            str += (" -> " + data + " <- ");
            str += ((right != null ? right.data + " (" + right.bal + ") ": "."));
            str += "\n";
            if (left != null)
                str += left.toString();
            if (right != null)
                str += right.toString();
            return str;
        }
    }

    private static int idx = 0;
    //  for pre order
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

    public static void display(Node node) {
        if (node == null)
            return;
        System.out.print((node.left != null ? node.left.data : "."));
        System.out.print(" -> " + node.data + " <- ");
        System.out.println((node.right != null ? node.right.data : "."));
        display(node.left); // display(2*idx+1);
        display(node.right); // display(2*idx+2);
    }
    
    public static int minInTree(Node node) {
        if (node == null) {
            return Integer.MAX_VALUE;
        }
        Node rnode = node;
        while (node.left != null) {
            rnode = rnode.left;
        }
        return node.data;
    }

    public static int maxInTree(Node node) {
        if (node == null) {
            return Integer.MIN_VALUE;
        }
        Node rnode = node;
        while (node.right != null) {
            rnode = rnode.right;
        }
        return node.data;
    }

    //  modified for avl
    public static Node addNode(Node node, int data) {
        if (node == null) {
            return new Node(data);
        }
        if (data < node.data) {
            node.left = addNode(node.left, data);
        } else {
            node.right = addNode(node.right, data);
        }
        node = rotate(node);
        return node;
    }
    
    //  modified for avl
    public static Node removeNode(Node node, int data) {
        if (node == null) {
            return null;
        }
        if (node.data == data) {
            if (node.left == null || node.right == null) {
                return (node.left == null) ? node.right : node.left;
            }
            int maxData = maxInTree(node.left);
            node.data = maxData;
            node.left = removeNode(node.left, maxData);
        } else if (data < node.data) {
            removeNode(node.left, data);
        } else {
            removeNode(node.right, data);
        }
        node = rotate(node);
        return node;
    }

    //  =================== avl start =================================
    //  rotations
    private static Node ll(Node node) {     //  left left rotation
        Node leftNode = node.left;
        Node leftNode_right = leftNode.right;
        leftNode.right = node;
        node.left = leftNode_right;
        updateHeightBalance(node);
        updateHeightBalance(leftNode);
        return leftNode;
    }
    
    private static Node rr(Node node) {     //  right right rotation
        Node rightNode = node.right;
        Node rightNode_left = rightNode.left;
        rightNode.left = node;
        node.right = rightNode_left;
        updateHeightBalance(node);
        updateHeightBalance(rightNode);
        return rightNode;
    }

    private static void updateHeightBalance(Node node) {
        int lh = -1, rh = -1;
        if (node.left != null) {
            lh = node.left.height;
        }
        if (node.right != null) {
            rh = node.right.height;
        }
        node.height = Math.max(lh, rh) + 1;
        node.bal = lh - rh;
    }
    
    public static Node rotate(Node node) {
        updateHeightBalance(node);
        if (node.bal == 2) {
            if (node.left.bal == 1) {
                node = ll(node);
            } else if (node.left.bal == -1) {
                node.left = rr(node.left);
                node = ll(node);
            }
        } else if (node.bal == -2) {
            if (node.right.bal == -1) {
                node = rr(node);
            } else if (node.right.bal == 1) {
                node.right = ll(node.right);
                node = rr(node);
            }
        }
        return node;
    }

    //  =================== main =====================================
    public static void solve() {
        Node root = null;
        for (int i = 1; i <= 20; i++) {
            root = addNode(root, i);
        }
        System.out.println(root);
    }
    public static void main(String[] args) {
        solve();
    }
}