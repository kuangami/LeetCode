// 9. Palindrome Number
/**
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 * Some hints:
 * Could negative integers be palindromes? (ie, -1)
 * 
 * If you are thinking of converting the integer to string, note the restriction of using extra space.
 * 
 * You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. 
 * How would you handle such case?
 * 
 * There is a more generic way of solving this problem.
 * 
 * Tags: Math
 * 
 * Similar Problems: (E) Palindrome Linked List
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) {
            // negative integers and integers that end with 0 are not palindrome
            return false;
        }
        
        int rev = 0;
        while (x > rev) {   // reverse the integer till half then compare, no overflow risk
            rev *= 10;
            rev += x % 10;
            x /= 10;
        }
        
        // even digits: x == rev if palindrome
        // odd digits: x == rev / 10 if padlindrome
        return (x == rev || x == rev / 10);
    }
};

int main() {
    int x = 1221;
    Solution sol;
    bool ans = sol.isPalindrome(x);
    cout << ans << endl;
    cin.get();
    
    return 0;
}