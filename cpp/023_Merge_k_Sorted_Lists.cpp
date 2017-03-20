// 23. Merge k Sorted Lists
/**
 * Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 * 
 * Subscribe to see which companies asked this question.
 * 
 * Tags: Divide and Conquer, Linked List, Heap
 * 
 * Similar Problems: (E) Merge Two Sorted Lists, (M) Ugly Number II
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

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

// divide and conquer
// time: O(n * logk), logk for partition, n for merge
class Solution {
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        
        if (l2 == NULL) {
            return l1;
        }
        
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
    
    // merge lists from start to end
    ListNode* mergeLists(vector<ListNode*>& lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        
        if (start < end) {
            int mid = start + (end - start) / 2;
            ListNode *l1 = mergeLists(lists, start, mid);
            ListNode *l2 = mergeLists(lists, mid + 1, end);
            return mergeTwoLists(l1, l2);
        }
        
        // start > end
        return NULL;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        return mergeLists(lists, 0, n - 1);
    }
};

// priority queue
// time: O(2n * logk), push and pop n times, each takes logk to find smallest
class Solution_PQ {
    struct compare {
        bool operator()(const ListNode* l, const ListNode* r) {
            return l->val > r->val; // smallest element on top
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        ListNode dummy(0);
        dummy.next = NULL;
        ListNode *curr = &dummy;
        int n = lists.size();
        
        // build the priority queue
        for (int i = 0; i < n; i++) {
            if (lists[i] != NULL) {
                // push the first elements of sorted lists
                pq.push(lists[i]);
            }
        }
        
        while (!pq.empty()) {
            curr->next = pq.top();
            pq.pop();   // pop the smallest element
            curr = curr->next;
            if (curr->next != NULL) {
                // push the next element
                pq.push(curr->next);
            }
        }
        
        return dummy.next;
    }
};

// make heap
// time: O(2n * logk), push and pop n times, each takes logk to find smallest
class Solution_Heap {
    static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val; // smallest element on top
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> heap;
        ListNode dummy(0);
        dummy.next = NULL;
        ListNode *curr = &dummy;
        int n = lists.size();
        
        // build heap with the smallest element on top
        for (int i = 0; i < n; i++) {
            if (lists[i] != NULL) {
                heap.push_back(lists[i]);
            }
        }
        make_heap(heap.begin(), heap.end(), heapComp);
        
        while (!heap.empty()) {
            curr->next = heap.front();
            pop_heap(heap.begin(), heap.end(), heapComp);
            heap.pop_back();
            curr = curr->next;
            if (curr->next != NULL) {
                // push next element
                heap.push_back(curr->next);
                push_heap(heap.begin(), heap.end(), heapComp);
            }
        }
        
        return dummy.next;
    }
};

int main() {
    ListNode node1_3(5), node1_2(3, &node1_3), node1_1(1, &node1_2);
    ListNode node2_2(4), node2_1(2, &node2_2);
    ListNode node3_2(8), node3_1(7, &node3_2);
    vector<ListNode*> lists = {&node1_1, &node2_1, &node3_1};
    Solution_Heap sol;
    ListNode *newhead = sol.mergeKLists(lists);
    for (ListNode *p = newhead; p != NULL; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}