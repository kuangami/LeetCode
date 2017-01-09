// 306. Additive Number
/**
 * Additive number is a string whose digits can form additive sequence.
 * 
 * A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
 * 
 * For example:
 * "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 *
 * "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 * 
 * Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
 * 
 * Follow up:
 * How would you handle overflow for very large input integers?
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        for (int i = 1; i <= n / 2; i++)    // the first number cannot exceed half of the whole string
            for (int j = 1; j <= (n - i) / 2; j++)  // the second number cannot exceed half of the remaining string
                if (isSum(num.substr(0, i), num.substr(i, j), num.substr(i + j)))   // check the rest of the string
                    return true;
        
        return false;
    }
    
    bool isSum(string num1, string num2, string str) {
        if ((num1.size() > 1 && num1[0] == '0') || (num2.size() > 1 && num2[0] == '0')) // handling leading zeros
            return false;
        
        string sum = strAdd(num1, num2);

        if (str == sum) // exactly match
            return true;
        
        if (str.size() <= sum.size() || sum.compare(str.substr(0, sum.size())) != 0)    // not match
            return false;
        else    // partially match, continue to compare
            return isSum(num2, sum, str.substr(sum.size()));
    }
    
    string strAdd(string num1, string num2) {
        string strSum;
        int n1 = num1.size() - 1, n2 = num2.size() - 1, carry = 0;
        while (n1 >= 0 || n2 >= 0)
        {
            int sum = carry + (n1 >= 0 ? num1[n1--] - '0' : 0) + (n2 >= 0 ? num2[n2--] - '0' : 0);
            strSum.push_back(sum % 10 + '0');
            carry = sum / 10;
        }
        
        if (carry)
            strSum.push_back(carry + '0');
        
        reverse(strSum.begin(), strSum.end());
        return strSum;
    }
};

int main()
{
    string num = "100010";
    Solution sol;
    bool bAdditive = sol.isAdditiveNumber(num);
    if (bAdditive)
        cout << "true" << endl;
    else
        cout << "false" << endl;
    
    cin.get();
    return 0;
}