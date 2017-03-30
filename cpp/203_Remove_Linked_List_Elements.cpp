// 203. Remove Linked List Elements
/**
 * Remove all elements from a linked list of integers that have value val.
 * 
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 * 
 * Tags: Linked List
 * 
 * Similar Problems: (E) Remove Element (E) Delete Node in a Linked List
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

// iterative solution
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *prev = &dummy, *curr = head;
        while (curr != NULL) {
            if (curr->val == val) {
                prev->next = curr->next;
            }
            else {
                // move prev forward
                prev = curr;
            }
            
            curr = curr->next;
        }
        
        return dummy.next;
    }
};

// recursive solution
class Solution_recursive {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL) {
            return NULL;
        }
        
        head->next = removeElements(head->next, val);
        
        // return head->next if head is deleted
        return (head->val == val) ? head->next : head;
    }
};

int main() {
    ListNode node7(6), node6(5, &node7), node5(4, &node6), node4(3, &node5), node3(6, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    ListNode *newhead = sol.removeElements(&node1, 6);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
} 