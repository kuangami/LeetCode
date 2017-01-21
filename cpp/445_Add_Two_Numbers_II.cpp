// 445. Add Two Numbers II
/**
 * You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their 
 * nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 * 
 * Example:
 * 
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 * Tags: Linked List
 * 
 * Similar Problems: (M) Add Two Numbers
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <cmath>

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
    int getLength(ListNode* p) {
        int len = 0;
        while (p != NULL) {
            p = p->next;
            len++;
        }
        
        return len;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = getLength(l1), n2 = getLength(l2);
        if (n1 < n2) {  // make sure l1 is longer than l2
            ListNode *tmp = l1;
            l1 = l2;
            l2 = tmp;
        }
        
        int diff = abs(n1 - n2);
        ListNode head(0), *curr = &head;
        // record a post representing the first location that could be affected by carry
        // for example,
        //   8 9 9 8     8 9 9 9     9 9 9 9
        //         |     |         |
        //        pos   pos       pos
        ListNode *post = &head;
        
        while (diff > 0) {  // the different part, can be treated as a plus one problem
            curr->next = new ListNode(l1->val);
            curr = curr->next;
            
            if (l1->val < 9)    // will not be affected by carry
                post = curr;
            
            l1 = l1->next;
            diff--;
        }
        
        while (l1 != NULL) {
            int val = l1->val + l2->val;
            
            if (val > 9) {  // if a carry generated, update post
                val -= 10;
                
                // add 1 the post, set the following to 0
                post->val++;
                post = post->next;
                while (post != NULL) {
                    post->val = 0;
                    post = post->next;
                }
            }
            
            // process the new node
            curr->next = new ListNode(val);
            curr = curr->next;
            l1 = l1->next;
            l2 = l2->next;
            if (val < 9)    // update post
                post = curr;
        }
        
        if (head.val == 1) {    // one more digit needs to be added
            ListNode *dummy = new ListNode(1);
            dummy->next = head.next;
            curr = dummy;
        }
        else
            curr = head.next;
        
        return curr;
    }
};

int main () {
    ListNode l1_4(3),l1_3(4, &l1_4), l1_2(2, &l1_3), l1_1(7, &l1_2);
    ListNode l2_3(4), l2_2(6, &l2_3), l2_1(5, &l2_2);
    Solution sol;
    ListNode *res = sol.addTwoNumbers(&l1_1, &l2_1);
    for (ListNode *p = res; p != NULL; p = p->next) {
        cout << p->val;
    }
    cout << endl;
    cin.get();
    
    return 0;
}