// 144. Binary Tree Preorder Traversal
/**
 * Given a binary tree, return the preorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [1,2,3].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 * 
 * Tags: Tree Stack
 * 
 * Similar Problems: (M) Binary Tree Inorder Traversal, (M) Verify Preorder Sequence in Binary Search Tree
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
// time: O(n), space: O(n)
class Solution {
    void preorder(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) {
            return;
        }
        
        nodes.push_back(root->val);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        preorder(root, res);
        return res;
    }
};

// interative solution using stack
// time: O(n), space: O(n)
class Solution_Iter {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        
        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                res.push_back(curr->val);
                curr = curr->left;
            }
            else {
                curr = st.top();
                st.pop();
                curr = curr->right;
            }
        }
        
        return res;
    }
};

// Morris Traversal
// time: O(n), space: O(1)
class Solution_Morris {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *curr = root, *prev = NULL;
        
        while (curr != NULL) {
            if (curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right;
            }
            else {  // curr->left != NULL
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right; // find in-order previous node
                }
                
                if (prev->right == NULL) {
                    res.push_back(curr->val);   // ouput first, only difference with inorder
                    prev->right = curr;
                    curr = curr->left;
                }
                else {  // prev->right == curr
                    prev->right = NULL; //recover tree
                    curr = curr->right;
                }
            }
        }
        
        return res;
    }
};

int main() {
    TreeNode node3(3), node2(2, &node3, NULL), node1(1, NULL, &node2);
    Solution_Morris sol;
    vector<int> res = sol.preorderTraversal(&node1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    cin.get();
    return 0;
}