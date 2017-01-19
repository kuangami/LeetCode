// 43. Multiply Strings
/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
 * 
 * Note:
 * 
 * 1. The length of both num1 and num2 is < 110.
 * 2. Both num1 and num2 contains only digits 0-9.
 * 3. Both num1 and num2 does not contain any leading zero.
 * 4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * 
 * Tags: Math, String
 * 
 * Similar Problems: (M) Add Two Numbers, (E) Plus One, (E) Add Binary, (E) Add Strings
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        
        // product length will not exceed the total length of two multipliers
        int n1 = num1.size(), n2 = num2.size(), n = n1 + n2;
        vector<int> product(n, 0);
        
        // add result from multiplying by digit
        for (int i = n1 - 1; i >= 0; i--) {
            for (int j = n2 - 1; j >= 0; j--) {
                product[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
            }
        }
        
        // make each digit valid
        for (int i = n - 1; i > 0; i--) {
            product[i - 1] += product[i] / 10;  // higher digit
            product[i] = product[i] % 10;       // lower digit
        }
        
        // convert into string
        string res("");
        if (product[0] != 0)    // first digit could be zero
            res += product[0] + '0';
        
        for (int i = 1; i < n; i++)
            res += product[i] + '0';
        
        return res;
    }
};

int main() {
    string num1("2143"), num2("2");
    Solution sol;
    string p = sol.multiply(num1, num2);
    cout << num1 << " * " << num2 << " = " << p << endl;
    cin.get();
    
    return 0;
}