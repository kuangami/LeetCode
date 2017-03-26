// 160. Intersection of Two Linked Lists
/**
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 * 
 * For example, the following two linked lists:
 * 
 * A:          a1 - a2
 *                    \
 *                     c1 - c2 - c3
 *                    /            
 * B:     b1 - b2 - b3
 * 
 * begin to intersect at node c1.
 * 
 * Notes:
 * 
 *  If the two linked lists have no intersection at all, return null.
 *  The linked lists must retain their original structure after the function returns.
 *  You may assume there are no cycles anywhere in the entire linked structure.
 *  Your code should preferably run in O(n) time and use only O(1) memory.
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

// align the two list by point one's tail to the other's head
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        ListNode *pA = headA, *pB = headB;
        
        while (pA != pB) {
            // reset the pointer to the head of the other linked list at the end of first iteration
            pA = pA ? pA->next : headB;
            pB = pB ? pB->next : headA;
        }
        
        // make sure the two pointer traveled the same distance
        // if the two lists have an intersection, the two pointer will meet at the intersection
        // if not, they will meet at the end, i.e. NULL
        return pA;
    }
};

// align the start point by length difference
class Solution_LenDifference {
    int getLength(ListNode *head) {
        int length = 0;
        while (head != NULL) {
            head = head->next;
            length++;
        }
        
        return length;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }
        
        int lenA = getLength(headA), lenB = getLength(headB);
        
        // align the starting point
        while (lenA > lenB) {
            headA = headA->next;
            lenA--;
        }
        
        while (lenB > lenA) {
            headB = headB->next;
            lenB--;
        }
        
        while (headA != headB) {
            // compare the rest of the lists
            headA = headA->next;
            headB = headB->next;
        }
        
        // if there is no intersection, headA will go to null
        return headA;
    }
};

int main() {
    ListNode c3(3), c2(2, &c3), c1(1, &c2);
    ListNode a2(2, &c1), a1(1, &a2);
    ListNode b3(3, &c1), b2(2, &b3), b1(1, &b2);
    cout << &c1 << endl;
    
    Solution sol;
    ListNode *p = sol.getIntersectionNode(&a1, &b1);
    cout << p << endl;

    cin.get();
    
    return 0;
} 