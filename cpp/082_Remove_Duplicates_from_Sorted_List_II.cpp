// 82. Remove Duplicates from Sorted List II
/**
 * Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
 * 
 * For example,
 * Given 1->2->3->3->4->4->5, return 1->2->5.
 * Given 1->1->1->2->3, return 2->3.
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
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // dummy node to mark head position
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *pre = &dummy, *curr = head;
        while (curr != NULL) {
            while (curr->next != NULL && curr->val == curr->next->val) {
                curr = curr->next;
            }
            
            if (pre->next == curr) {    // curr has unique values
                pre = curr;
            }
            else {  // curr to be deleted
                pre->next = curr->next;
            }
            
            curr = curr->next;
        }
        
        return dummy.next;
    }
};

// pointer to pointer
class Solution_PP {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // **pp to mark head position
        ListNode **pp = &head;
        
        while (*pp != NULL) {
            ListNode *curr = *pp;
            while (curr->next != NULL && curr->val == curr->next->val) {
                curr = curr->next;
            }
            
            if (*pp == curr) {    // curr has unique values
                pp = &(curr->next);
            }
            else {  // curr to be deleted
                *pp = curr->next;
            }
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

        ListNode *next = head->next;
        if (head->val != next->val) {   // head has unique values
            head->next = deleteDuplicates(next);
            return head;
        }
        
        // head to be deleted
        while (next != NULL && head->val == next->val) {
            next = next->next;
        }
        
        return deleteDuplicates(next);
    }
};

int main() {
    ListNode node5(3), node4(3, &node5), node3(3, &node4), node2(1, &node3), node1(1, &node2);
    Solution sol;
    ListNode *newhead = sol.deleteDuplicates(&node1);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}