// 459. Repeated Substring Pattern
/**
 * Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. 
 * You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.
 * 
 * Example 1:
 * 
 * Input: "abab"
 * Output: True
 * Explanation: It's the substring "ab" twice.
 * 
 * Example 2:
 * 
 * Input: "aba"
 * Output: False
 * 
 * Example 3:
 * 
 * Input: "abcabcabcabc"
 * Output: True
 * Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)
 * 
 * 
 * Tags: String
 * 
 * Similar Problems: (E) Implement strStr()
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>

using namespace std;

// build new string to check repeated pattern
class Solution2 {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        
        // start from n/2 to check its possible substring
        for (int i = n / 2; i > 0; i--) {
            if (n % i == 0) {
                int m = n / i;  // repeated m times
                string s = str.substr(0, i);
                string p = "";
                while (m--) {
                    p += s; // create a new patterned string to compare
                }
                
                if (p == str) { // if equal return true
                    return true;
                }
            }
        }
        
        return false;
    }
};

// check prefix and suffix inspired by KMP
class Solution {
public:
    bool repeatedSubstringPattern(string str) {
        int n = str.size();
        
        // start from n/2 to check its possible substring
        for (int i = n / 2; i > 0; i--) {
            if (n % i == 0) {
                string pre = str.substr(0, n - i);  // prefix
                string suf = str.substr(i);         // suffix
                if (pre == suf) {   // if equal return true
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main() {
    string str = "aaaaa";
    Solution sol;
    bool ans = sol.repeatedSubstringPattern(str);
    cout << ans << endl;
    cin.get();
    
    return 0;
}