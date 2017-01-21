// 371. Sum of Two Integers
/**
 * Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.
 * 
 * Example:
 * Given a = 1 and b = 2, return 3.
 * 
 * Tags: Bit Manipulation
 * 
 * Similar Problems:  (M) Add Two Numbers
 * 
 * Author: Kuang Qin
 */

#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
    }
};

int main() {
    Solution sol;
    cout << sol.getSum(1, 2) << endl;
    cin.get();
    return 0;
}