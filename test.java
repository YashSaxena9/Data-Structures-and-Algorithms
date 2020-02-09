import java.util.BitSet;
import java.util.LinkedList;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    HashMap<TreeNode, TreeNode> parents = new HashMap<>();

    private void dfs_preOrder(TreeNode node, TreeNode parent) {
        if (node == null) {
            return;
        }
        parents.put(node, parent);
        dfs_preOrder(node.left, node);
        dfs_preOrder(node.right, node);
    }

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        dfs_preOrder(root, null);
        LinkedList<TreeNode> que = new LinkedList<>();
        que.addLast(root);
        while (que.size() != 0) {
            int size = que.size();
            while (size-- > 0) {
                if (K == 0) {
                    parents.get
                }
                TreeNode front = que.removeFirst();

            }
        }
        return null;
    }
}

/**
 * test
 */
public class test {
    public static void main(String[] args) {
        Solution ans = new Solution();
        // System.out.println("->" + (char)64 + "<-");
        // System.out.println(ans.lengthOfLongestSubstring("abcabcbb"));
    }
}