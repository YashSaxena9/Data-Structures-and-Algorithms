import java.util.LinkedList;
import java.util.Stack;
/**
 * avlTree
 */
public class avlTree {
    public static class Node {
        int data = 0;
        Node left = null;
        Node right = null;

        int height = 0;
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

        // @Override
        // public String toString() {
        //     Node curr = this;
        //     StringBuilder str = new StringBuilder();
        //     while (curr != null) {
        //         Node nextLeft = curr.left;
        //         if (nextLeft == null) {
        //             str.append((curr.left != null ? curr.left.data + " (" + curr.left.bal + ")" : "."));
        //             str.append(" -> " + curr.data + " <- ");
        //             str.append((curr.right != null ? curr.right.data + " (" + curr.right.bal + ")" : "."));
        //             str.append("\n");
        //             curr = curr.right;
        //         } else {
        //             Node rightMost = nextLeft;
        //             while (rightMost.right != null && rightMost.right != curr) {
        //                 rightMost = rightMost.right;
        //             }
        //             if (rightMost.right == null) {
        //                 str.append((curr.left != null ? curr.left.data + " (" + curr.left.bal + ")" : "."));
        //                 str.append(" -> " + curr.data + " <- ");
        //                 str.append((curr.right != null ? curr.right.data + " (" + curr.right.bal + ")" : "."));
        //                 str.append("\n");
        //                 rightMost.right = curr;     //  create thread
        //                 curr = curr.left;
        //             } else {
        //                 rightMost.right = null;     //  break thread
        //                 curr = curr.right;
        //             }
        //         }
        //     }
        //     return str.toString();
        // }


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
    //  for pre order
    public static Node createTree(int[] preOrd) {
        if (idx == preOrd.length || preOrd[idx] == -1) {
            idx++;
            return null;
        }
        Node node = new Node(preOrd[idx]);
        idx++;
        node.left = createTree(preOrd);
        node.right = createTree(preOrd);

        return node;
    }

    public static Node makeBST(int[] inOrd, int si, int ei) {
        if (si > ei) {
            return null;
        }
        int mid = (si + ei) >> 1;
        Node node = new Node(inOrd[mid]);
        node.left = makeBST(inOrd, si, mid - 1);
        node.right = makeBST(inOrd, mid + 1, ei);

        node=rotate(node);
        return node;
    }

    public static void display(Node node) {
        if (node == null)
            return;
        System.out.print((node.left != null ? node.left.data + " (" + node.left.bal + ")" : "."));
        System.out.print(" -> " + node.data + " <- ");
        System.out.println((node.right != null ? node.right.data + " (" + node.right.bal + ")" : "."));
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
        return rotate(node);
        
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
            node.left = removeNode(node.left, data);
        } else {
            node.right = removeNode(node.right, data);
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
        // if (node == null)   return;
        int lh = -1, rh = -1;       //  default value if nodes are null
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
        if (node.bal == 2) {                                   // if (node.bal == 2) {
            if (node.left.bal == 1) {                          // if (node.left.bal == 1) {
                return ll(node);
            } else {                   // } else if (node.left.bal == -1) {
                node.left = rr(node.left);
                return ll(node);
            }
        } else if (node.bal == -2) {                           // } else if (node.bal == -2) {
            if (node.right.bal == -1) {                         // if (node.right.bal == -1) {
                return rr(node);
            } else  {                  // } else if (node.right.bal == 1) {
                node.right = ll(node.right);
                return rr(node);
            }
        }
        return node;
    }
    
    //  =================== main =====================================
    public static void solve() {
        // int[] arr = {10};
        // Node root = makeBST(arr, 0, 0);
        Node root=null;
        for (int i = 1; i <= 20; i++) {
            root = addNode(root, i * 10);
        }
        // System.out.println(root);
        display(root);
        // System.out.println(root);
    }
    public static void main(String[] args) {
        solve();
    }
}