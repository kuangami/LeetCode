// 21. Merge Two Sorted Lists
/**
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Tags: Linked List
 * 
 * Similar Problems: (H) Merge k Sorted Lists, (E) Merge Sorted Array, (M) Sort List, (M) Shortest Word Distance II
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

// iterative solution by adding l2 to l1
class Solution_Interative {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // insert l2 into l1
        ListNode dummy(INT_MIN);
        dummy.next = l1;
        
        ListNode *curr = &dummy;
        while (l2 != NULL) {
            while (curr->next != NULL && curr->next->val < l2->val) {
                // pass until l2 has larger value
                curr = curr->next;
            }
            
            // insert l2
            ListNode *next = l2->next;
            l2->next = curr->next;
            curr->next = l2;
            l2 = next;
        }
        
        return dummy.next;
    }
};

// iterative solution by comparing l1 and l2
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode *curr = &dummy;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            
            curr = curr->next;
        }
        
        // insert the rest
        curr->next = l1 ? l1 : l2;
        
        return dummy.next;
    }
};

// recursive solution
class Solution_Recursive {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        
        if (l2 == NULL) {
            return l1;
        }
        
        // compare the first element
        if (l1->val < l2->val) {    // l1 has the first element
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        
        // l2 has the first element
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
};

int main() {
    ListNode node1_3(5), node1_2(3, &node1_3), node1_1(1, &node1_2);
    ListNode node2_2(4), node2_1(2, &node2_2);
    Solution_Recursive sol;
    ListNode *newhead = sol.mergeTwoLists(&node1_1, &node2_1);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}