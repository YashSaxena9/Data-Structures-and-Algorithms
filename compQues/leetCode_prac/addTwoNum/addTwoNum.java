/**
 * ______Approach______ :-
 * making a new linked list and adding sum of each node to a new node pf the list
 * removind carry from sum by % and / by 10
 * doing same and adding carry too next time
 */

import java.util.Scanner;

//  ================================= Solution ===================================
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode res = null, temp = null;
        int carry = 0, sum = 0;
        while (l1 != null || l2 != null) {
            sum += carry;
            sum += (l1 != null) ? l1.val : 0;
            sum += (l2 != null) ? l2.val : 0;
            carry = sum / 10;
            sum = sum % 10;
            if (res == null) {
                res = new ListNode(sum);
                temp = res;
            } else {
                temp.next = new ListNode(sum);
                temp = temp.next;
            }
            if (l1 != null) {
                l1 = l1.next;
            }
            if (l2 != null) {
                l2 = l2.next;
            }
            sum = 0;
        }
        if (carry != 0) {
            temp.next = new ListNode(carry);
        }
        return res;
    }
}
//  ===========================================================================

//  ============================ list nodes(part of ques) ========================
class ListNode {
    public int val;
    public ListNode next;
    ListNode(int x) {
        this.val = x;
    }
    
    ListNode(int[] x) {
        if (x.length == 0) {
            return;
        }
        ListNode temp = this;
        for (int i = 0; i < x.length; i++) {
            if (i == 0) {
                temp.val = x[i];
            }
            else {
                temp.next = new ListNode(x[i]);
                temp = temp.next;
            }
        }
    }

    public void add(int num) {
        ListNode temp = this;
        while (temp.next != null) {
            temp = temp.next;
        }
        temp.next = new ListNode(num);
    }

    public void print() {
        ListNode temp = this;
        while (temp.next != null) {
            System.out.print(temp.val + "->");
            temp = temp.next;
        }
        System.out.println(temp.val);
    }
}
//  =================================================================

/**
 * twoSum
 */
public class addTwoNum {
    private static Scanner scn = new Scanner(System.in);
    public static void main(String[] args) {
        ListNode lst1 = new ListNode(new int[] {2,4,9});
        ListNode lst2 = new ListNode(new int[] {5,6,4});
        lst1.print();
        lst2.print();
        Solution sol = new Solution();
        sol.addTwoNumbers(lst1, lst2).print();
    }
}