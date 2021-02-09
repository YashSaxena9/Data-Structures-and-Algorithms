import java.util.*;
/**
 * verticalTrav
 */
public class verticalTrav {
    static class Node {
        int val;
        Node left, right;
        Node() {
            this(0, null, null);
        }
        Node(int val) {
            this(val, null, null);
        }
        
        Node(int val, Node left, Node right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }
    
    static class Solution {
        int leftMost = -1, rightMost = -1;
        private int width_andSize(Node node, int lvl) {
            if (node == null) return 0;
            int size = 1;
            leftMost = Math.min(leftMost, lvl);
            rightMost = Math.max(rightMost, lvl);
            size += width_andSize(node.left, lvl - 1);
            size += width_andSize(node.right, lvl + 1);
            return size;
        }

        public List<List<Integer>> verticalTraversal(Node root) {
            LinkedList<Node> que1 = new LinkedList<>();
            LinkedList<Integer> que2 = new LinkedList<>();
            int treeSize = width_andSize(root, 0);
            List<List<Integer>> list = new ArrayList<>(rightMost - leftMost);
            for (int i = 0; i < (rightMost - leftMost); i++) list.add(new ArrayList<>());
            if ((1 & treeSize) == 1) list.add(new ArrayList<>());
            
            que1.addLast(root);
            que2.addLast(-leftMost);
            while (que1.size() != 0) {
                int size = que1.size();
                System.out.println(list);
                while (size --> 0) {
                    Node rnode = que1.removeFirst();
                    int rdata = que2.removeFirst();
                    list.get(rdata).add(rnode.val);
                    if (rnode.left != null) {
                        que1.addLast(rnode.left);
                        que2.addLast(rdata - 1);
                    }
                    if (rnode.right != null) {
                        que1.addLast(rnode.right);
                        que2.addLast(rdata + 1);
                    }
                }
            }
            // System.out.println(list);
            return list;
        }
    }

    public static Node mkTreeLvlOrder(Integer[] arr, int idx) {
        if (idx >= arr.length || arr[idx] == null) {
            return null;
        }
        Node node = new Node(arr[idx]);
        node.left = mkTreeLvlOrder(arr, 2 * idx + 1);
        node.right = mkTreeLvlOrder(arr, 2 * idx + 2);
        return node;
    }
    public static void main(String[] args) {
        Integer[] arr = {0, null, 1};
        Node root = mkTreeLvlOrder(arr, 0);
        Solution ans = new Solution();
        System.out.println(ans.verticalTraversal(root));
    }
}
