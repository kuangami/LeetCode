// 95. Unique Binary Search Trees II
/**
 * Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1...n.
 * 
 * For example,
 * Given n = 3, your program should return all 5 unique BST's shown below.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 * 
 * Tags: Tree, Dynamic Programming
 * 
 * Similar Problems: (M) Unique Binary Search Trees, (M) Different Ways to Add Parentheses
 * 
 * Author: Kuang Qin
 */ 

#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// G(n):    the number of unique BST for a sequence of length n (G(0) = G(1) = 1)
// F(i, n): the number of unique BST, where the number i is the root of BST (1 <= i <= n)
// G(n) = F(1, n) + F(2, n) + ... + F(n, n)
// F(i, n) = G(i - 1) * G(n - i): 
// for example, F(3, 7): 3 as root, [1, 2] left subtree, [4, 5, 6, 7] right subtree
// F(3, 7) = G(2) * G(4)
// G(n) = G(0) * G(n - 1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0)

class Solution {
    vector<TreeNode*> generate(int start, int end) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(NULL);    // empty tree
            return res;
        }
        
        for (int iroot = start; iroot <= end; iroot++) {    // root position
            vector<TreeNode*> left = generate(start, iroot - 1);
            vector<TreeNode*> right = generate(iroot + 1, end);
            
            for (int i = 0; i < left.size(); i++) {         // left subtree
                for (int j = 0; j < right.size(); j++) {    // right subtree
                    TreeNode *root = new TreeNode(iroot);
                    root->left = left[i];
                    root->right = right[j];
                    res.push_back(root);
                }
            }
        }
        
        return res;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) {
            return res;
        }
        
        return generate(1, n);
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
    Solution sol;
    vector<TreeNode*> trees = sol.generateTrees(3);
    TreeOperation trOp;
    for (int i = 0; i < trees.size(); i++) {
        trOp.printTree(trees[i]);
        trOp.deleteTree(trees[i]);
        cout << endl;
    }
    cin.get();
    return 0;
}