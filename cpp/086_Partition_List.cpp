// 86. Partition List
/**
 * Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the two partitions.
 * 
 * For example,
 * Given 1->4->3->2->5->2 and x = 3,
 * return 1->2->2->4->3->5.
 * 
 * Tags: Linked List Two Pointers
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
    ListNode* partition(ListNode* head, int x) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // build two lists: l1 < x, l2 >= x
        ListNode node1(0), node2(0);
        ListNode *p1 = &node1, *p2 = &node2;
        
        while (head != NULL) {
            if (head->val < x) {
                p1->next = head;
                p1 = p1->next;
            }
            else {
                p2->next = head;
                p2 = p2->next;
            }
            
            head = head->next;
        }
        
        p2->next = NULL;        // the last element
        p1->next = node2.next;  // connect two lists
        return node1.next;
    }
};

int main() {
    ListNode node6(2), node5(5, &node6), node4(2, &node5), node3(3, &node4), node2(4, &node3), node1(1, &node2);
    Solution sol;
    ListNode *p = sol.partition(&node1, 3);
    while (p != NULL) {
        cout << p->val << " ";
        p = p->next;
    }
    cin.get();
    
    return 0;
}