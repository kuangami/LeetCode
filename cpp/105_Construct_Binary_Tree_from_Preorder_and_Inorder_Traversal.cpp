// 105. Construct Binary Tree from Preorder and Inorder Traversal
/**
 * Given preorder and inorder traversal of a tree, construct the binary tree.
 * 
 * Note:
 * You may assume that duplicates do not exist in the tree.
 * 
 * Tags: Tree, Array, Depth-first Search
 * 
 * Similar Problems: (M) Construct Binary Tree from Inorder and Postorder Traversal
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

class Solution {
    TreeNode* build(vector<int>& preorder, int proot, vector<int>& inorder, int istart, int iend) {
        if (proot > preorder.size() - 1 || istart > iend) {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(preorder[proot]);
        
        int iroot;
        for (iroot = istart; iroot < iend; iroot++) {
            if (inorder[iroot] == preorder[proot]) {
                break;
            }
        }
        
        root->left = build(preorder, proot + 1, inorder, istart, iroot - 1);
        root->right = build(preorder, proot + (iroot - istart) + 1, inorder, iroot + 1, iend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        if (n == 0) {
            return NULL;
        }
        
        return build(preorder, 0, inorder, 0, n - 1);
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
    vector<int> preorder = {1,2,4,3,5,6};
    vector<int> inorder = {4,2,1,5,3,6};
    Solution sol;
    TreeNode *root = sol.buildTree(preorder, inorder);
    TreeOperation trOp;
    trOp.printTree(root);
    trOp.deleteTree(root);
    return 0;
}