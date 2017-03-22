// 109. Convert Sorted List to Binary Search Tree
/**
 * Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
 * 
 * Tags: Depth-first Search, Linked List
 * 
 * Similar Problems: (E) Convert Sorted Array to Binary Search Tree
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <queue>

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

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        
        if (head->next == NULL) {
            return new TreeNode(head->val);
        }
        
        // find the middle point
        ListNode *slow = head, *fast = head, *pre = head;
        while (fast != NULL && fast->next != NULL) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = NULL;   // break the list into two halves
        
        // use slow as root and build left and right sub-tree
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slow->next);
        
        return root;
    }
};

class TreeOperation {
    int getTreeHeight(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int l = getTreeHeight(root->left);
        int r = getTreeHeight(root->right);
        
        if (l > r) {
            return l + 1;
        }
        
        return r + 1;
    }
    
    // output all the node in level order, including null pointers
    vector<vector<string>> levelOrderFull(TreeNode* root) {
        vector<vector<string>> output;
        if (root == NULL) {
            return output;
        }
        
        int h = getTreeHeight(root);
        queue<TreeNode*> q;
        q.push(root);
        
        // fill the container in each level
        for (int i = 0; i < h; i++) {
            vector<string> level;
            int currLevelCount = q.size();
            
            // while loop for current level
            while (currLevelCount--) {
                TreeNode *curr = q.front();
                if (curr == NULL) {
                    level.push_back("&");
                    q.push(NULL);
                    q.push(NULL);
                }
                else {
                    stringstream ss;
                    ss << curr->val;
                    level.push_back(ss.str());
                    q.push(curr->left);
                    q.push(curr->right);
                }
                
                q.pop();
            }
            
            output.push_back(level);
        }
        
        return output;
    }
public:
    void printTree(TreeNode *root) {
        vector<vector<string>> output = levelOrderFull(root);
        int h = output.size();
        if (h == 0) {
            return;
        }
        
        int w = 2 * output[h - 1].size() + 1;   // total width
        for (int i = 0; i < h; i++) {
            int n = output[i].size();
            int m = (w - n) / (n + 1);  // calculate space width
            string sp(m, ' ');
            if ((w - n) % (n + 1)) {
                cout << sp << " ";
            }
            else {
                cout << sp;     // add space
            }
            
            for (int j = 0; j < n; j++) {
                cout << output[i][j] << sp;
            }
            cout << endl;
        }
        
        return;
    }
    
    void deleteTree(TreeNode *root) {
        if (root == NULL) {
            return;
        }
        
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return;
        }
        
        deleteTree(root->left);
        deleteTree(root->right);
        return;
    }
};

int main() {
    ListNode node10(10), node9(9, &node10), node8(8, &node9), node7(7, &node8), node6(6, &node7);
    ListNode node5(5, &node6), node4(4, &node5), node3(3, &node4), node2(2, &node3), node1(1, &node2);
    ListNode *head = &node1, *curr = head;
    cout << "Sorted List: " << endl;
    while (curr != NULL) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
    
    Solution sol;
    TreeNode *root = sol.sortedListToBST(head);
    cout << "Binary Search Tree: " << endl;
    TreeOperation treeop;
    treeop.printTree(root);
    treeop.deleteTree(root);
    cin.get();
    
    return 0;
}