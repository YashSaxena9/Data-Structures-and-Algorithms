/**
 * ______Approach______ :-
 * making a new linked list and adding sum of each node to a new node pf the list
 * removind carry from sum by % and / by 10
 * doing same and adding carry too next time
 */
#include<iostream>
#include<vector>
using namespace std;

//  ============================ list nodes(part of ques) ========================
class ListNode {
private:
public:
    int val;
    ListNode* next = nullptr;
    ListNode(int x) {
        this->val = x;
    }
    
    ListNode(vector<int>& x) {
        if (x.size() == 0) {
            return;
        }
        ListNode* temp = this;
        for (int i = 0; i < x.size(); i++) {
            if (i == 0) {
                temp->val = x[i];
            }
            else {
                temp->next = new ListNode(x[i]);
                temp = temp->next;
            }
        }
    }

    void add(int num) {
        ListNode* temp = this;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new ListNode(num);
    }

    void print() {
        ListNode* temp = this;
        while (temp->next != nullptr) {
            cout << temp->val << "->";
            temp = temp->next;
        }
        cout << temp->val << endl;
    }
};
//  =================================================================

//  ================================= Solution ===================================
class Solution {
private:
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr, *temp = nullptr;
        int carry = 0, sum = 0;
        while (l1 != nullptr || l2 != nullptr) {
            sum += carry;
            sum += (l1 != nullptr) ? l1->val : 0;
            sum += (l2 != nullptr) ? l2->val : 0;
            carry = sum / 10;
            sum = sum % 10;
            if (res == nullptr) {
                res = new ListNode(sum);
                temp = res;
            } else {
                temp->next = new ListNode(sum);
                temp = temp->next;
            }
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                l2 = l2->next;
            }
            sum = 0;
        }
        if (carry != 0) {
            temp->next = new ListNode(carry);
        }
        return res;
    }
};
//  ===========================================================================

int main(int args, char**argv) {
    ListNode* lst1 = new ListNode(vector<int>()={2,4,9});
    ListNode* lst2 = new ListNode(vector<int>()={5,6,4});
    lst1->print();
    lst2->print();
    Solution* sol = new Solution();
    sol->addTwoNumbers(lst1, lst2)->print();
}