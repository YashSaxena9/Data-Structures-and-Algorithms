import java.util.BitSet;

class Solution {
    //     public int lengthOfLongestSubstring(String s) {
    //         int length = 0;
    //         for (int i = 0; i < s.length(); i++) {
    //             for (int j = i + 1; j <= s.length(); j++) {
    //                 String temp = s.substring(i, j);
    //                 if (haveNoRepeat(temp) && temp.length() > length) {
    //                     length = temp.length();
    //                 }
    //             }
    //         }
    //         return length;
    //     }
        
    //     private boolean haveNoRepeat(String str) {
    //         BitSet vis = new BitSet(26);
    //         for (int i = 0; i < str.length(); i++) {
    //             if (!vis.get(str.charAt(i) - ' ')) {
    //                 vis.set(str.charAt(i) - ' ');
    //             } else {
    //                 return false;
    //             }
    //         }
    //         return true;
    //     }
    public int lengthOfLongestSubstring(String s) {
        int[] charArr = new int[256];
        int ptr1 = 0, ptr2 = 0;
        int len = 0, finLen = len;
        charArr[s.charAt(ptr2) - ' ']++;
        while (ptr2 < s.length() - 1) {
            if (charArr[s.charAt(ptr2) - (char)0] <= 1) {
                System.out.println(s.charAt(ptr2));
                len++;
                ptr2++;
                charArr[s.charAt(ptr2) - (char)0]++;
            }
            else {
                ptr1++;
                charArr[s.charAt(ptr1) - (char)0]--;
                finLen = Math.max(finLen, len);
            }
        }
        return finLen;
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