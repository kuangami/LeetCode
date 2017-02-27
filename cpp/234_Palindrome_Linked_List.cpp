// 234. Palindrome Linked List
/**
 * Given a singly linked list, determine if it is a palindrome.
 * 
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
 * 
 * Tags: Linked List, Two Pointers
 * 
 * Similar Problems: (E) Palindrome Number, (E) Valid Palindrome, (E) Reverse Linked List
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
    ListNode(int x, ListNode* p) : val(x), next(p) {}
};

class Solution {
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
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        
        // use two pointers to find the middle and end
        ListNode *slow = head, *fast = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // reverse the second part of the list
        slow = slow->next;
        slow = reverseList(slow);
        
        // compare head and slow
        while (slow != NULL) {
            if (head->val != slow->val) {
                return false;
            }
            
            head = head->next;
            slow = slow->next;
        }
        
        return true;
    }
};

int main() {
    ListNode node4(1), node3(2, &node4), node2(2, &node3), node1(1, &node2);
    Solution sol;
    bool ans = sol.isPalindrome(&node1);
    cout << ans << endl;
    cin.get();
    
    return 0;
}