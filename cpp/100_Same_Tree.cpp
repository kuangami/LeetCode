// 100. Same Tree
/**
 * Given two binary trees, write a function to check if they are equal or not.
 * 
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 * 
 * Tags: Tree, Depth-first Search
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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        
        if (p != NULL && q != NULL) {
            if (p->val == q->val) {
                return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
            }
        }
        
        return false;
    }
};

int main() {
    TreeNode node1_1(1), node1_4(4), node1_2(2, &node1_1, NULL), node1_5(5, &node1_4, NULL), node1_3(3, &node1_2, &node1_5);
    TreeNode node2_1(1), node2_4(4), node2_2(2, &node2_1, NULL), node2_5(5, NULL, &node2_4), node2_3(3, &node2_2, &node2_5);
    Solution sol;
    bool ans = sol.isSameTree(&node1_3, &node2_3);
    cout << ans << endl;
    cin.get();
    return 0;
}