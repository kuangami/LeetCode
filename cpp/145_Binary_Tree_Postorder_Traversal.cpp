// 145. Binary Tree Postorder Traversal
/**
 * Given a binary tree, return the postorder traversal of its nodes' values.
 * 
 * For example:
 * Given binary tree {1,#,2,3},
 *    1
 *     \
 *      2
 *     /
 *    3
 * return [3,2,1].
 * 
 * Note: Recursive solution is trivial, could you do it iteratively?
 * 
 * Subscribe to see which companies asked this question.
 * 
 * Tags: Tree Stack
 * 
 * Similar Problems: (M) Binary Tree Inorder Traversal
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

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
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (root == NULL) {
            return;
        }
        
        postorder(root->left, nodes);
        postorder(root->right, nodes);
        nodes.push_back(root->val);
        return;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        postorder(root, res);
        return res;
    }
};

// interative solution using stack
// time: O(n), space: O(n)
class Solution_Iter {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode *curr = root;
        
        // the opposite way of preorder
        while (curr != NULL || !st.empty()) {
            if (curr != NULL) {
                st.push(curr);
                res.push_back(curr->val);
                curr = curr->right;
            }
            else {
                curr = st.top();
                st.pop();
                curr = curr->left;
            }
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

// Morris Traversal
// time: O(n), space: O(1)
class Solution_Morris {
    // reverse tree node from start to end
    // 1
    //  \               start: 1, end: 3
    //   2
    //    \             output: 3, 2, 1
    //     3
    void reverseNodes(TreeNode *start, TreeNode *end) {
        if (start == end) {
            return;
        }
        
        // can be treated as reversing a linked list, right is equal to next
        TreeNode *prev = start, *curr = start->right, *next;
        while (prev != end) {
            next = curr->right; // save the next
            curr->right = prev; // point to the start of the reversed list
            prev = curr;        // update the start of the reversed list
            curr = next;        // update the next node to be reversed
        }
        
        return;
    }
    
    void reverseAddNodes(TreeNode *start, TreeNode *end, vector<int>& nodes) {
        reverseNodes(start, end);   // reverse for output
        
        for (TreeNode *p = end; p != start; p = p->right) {
            nodes.push_back(p->val);
        }
        nodes.push_back(start->val);
        
        reverseNodes(end, start);   // recover the tree
        return;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode dummy(0), *curr = &dummy, *prev = NULL;
        dummy.left = root;
        
        while (curr != NULL) {
            if (curr->left == NULL) {
                curr = curr->right;
            }
            else {
                prev = curr->left;
                while (prev->right != NULL && prev->right != curr) {
                    prev = prev->right; // find in-order previous node
                }
                
                if (prev->right == NULL) {
                    prev->right = curr;
                    curr = curr->left;
                }
                else {  // prev->right == curr
                    // reverse add the right boundary of its left sub-tree
                    reverseAddNodes(curr->left, prev, res);
                    prev->right = NULL;
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
    vector<int> res = sol.postorderTraversal(&node1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    cin.get();
    return 0;
}