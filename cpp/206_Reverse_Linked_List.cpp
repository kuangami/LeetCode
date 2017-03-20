// 206. Reverse Linked List
/**
 * Reverse a singly linked list.
 * 
 * Hint:
 * A linked list can be reversed either iteratively or recursively. Could you implement both?
 * 
 * Tags: Linked List
 * 
 * Similar Problems: (M) Reverse Linked List II, (M) Binary Tree Upside Down, (E) Palindrome Linked List
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
class Solution_Iterative {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = NULL, *next = NULL;
        
        while (head != NULL) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        
        return pre;
    }
};

// recursive solution by adding to front
class Solution_Recursive {
    ListNode* pushFront(ListNode* head, ListNode* newhead) {
        if (head == NULL) {
            return newhead;
        }
        
        ListNode *next = head->next;
        head->next = newhead;
        return pushFront(next, head);
    }

public:
    ListNode* reverseList(ListNode* head) {
        return pushFront(head, NULL);
    }
};

// recursive solution by reverse sublist
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        ListNode *newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    ListNode *newhead = sol.reverseList(&node1);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}