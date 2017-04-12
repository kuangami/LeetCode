// 214. Shortest Palindrome
/**
 * Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome 
 * you can find by performing this transformation.
 * 
 * For example:
 * 
 * Given "aacecaaa", return "aaacecaaa".
 * 
 * Given "abcd", return "dcbabcd".
 * 
 * Tags: String
 * 
 * Similar Problems: (M) Longest Palindromic Substring, (E) Implement strStr(), (H) Palindrome Pairs
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() < 2) {
            return s;
        }
        
        // build a string with its reverse
        // then use KMP to find the longest common prefix and suffix, which is a palindrome
        //
        // for example: 
        //  a b a b c # c b a b a
        //
        // longest common string in prefix and suffix is "aba"
        // its length will be shown as the value of the last char in the KMP table
        
        string r = s;
        reverse(r.begin(), r.end());
        string l = s + "#" + r;
        
        int n = l.size();
        vector<int> table(n, 0);    // KMP lookup table
        for (int i = 1; i < n; i++) {
            // in substring l[0...i]: l[i] is the suffix, l[j] should be set to the char after the longest common prefix
            // table[i - 1] shows the longest common prefix and suffix matched for the last char
            int j = table[i - 1];
            
            // if not match, recursively searching for a shorter string
            while (j > 0 && l[i] != l[j]) {
                j = table[j - 1];
            }
            
            // if matched, extend the common prefix and suffix by 1
            if (l[j] == l[i]) {
                j++;
            }
            
            // assign the value to current substring
            table[i] = j;
        }
        
        // table[n - 1] represents the length of the longest palindrome
        return r.substr(0, s.size() - table[n - 1]) + s;
    }
};

int main() {
    string s = "ababc";
    Solution sol;
    string ans = sol.shortestPalindrome(s);
    cout << ans << endl;
    cin.get();
    
    return 0;
}