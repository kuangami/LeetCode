// 8. String to Integer (atoi)
/**
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 * 
 * spoilers alert... click to show requirements for atoi.
 * 
 * Requirements for atoi:
 *
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 * 
 * Tags: Math, String
 * 
 * Similar Problems: (E) Reverse Integer, (H) Valid Number
 * 
 * Author: Kuang Qin
 */
 
#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int i = 0, sign = 1, num = 0;
        
        while (str[i] == ' ') // white spaces
            i++;
        
        if (str[i] == '-' || str[i] == '+') // sign
        {
            if (str[i] == '-')
                sign = -1;
            
            i++;
        }
        
        while (str[i] >= '0' && str[i] <= '9')
        {
            // handle overflow
            if (num > INT_MAX / 10 || (num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10))
            {
                if (sign == 1)
                    return INT_MAX;
                else
                    return INT_MIN;
            }
            
            num = num * 10 + (str[i++] - '0');
        }
        
        return sign * num;
    }
};

int main()
{
    string str = "2147483648";
    Solution sol;
    int i = sol.myAtoi(str);
    cout << i << endl;
    cin.get();
    
    return 0;
}