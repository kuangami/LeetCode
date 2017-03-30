// 237. Delete Node in a Linked List
/**
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 * 
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 
 * after calling your function.
 * 
 * Tags: Linked List
 * 
 * Similar Problems: (E) Remove Linked List Elements
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
    void deleteNode(ListNode* node) {
        *node = *(node->next);
        
        // equivalent to copy the values:
        // node->val = node->next->val;
        // node->next = node->next->next;
        return;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    sol.deleteNode(&node3);
    for (ListNode *p = &node1; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
} 