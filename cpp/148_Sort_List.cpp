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

// top-down merge sort
// time: O(nlogn), space: O(logn)
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

// bottom-up merge sort
// time: O(nlogn), space: O(1)
class Solution_BottomUp {
    // divide the list into two part, return the head of the second part
    ListNode* split(ListNode* head, int n) {
        for (int i = 1; head != NULL && i < n; i++) {
            head = head->next;
        }
        
        if (head != NULL) {
            // remaining part of the list
            ListNode *p = head->next;
            head->next = NULL;
            return p;
        }
        
        // head == NULL
        return NULL;
    }
    
    // merge two sorted list l1 and l2, then append the result to head
    // return the tail of the merged list
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* head) {
        ListNode *curr = head;
        
        while (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                curr->next = l2;
                curr = l2;
                l2 = l2->next;
            }
            else {
                curr->next = l1;
                curr = l1;
                l1 = l1->next;
            }
        }
        
        // append the rest of the list
        curr->next = (l1 != NULL) ? l1 : l2;
        
        // go to the tail of the list
        while (curr->next != NULL) {
            curr = curr->next;
        }
        
        return curr;
    }

public:
    ListNode* sortList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // get length
        ListNode *curr = head;
        int length = 0;
        while (curr != NULL) {
            curr = curr->next;
            length++;
        }
        
        ListNode dummy(0);
        dummy.next = head;
        
        ListNode *left, *right, *tail;
        for (int step = 1; step < length; step <<= 1) {
            // for each new step, set curr to the beginning of the list
            curr = dummy.next;
            tail = &dummy;
            
            // traverse the entire list once
            while (curr != NULL) {
                left = curr;
                right = split(left, step);
                curr = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        
        return dummy.next;
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