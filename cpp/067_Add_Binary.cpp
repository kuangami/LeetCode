// 67. Add Binary
/**
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 * Tags: Math, String
 * 
 * Similar Problems: (M) Add Two Numbers, (M) Multiply Strings, (E) Plus One
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res("");
        
        int carry = 0, i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry == 1) {
            if (i >= 0)
                carry += a[i--] - '0';
            
            if (j >= 0)
                carry += b[j--] - '0';
            
            res += carry % 2 + '0';
            carry = carry / 2;
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};

int main() {
    string a = "11", b = "1";
    Solution sol;
    string res = sol.addBinary(a, b);
    cout << res << endl;
    cin.get();
    
    return 0;
}