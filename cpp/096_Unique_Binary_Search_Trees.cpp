// 96. Unique Binary Search Trees
/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * 
 *    1         3     3      2      1
 *     \       /     /      / \      \
 *      3     2     1      1   3      2
 *     /     /       \                 \
 *    2     1         2                 3
 * 
 * Tags: Tree, Dynamic Programming
 * 
 * Similar Problems: (M) Unique Binary Search Trees II
 * 
 * Author: Kuang Qin
 */

#include <iostream>

using namespace std;

// G(n):    the number of unique BST for a sequence of length n (G(0) = G(1) = 1)
// F(i, n): the number of unique BST, where the number i is the root of BST (1 <= i <= n)
// G(n) = F(1, n) + F(2, n) + ... + F(n, n)
// F(i, n) = G(i - 1) * G(n - i): 
// for example, F(3, 7): 3 as root, [1, 2] left subtree, [4, 5, 6, 7] right subtree
// F(3, 7) = G(2) * G(4)
// G(n) = G(0) * G(n - 1) + G(1) * G(n - 2) + ... + G(n - 1) * G(0)
class Solution {
public:
    int numTrees(int n) {
        int G[n + 1] = {};
        G[0] = G[1] = 1;
        
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        
        return G[n];
    }
};

int main() {
    Solution sol;
    int num = sol.numTrees(3);
    cout << num << endl;
    cin.get();
    return 0;
}