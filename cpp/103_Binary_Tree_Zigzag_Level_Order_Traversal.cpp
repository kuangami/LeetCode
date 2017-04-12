// 103. Binary Tree Zigzag Level Order Traversal
/**
 * Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, 
 * then right to left for the next level and alternate between).
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 *     3
 *    / \
 *   9  20
 *     /  \
 *    15   7
 * return its zigzag level order traversal as:
 * [
 *   [3],
 *   [20,9],
 *   [15,7]
 * ]
 * 
 * Tags: Tree, Breadth-first Search, Stack
 * 
 * Similar Problems: (M) Binary Tree Level Order Traversal
 * 
 * Author: Kuang Qin
 */ 

#include <iostream>
#include <vector>
#include <queue>
#include <deque>

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

// bfs solution using array
// time: O(n), space: O(n) - queue
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        if (root == NULL) {
            return nodes;
        }
        
        bool rev = false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int levelCount = q.size();
            vector<int> level(levelCount);
            
            for (int i = 0; i < levelCount; i++) {  // output current level
                TreeNode *curr = q.front();
                int index = rev ? levelCount - 1 - i : i;
                level[index] = curr->val;
                if (curr->left != NULL) {
                    q.push(curr->left);
                }
                
                if (curr->right != NULL) {
                    q.push(curr->right);
                }
                
                q.pop();
            }
            
            rev = !rev; // change direction
            nodes.push_back(level);
        }
            
        return nodes;
    }
};

// bfs solution using deque
// time: O(n), space: O(n) - queue
class Solution_Deque {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        if (root == NULL) {
            return nodes;
        }
        
        bool rev = false;
        deque<TreeNode*> dq;
        dq.push_back(root);
        while (!dq.empty()) {
            int levelCount = dq.size();
            vector<int> level;
            
            while (levelCount--) {  // output current level
                if (rev) {  // output from right to left
                    TreeNode *curr = dq.back();
                    level.push_back(curr->val);
                    dq.pop_back();
                    
                    if (curr->right != NULL) {
                        dq.push_front(curr->right);
                    }
                    
                    if (curr->left != NULL) {
                        dq.push_front(curr->left);
                    }
                }
                else {  // output from left to right
                    TreeNode *curr = dq.front();
                    level.push_back(curr->val);
                    dq.pop_front();
                    
                    if (curr->left != NULL) {
                        dq.push_back(curr->left);
                    }
                    
                    if (curr->right != NULL) {
                        dq.push_back(curr->right);
                    }
                }
            }
            
            rev = !rev; // change direction
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
        
        if (depth % 2 == 0) {   // odd rows
            nodes[depth].push_back(root->val);
        }
        else {  // even rows
            nodes[depth].insert(nodes[depth].begin(), root->val);
        }
        
        dfs(root->left, depth + 1, nodes);
        dfs(root->right, depth + 1, nodes);
        return;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> nodes;
        dfs(root, 0, nodes);            
        return nodes;
    }
};

int main() {
    TreeNode node5(7), node4(15), node3(20, &node4, &node5), node2(9), node1(3, &node2, &node3);
    Solution sol;
    vector<vector<int>> res = sol.zigzagLevelOrder(&node1);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    cin.get();
    return 0;
}