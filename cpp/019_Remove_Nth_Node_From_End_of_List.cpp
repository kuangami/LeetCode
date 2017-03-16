// 19. Remove Nth Node From End of List
/**
 * Given a linked list, remove the nth node from the end of list and return its head.
 * 
 * For example,
 * 
 * Given linked list: 1->2->3->4->5, and n = 2.
 * 
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * 
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
 * 
 * Tags: Linked List, Two Pointers
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // use a dummy node to mark the head of the list
        ListNode dummy(0);
        dummy.next = head;
        
        // set two pointer difference by n
        ListNode *slow = &dummy, *fast = slow;
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }
        
        // move fast to the last element
        // find the node to be removed: slow->next
        while (fast->next != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
        
        // remove the node
        fast = slow->next;
        slow->next = fast->next;
        delete fast;
        
        return dummy.next;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    ListNode *newhead = sol.removeNthFromEnd(&node1, 5);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}