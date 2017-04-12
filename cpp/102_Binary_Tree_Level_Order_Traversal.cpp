// 102. Binary Tree Level Order Traversal
/**
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
 * ]
 * 
 * Tags: Tree, Breadth-first Search
 * 
 * Similar Problems: (M) Binary Tree Zigzag Level Order Traversal, (E) Binary Tree Level Order Traversal II, 
 * (E) Minimum Depth of Binary Tree, (M) Binary Tree Vertical Order Traversal
 * 
 * Author: Kuang Qin
 */ 

#include <iostream>
#include <vector>
#include <queue>

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

// bfs solution
// time: O(n), space: O(n) - queue
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        if (root == NULL) {
            return nodes;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelCount = q.size();
            vector<int> level;
            
            while (levelCount--) {  // output current level
                TreeNode *curr = q.front();
                level.push_back(curr->val);
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
                
                q.pop();
            }
            
            nodes.push_back(level);
        }
            
        return nodes;
    }
};

// dfs solution
// time: O(n), space: O(n) - call stack
class Solution_DFS {
    void dfs(TreeNode* root, int depth, vector<vector<int>>& nodes) {
        if (root == NULL) {
            return;
        }
        
        // create a new vector for a new level
        if (depth >= nodes.size()) {
            vector<int> level;
            nodes.push_back(level);
        }
        
        nodes[depth].push_back(root->val);
        dfs(root->left, depth + 1, nodes);
        dfs(root->right, depth + 1, nodes);
        return;
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        dfs(root, 0, nodes);            
        return nodes;
    }
};

int main() {
    TreeNode node5(7), node4(15), node3(20, &node4, &node5), node2(9), node1(3, &node2, &node3);
    Solution sol;
    vector<vector<int>> res = sol.levelOrder(&node1);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    cin.get();
    return 0;
}