// 94. Binary Tree Inorder Traversal
/**
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree [1,null,2,3],
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,3,2].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 * 
 * Tags: Tree, Hash Table, Stack
 * 
 * Similar Problems: (M) Validate Binary Search Tree, (M) Binary Tree Preorder Traversal, (H) Binary Tree Postorder Traversal, 
 * (M) Binary Search Tree Iterator (M) Kth Smallest Element in a BST (H) Closest Binary Search Tree Value II (M) Inorder Successor in BST
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

// recursive solution
// time: O(n), space: O(n) - function call stack
class Solution {
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) {
            return;
        }
        
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
        return;
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
};

// iterative solution using stack
// time: O(n), space: O(n) - stack
class Solution_Iter {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                curr = st.top();
                st.pop();
                res.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        return res;
    }
};

// Morris traversal
// time: O(n) - find prev pointer, space: O(1)
class Solution_Morris {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *curr = root, *prev = NULL;
        while (curr != NULL) {
            if (curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else {
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right;
                }
                
                if (prev->right == NULL) {
                    prev->right = curr;     // change tree shape
                    curr = curr->left;
                }
                else {  // prev->right == curr
                    prev->right == NULL;    // recover tree shape
                    res.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        
        return res;
    }
};

int main() {
    TreeNode node3(3), node2(2, &node3, NULL), node1(1, NULL, &node2);
    Solution sol;
    vector<int> res = sol.inorderTraversal(&node1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    cin.get();
    return 0;
}