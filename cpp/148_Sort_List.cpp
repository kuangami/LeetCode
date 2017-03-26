// 148. Sort List
/**
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Tags: Linked List, Sort
 * 
 * Similar Problems: (E) Merge Two Sorted Lists, (M) Sort Colors, (M) Insertion Sort List
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        
        if (l2 == NULL) {
            return l1;
        }
        
        if (l1->val < l2->val) {    // the first element from l1
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        
        // first element from l2
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *slow = head, *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *l1 = head, *l2 = slow->next;
        slow->next = NULL;
        return mergeTwoLists(sortList(l1), sortList(l2));
    }
};

int main() {
    ListNode node5(3), node4(1, &node5), node3(5, &node4), node2(4, &node3), node1(2, &node2);
    Solution sol;
    ListNode *newhead = sol.sortList(&node1);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
} 