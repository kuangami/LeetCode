// 415. Add Strings
/**
 * Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 * 
 * Note:
 * 
 * 1. The length of both num1 and num2 is < 5100.
 * 2. Both num1 and num2 contains only digits 0-9.
 * 3. Both num1 and num2 does not contain any leading zero.
 * 4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * 
 * Tags: Math
 * 
 * Similar Problems: (M) Add Two Numbers, (M) Multiply Strings
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res("");
        int carry = 0, i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || carry == 1) {
            if (i >= 0)
                carry += num1[i--] - '0';
            
            if (j >= 0)
                carry += num2[j--] - '0';
            
            res += carry % 10 + '0';
            carry /= 10;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string num1 = "13", num2 = "9";
    Solution sol;
    string res = sol.addStrings(num1, num2);
    cout << res << endl;
    cin.get();
    
    return 0;
}