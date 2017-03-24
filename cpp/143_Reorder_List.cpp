// 143. Reorder List
/**
 * Given a singly linked list L: L0->L1->...->Ln-1->Ln,
 * reorder it to: L0->Ln->L1->Ln-1->L2->Ln-2->...
 * 
 * You must do this in-place without altering the nodes' values.
 * 
 * For example,
 * Given {1,2,3,4}, reorder it to {1,4,2,3}.
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
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return;
        }
        
        // divide the list into two parts
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the second part of the list from slow->next
        ListNode *curr = slow->next, *prev = NULL;
        while (curr != NULL) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        
        // connect two lists
        slow->next = NULL;
        while (head != NULL && prev != NULL) {
            ListNode *next = prev->next;
            prev->next = head->next;
            head->next = prev;
            head = prev->next;
            prev = next;
        }
        
        return;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    ListNode *head = &node1;
    sol.reorderList(head);
    for (ListNode *p = head; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}