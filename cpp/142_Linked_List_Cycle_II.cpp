// 142. Linked List Cycle II
/**
 * Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
 * 
 * Note: Do not modify the linked list.
 *
 * Follow up:
 * Can you solve it without using extra space?
 * 
 * Tags: Linked List, Two Pointers
 * 
 * Similar Problems:  (E) Linked List Cycle, (M) Find the Duplicate Number
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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // Suppose they first meet at step k, the length of the Cycle is r. 
            // so 2k - k = nr, let n = 1, we have k = r
            // m is the distance between start node of the cycle and first meeting node
            // need (r - m) step to reach the start node of the cycle
            // s is distance between the start node of list and the start node of cycle
            // from the slow pointer: s = k - m
            // ... - s - ... m ... - k
            //       |               |
            //      ...    r - m    ...
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                
                return slow;
            }
        }
        
        return NULL;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    node5.next = &node3;
    cout << &node3 << endl;
    Solution sol;
    ListNode *p = sol.detectCycle(&node1);
    cout << p << endl;
    cin.get();
    
    return 0;
}