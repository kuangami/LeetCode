// 65. Valid Number
/**
 * Validate if a given string is numeric.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 * 
 * Tags: Math, String
 * 
 * Similar Problems: (E) String to Integer (atoi)
 *
 * Author: Kuang Qin
 */
 
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int begin = 0, end = n - 1;

        // remove prefixing and suffixing spaces
        while ((begin < n) && (s[begin] == ' '))
        {
            begin++;
        }
        
        while ((end > 0) && (s[end] == ' '))
        {
            end--;
        }
        
        // if the length is less than zero, return false
        if (begin > end)
        {
            return false;
        }
        
        // define two flags for dot('.') and scientific notation('e')
        // define two more flags for number before and after 'e' for result output
        bool hasDot = false, hasExp = false, bNum = false, bNumAfterE = false;
        
        for (int i = begin; i <= end; i++)
        {
            if (s[i] == '+' || s[i] == '-') // sign
            {
                if (i != begin && s[i - 1] != 'e')
                    // sign can be only at the beginning or after 'e'
                    return false;
            }
            else if (s[i] >= '0' && s[i] <= '9')    // digit
            {
                // valid number
                bNum = true;
                bNumAfterE = true;
            }
            else if (s[i] == 'e')   // 'e'
            {
                if (hasExp || !bNum)
                    // a) already has an 'e'
                    // b) invalid number before e
                    return false;
                
                hasExp = true;      // set has 'e' flag
                bNumAfterE = false; // begin validating number after 'e'
            }
            else if (s[i] == '.')   // dot
            {
                if (hasDot || hasExp)
                    // a) already has a dot
                    // b) dot after 'e'
                    return false;
                
                hasDot = true;  // set has dot flag
            }
            else    //other characters
                return false;
        }
        
        return bNum && bNumAfterE;  // true if both numbers before and after 'e' are valid
    }
};

class Solution2 {
public:
    bool isNumber(string s) {
        int n = s.size();
        int begin = 0, end = n - 1;

        // remove prefixing and suffixing spaces
        while ((begin < n) && (s[begin] == ' '))
        {
            begin++;
        }
        
        while ((end > 0) && (s[end] == ' '))
        {
            end--;
        }

        // remove sign if exists
        if ((s[begin] == '+') || (s[begin] == '-'))
        {
            begin++;
        }

        // if the length is less than zero, return false
        if (begin > end)
        {
            return false;
        }

        // define two flags for dot('.') and scientific notation('e')
        bool hasDot = false, hasExp = false;
        for (int i = begin; i <= end; i++)
        {
            switch (s[i])
            {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                // if digit do nothing
                break;

            case '.':
                if ((begin == end) || hasDot || hasExp)
                {
                    // 3 cases return false:
                    // a) dot is the only character
                    // b) two dots
                    // c) dot after 'e'
                    return false;
                }

                hasDot = true;
                break;

            case 'e':
                if ((i == begin) || (i == end) || hasExp ||
                    ((s[i - 1] == '.') && (i - 1 == begin)))
                {
                    // 4 cases return false:
                    // a) 'e' at the beginning
                    // b) 'e' at the end
                    // c) two 'e'
                    // d) only '.' before 'e' (example: '.e1')
                    return false;
                }

                hasExp = true;
                break;

            case '+':
            case '-':
                if ((i == begin) || (i == end) || s[i - 1] != 'e')
                {
                    // after removing the sign, the sign can only exists after 'e'
                    // 3 cases return false:
                    // a) sign at the beginning (this also ensures s[i - 1] accessible)
                    // b) sign at the end (example: '3e-')
                    // c) sign not after 'e'
                    return false;
                }
                break;

            default:
                return false;
            }
        }

        return true;
    }
};

int main()
{
    string s = "3e-";
    Solution sol;
    cout << sol.isNumber(s) << endl;
    cin.get();
    
    return 0;
}