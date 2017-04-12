// 24. Swap Nodes in Pairs
/**
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
 * 
 * Tags: Linked List
 * 
 * Similar Problems: (H) Reverse Nodes in k-Group
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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        
        return next;
    }
};

// dummy pointer
class Solution_Dummy {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0), *pre = &dummy;
        pre->next = head;
        
        while (pre->next != NULL && pre->next->next != NULL) {
            // start: dummy->a->b->c
            ListNode *curr = pre->next, *next = curr->next;     // pre: dummy, curr: a, next: b
            curr->next = next->next;                            // point a->next to c
            next->next = curr;                                  // point b->next to a
            pre->next = next;                                   // point dummy->next to b
            pre = curr;                                         // pre: a, go to next pair
            // finish: dummy->b->a->c
        }
        
        return dummy.next;
    }
};

// pointer to pointer
class Solution_PP {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode **pp = &head, *curr = head;
        
        while (curr != NULL && curr->next != NULL) {
            // start: head->a->b->c
            ListNode *next = curr->next;    // curr: a, next: b, pp: &head
            curr->next = next->next;        // point a->next to c
            next->next = curr;              // point b->next to a
            *pp = next;                     // point head to b
            pp = &(curr->next);             // pp: &(a->next), go to next pair
            curr = *pp;                     // curr: c
            // finish: head->b->a->c
        }
        
        return head;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    ListNode *newhead = sol.swapPairs(&node1);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}