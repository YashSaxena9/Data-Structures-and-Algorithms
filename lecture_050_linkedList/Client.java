/**
 * Client
 */
public class Client {

    public static void main(String[] args) {
        linkedList<Character> ll = new linkedList<>();
        System.out.println(ll);
        ll.addFirst((char)(10 + 'a'));
        ll.addLast((char)(20 + 'b'));
        ll.addLast((char)(30 + 'c'));
        System.out.println(ll);
        ll.setAt(1, (char)(90 + 'a'));
        System.out.println(ll);
        ll.reverseList();
        System.out.println(ll);
    }
}



/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
/* public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null) return false;
        ListNode slow = head.next;
        ListNode fast = head.next.next;
        while (fast != slow) {
            slow = slow.next;
            fast = fast.next.next;
            if (fast.next == null || fast == null) {
                return false;
            }
        }
        return true;
    }
} */


/* 
//  is palindrome
bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }
    ListNode* mid = middleNodeByIndex(head);
    ListNode* nhead = mid->next;
    mid->next = nullptr;
    nhead= reverseList(nhead);
    ListNode* curr1 = head;
    ListNode* curr2 = nhead;

    while (curr1 != nullptr && curr2 != nullptr) {
        if (curr1->val != curr2->val) {
            return false;
        }
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    nhead = reverseList(nhead);
    mid->next = nhead;
    return true;
} */