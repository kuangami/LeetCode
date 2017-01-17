// 2. Add Two Numbers
/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * 
 * Subscribe to see which companies asked this question
 * 
 * Tags: Linked List, Math
 * 
 * Similar Problems: (M) Multiply Strings, (E) Add Binary, (E) Sum of Two Integers, (E) Add Strings, (M) Add Two Numbers II
 * 
 * Author: Kuang Qin
 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *p) : val(x), next(p) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(0), *curr = &head;
        int sum = 0;
        while (l1 != NULL || l2 != NULL || sum) {
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            curr->next = new ListNode(sum % 10);    // add node
            curr = curr->next;  // move curr to the last element
            sum /= 10;  // save the carry
        }
        
        return head.next;
    }
};

int main() {
    // 999 + 1 = ?
    ListNode l1_3(9), l1_2(9, &l1_3), l1_1(9, &l1_2);
    ListNode l2_1(1);
    Solution sol;
    ListNode *res = sol.addTwoNumbers(&l1_1, &l2_1);
    for (ListNode *p = res; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}