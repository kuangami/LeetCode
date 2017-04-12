// 138. Copy List with Random Pointer
/**
 * A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
 * 
 * Return a deep copy of the list.
 * 
 * Subscribe to see which companies asked this question.
 * 
 * Tags: Hash Table, Linked List
 * 
 * Similar Problems: (M) Clone Graph
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
    RandomListNode(int x, RandomListNode *p) : label(x), next(p), random(NULL) {}
};

/** 
 * Deep Copy:
 * A deep copy copies all fields, and makes copies of dynamically allocated memory pointed to by the fields. 
 * A deep copy occurs when an object is copied along with the objects to which it refers.
 */

/** 
 * Shallow Copy: 
 * Shallow copy is a bit-wise copy of an object. A new object is created that has an exact copy of the values in the original object. 
 * If any of the fields of the object are references to other objects, just the reference addresses are copied i.e., only the memory address is copied.
 */

class Solution_HashMap {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        // use a hash map to map old address to new address
        unordered_map<RandomListNode*, RandomListNode*> map;
        RandomListNode *curr = head;
        while (curr != NULL) {
            map[curr] = new RandomListNode(curr->label);
            curr = curr->next;
        }
        
        curr = head;
        while (curr != NULL) {
            map[curr]->next = map[curr->next];
            map[curr]->random = map[curr->random];
            curr = curr->next;
        }
        
        return map[head];
    }
};

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        // for each node in the original list, create a copy immediately after it
        RandomListNode *l1 = head, *l2;
        while (l1 != NULL) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->next;
            l1->next = l2;
            l1 = l2->next;
        }
        
        // save the new head, assign the l2->random by l1->random->next
        RandomListNode *newhead = head->next;
        l1 = head;
        while (l1 != NULL) {
            l2 = l1->next;
            l2->random = l1->random ? l1->random->next : NULL;
            l1 = l2->next;
        }
        
        // split two lists
        l1 = head;
        while (l1 != NULL) {
            l2 = l1->next;
            l1->next = l2->next;
            l1 = l2->next;
            if (l1 != NULL) {
                l2->next = l1->next;
            }
        }
        
        return newhead;
    }
};

class Solution2 {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        // for each node in the original list l1, create a copy called l2
        // point l2->next to l1->random, l1->random to l2
        RandomListNode *l1, *l2;
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = new RandomListNode(l1->label);
            l2->next = l1->random;
            l1->random = l2;
        }
        
        // save the new head, assign the l2->random by l2->next->random
        // l2->next: l1->random, l1->random is corresponding l2
        RandomListNode *newhead = head->random;
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l2->random = l2->next ? l2->next->random : NULL;
        }
        
        // recover l1->random by l2->next, set l2->next to l1->next->random 
        for (l1 = head; l1 != NULL; l1 = l1->next) {
            l2 = l1->random;
            l1->random = l2->next;
            l2->next = l1->next ? l1->next->random : NULL;
        }
        
        return newhead;
    }
};

int main() {
    RandomListNode node5(5), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    node5.random = &node3;
    node3.random = &node2;
    node2.random = &node5;
    
    RandomListNode *head = &node1, *curr = head;
    cout << "Original List:" << endl;
    while (curr != NULL) {
        cout << static_cast<const void *> (curr) << "(" << curr->label << ", " \
            << static_cast<const void *> (curr->next) << ", " \
            << static_cast<const void *> (curr->random) << ")" << endl;
        curr = curr->next;
    }
    cout << endl;
    
    Solution sol;
    curr = sol.copyRandomList(head);
    cout << "Copied List:" << endl;
    while (curr != NULL) {
        cout << static_cast<const void *> (curr) << "(" << curr->label << ", " \
            << static_cast<const void *> (curr->next) << ", " \
            << static_cast<const void *> (curr->random) << ")" << endl;
        RandomListNode *p = curr;
        curr = curr->next;
        delete p;
    }
    cin.get();
    
    return 0;
}