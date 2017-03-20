// 83. Remove Duplicates from Sorted List
/**
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 * 
 * Tags: Linked List
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *curr = head;
        while (curr != NULL) {
            // search and delete duplicates
            while (curr->next != NULL && curr->next->val == curr->val) {
                curr->next = curr->next->next;
            }
            
            // move forward
            curr = curr->next;
        }
        
        return head;
    }
};

// recursive
class Solution_Recursive {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        head->next = deleteDuplicates(head->next);
        
        // duplicates
        if (head->val == head->next->val) {
            return head->next;
        }
        
        return head;
    }
};

int main() {
    ListNode node5(3), node4(2, &node5), node3(2, &node4), node2(1, &node3), node1(1, &node2);
    Solution sol;
    ListNode *newhead = sol.deleteDuplicates(&node1);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}