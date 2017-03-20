// 61. Rotate List
/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.
 * 
 * For example:
 * Given 1->2->3->4->5->NULL and k = 2,
 * return 4->5->1->2->3->NULL.
 * 
 * Tags: Linked List, Two Pointers
 * 
 * Similar Problems: (E) Rotate Array
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

// circle list
class Solution_CircleList {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        int len = 1;
        ListNode *tail = head;
        
        // find the end of the list
        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }
        
        // for a cirle
        tail->next = head;
        
        // find new tail
        // when k > len, shift right (k % len)
        // (len - k % len) is the new tail position
        for (int i = 0; i < len - k % len; i++) {
            tail = tail->next;
        }
        
        head = tail->next;
        tail->next = NULL;
        
        return head;
    }
};

// two pointers
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0) {
            return head;
        }
        int len = 1;
        ListNode *fast = head, *slow = head;
        
        // move fast pointer to the end of the list
        while (fast->next != NULL) {
            fast = fast->next;
            len++;
        }
        
        // move slow pointer to the new tail
        // when k > len, shift right (k % len)
        // (len - k % len) is the new tail position
        for (int i = 1; i < len - k % len; i++) {
            slow = slow->next;
        }
        
        fast->next = head;  // connect tail to head
        head = slow->next;  // new head
        slow->next = NULL;  // point tail to null
        
        return head;
    }
};

int main() {
    ListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    ListNode *newhead = sol.rotateRight(&node1, 3);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}