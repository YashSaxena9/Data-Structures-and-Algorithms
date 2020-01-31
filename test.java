import java.util.BitSet;

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int length = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                String temp = s.substring(i, j);
                if (haveNoRepeat(temp) && temp.length() > length) {
                    length = temp.length();
                }
            }
        }
        return length;
    }
    
    private boolean haveNoRepeat(String str) {
        BitSet vis = new BitSet(26);
        for (int i = 0; i < str.length(); i++) {
            if (!vis.get(str.charAt(i) - 'A')) {
                vis.set(str.charAt(i) - 'A');
            } else {
                return false;
            }
        }
        // System.out.println(vis);
        return true;
    }
}

/**
 * test
 */
public class test {
    public static void main(String[] args) {
        Solution ans = new Solution();
        // System.out.println("->" + (char)64 + "<-");
        System.out.println(ans.lengthOfLongestSubstring("abcabcbb"));
    }
}