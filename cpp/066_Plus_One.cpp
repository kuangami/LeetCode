// 66. Plus One
/**
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of the list.
 * 
 * Subscribe to see which companies asked this question
 * 
 * Tags: Array, Math
 * 
 * Similar Problems: (M) Multiply Strings, (E) Add Binary, (M) Plus One Linked List
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size(), sum = 0, carry = 1;
        for (int i = n - 1; i >= 0; i--) {
            sum = digits[i] + carry;
            carry = sum / 10;
            digits[i] = sum % 10;
            if (!carry)
                break;  // no change in the remaining digits
        }
        
        // if carry still exists after the most significant digit, the original array must be all '9'
        if (carry) {
            digits[0] = 1;
            digits.push_back(0);
        }
        
        return digits;
    }
};

int main() {
    vector<int> digits = {9, 9, 9, 9};
    Solution sol;
    vector<int> res = sol.plusOne(digits);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    cout << endl;
    cin.get();
    
    return 0;
}