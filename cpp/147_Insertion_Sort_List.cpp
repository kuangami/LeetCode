// 147. Insertion Sort List
/**
 * Sort a linked list using insertion sort.
 * 
 * Tags: Linked List, Sort
 * 
 * Similar Problems (M) Sort List
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <climits>

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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dummy(INT_MIN);
        ListNode *prev = &dummy, *curr = head;
        
        while (curr != NULL) {
            // reset searching pointer to begining only when needed
            if (prev->val > curr->val) {
                prev = &dummy;
            }
            
            while (prev->next != NULL && prev->next->val < curr->val) {
                prev = prev->next;
            }
            
            // insert between prev and prev->next
            ListNode *next = curr->next;
            curr->next = prev->next;
            prev->next = curr;
            curr = next;
        }
        
        return dummy.next;
    }
};

int main() {
    ListNode node5(3), node4(5, &node5), node3(4, &node4), node2(-1, &node3), node1(2, &node2);
    Solution sol;
    ListNode *newhead = sol.insertionSortList(&node1);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
} 