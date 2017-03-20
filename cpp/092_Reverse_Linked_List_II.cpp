// 92. Reverse Linked List II
/**
 * Reverse a linked list from position m to n. Do it in-place and in one-pass.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 * 
 * return 1->4->3->2->5->NULL.
 * 
 * Note:
 * Given m, n satisfy the following condition:
 * 1 <= m <= n <= length of list.
 * 
 * Tags: Linked List
 *
 * Similar Problems: (E) Reverse Linked List
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) {
            return NULL;
        }
        
        // a dummy node to mark the head of the list
        ListNode dummy(0);
        dummy.next = head;
        
        // find the node before reversing
        ListNode *pre = &dummy;
        for (int i = 0; i < m - 1; i++) {
            pre = pre->next;
        }
        
        // reverse the sub-list
        ListNode *curr = pre->next, *next = curr->next;
        for (int i = m; i < n; i++) {
            curr->next = next->next;
            next->next = pre->next;
            pre->next = next;
            next = curr->next;
        }
        
        return dummy.next;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    ListNode *newhead = sol.reverseBetween(&node1, 2, 4);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
} 
