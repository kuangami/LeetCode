// 141. Linked List Cycle
/**
 * Given a linked list, determine if it has a cycle in it.
 * 
 * Follow up:
 * Can you solve it without using extra space?
 * 
 * Tags: Linked List, Two Pointers
 * 
 * Similar Problems: (M) Linked List Cycle II
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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        
        ListNode *slow = head, *fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            // fast will catch up with slow if there is cycle
            if (slow == fast) {
                return true;
            }
        }
        
        return false;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    node5.next = &node1;
    Solution sol;
    bool ans = sol.hasCycle(&node1);
    cout << ans << endl;
    cin.get();
    
    return 0;
}