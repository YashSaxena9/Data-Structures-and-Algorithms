//  leetcode 208, 211, 212, 472, 642
// query on strings codechef --> NPLFLF


public class trieBasic {
    public class Node {
        int wordEnd = 0;
        String word = "";
        Node[] childs;

        Node() {
            this.childs = new Node[26];
            this.wordEnd = 0;
        }
    }

    Node root = null;
    public void insert(String word) {
        Node curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int idx = word.charAt(i) - 'a';
            if (curr.childs[idx] == null) {
                curr.childs[idx] = new Node();
            }
            curr = curr.childs[idx];
        }
        curr.wordEnd++;
    }

    public boolean search(String word) {
        Node curr = root;
        int n = word.length();
        for (int i = 0; i < n; i++) {
            int idx = word.charAt(i) - 'a';
            curr = curr.childs[idx];
            if (curr == null) {
                return false;
            }
        }
        return curr.wordEnd > 0;
    }

    public boolean search_wild(String word) {
        return searchWithUnknown(root, 0, word);
    }
    private boolean searchWithUnknown(Node node, int si, String word) {     //  for words like a.ad for word abad
        if (node == null) return false;
        if (si == word.length()) return node.wordEnd != 0;

        boolean res = false;
        if (word.charAt(si) == '.') {
            for (int i = 0; i < 26; i++) {
                if (node.childs[i] != null) {
                    res = res || searchWithUnknown(node.childs[i], si + 1, word);
                }
            }
        } else {
            int idx = word.charAt(si) - 'a';
            if (node.childs[idx] != null) {
                res = res || searchWithUnknown(node.childs[idx], si + 1, word);
            }
        }
        return res;
    }

    public boolean startsWith(String prefix) {      //  cheack prefix, not necessary to have word end
        Node curr = root;
        int n = prefix.length();
        for (int i = 0; i < n; i++) {
            int idx = prefix.charAt(i) - 'a';
            curr = curr.childs[idx];
            if (curr == null) {
                return false;
            }
        }
        return true;
    }
}