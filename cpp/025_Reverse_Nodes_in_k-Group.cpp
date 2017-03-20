// 25. Reverse Nodes in k-Group
/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out 
 * 0nodes in the end should remain as it is.
 * 
 * You may not alter the values in the nodes, only nodes itself may be changed.
 * 
 * Only constant memory is allowed.
 * 
 * For example,
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Tags: Linked List
 * 
 * Similar Problems: (M) Swap Nodes in Pairs
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

// recursive solution
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head;
        int count = 0;
        // find (k + 1)th node
        while (curr != NULL && count != k) {
            curr = curr->next;
            count++;
        }
        
        if (count == k) {
            curr = reverseKGroup(curr, k);      // reverse rest of the list
            while (count-- > 0) {
                ListNode *next = head->next;    // save head->next
                head->next = curr;              // point head->next to rest of the reversed list
                curr = head;                    // move head forward to reverse the list
                head = next;
            }
            
            head = curr;    // save for output
        }
        
        return head;
    }
};

// iterative solution
class Solution_Iterative {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;
        int count = 0;
        
        // find length of the list
        ListNode *curr = head, *pre = &dummy;
        while (curr != NULL) {
            curr = curr->next;
            count++;
        }
        
        while (count >= k) {
            curr = pre->next;
            ListNode *next = curr->next;
            for (int i = 1; i < k; i++) {   // needs (k - 1) operations
                // start: pre->a->b->c, curr: a, next: b
                curr->next = next->next;    // point a->next to c
                next->next = pre->next;     // point b->next to a
                pre->next = next;           // point pre->next to b
                next = curr->next;          // move forward, curr: a, next: c
                // finish: pre->b->a->c
            }
            
            // point the pre to the end of reversed sub-list
            pre = curr;    // after the loop, curr becomes the tail
            count -= k;
        }
        
        return dummy.next;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    ListNode *newhead = sol.reverseKGroup(&node1, 3);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}