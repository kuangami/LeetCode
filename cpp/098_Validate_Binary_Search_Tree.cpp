// 98. Validate Binary Search Tree
/**
 * Given a binary tree, determine if it is a valid binary search tree (BST).
 * 
 * Assume a BST is defined as follows:
 * 
 * The left subtree of a node contains only nodes with keys less than the node's key.
 * The right subtree of a node contains only nodes with keys greater than the node's key.
 * Both the left and right subtrees must also be binary search trees.
 * 
 * Example 1:
 *     2
 *    / \
 *   1   3
 * Binary tree [2,1,3], return true.
 * 
 * Example 2:
 *     1
 *    / \
 *   2   3
 * Binary tree [1,2,3], return false.
 * 
 * Tags: Tree, Depth-first Search
 * 
 * Similar Problems: (M) Binary Tree Inorder Traversal, (E) Find Mode in Binary Search Tree
 * 
 * Author: Kuang Qin
 */
 
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

class Solution {
    bool validate(TreeNode* root, TreeNode *minNode, TreeNode *maxNode) {
        if (root == NULL) {
            return true;
        }
        
        // root smaller than minNode
        if (minNode != NULL && root->val <= minNode->val) {
            return false;
        }
        
        // root larger than maxNode
        if (maxNode != NULL && root->val >= maxNode->val) {
            return false;
        }
        
        return validate(root->left, minNode, root) && validate(root->right, root, maxNode);
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root, NULL, NULL);
    }
};

int main() {
    TreeNode node1(1), node4(4), node2(2, &node1, NULL), node5(5, &node4, NULL), node3(3, &node2, &node5);
    Solution sol;
    bool ans = sol.isValidBST(&node3);
    cout << ans << endl;
    cin.get();
    return 0;
}