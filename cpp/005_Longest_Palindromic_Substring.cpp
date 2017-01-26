// 5. Longest Palindromic Substring
/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * 
 * Example:
 * 
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * Example:
 * 
 * Input: "cbbd"
 * Output: "bb"
 * 
 * Tags: String
 * 
 * Similar Problems: (H) Shortest Palindrome (E) Palindrome Permutation (H) Palindrome Pairs
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }
        
        int start = 0, maxLen = 0, i = 0;
        // stop if max length is the possible largest
        while (i < n - 1 && maxLen < 2 * (n - i)) {
            int left = i, right = i;
            
            // check duplicates, which are natural palindromic string
            while (right < n - 1 && s[right + 1] == s[right]) {
                right++;
            }
            
            i = right + 1;  // skip all the duplicates for next check
            
            // start from middle, check both sides
            while (left > 0 && right < n - 1 && s[left - 1] == s[right + 1]) {
                left--;
                right++;
            }
            
            // update max length
            int curLen = right - left + 1;
            if (curLen > maxLen) {
                maxLen = curLen;
                start = left;
            }
        }
        
        return s.substr(start, maxLen);
    }
};

int main() {
    string s = "babbad";
    Solution sol;
    string res = sol.longestPalindrome(s);
    cout << res << endl;
    cin.get();

    return 0;
}