// 28. Implement strStr()
/*
 * Implement strStr().
 * 
 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 * 
 * Tags: Two Pointers, String
 * 
 * Similar Problems: (H) Shortest Palindrome, (E) Repeated Substring Pattern
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// brute force, time: O(n^2), space: O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        // brute-force search
        for (int i = 0; ; i++) {
            for (int j = 0; ; j++) {
                if (j == needle.size()) {   // substring matched
                    return i;
                }
                
                if (i + j == haystack.size()) {   // at the end of haystack
                    return -1;
                }
                
                if (needle[j] != haystack[i + j]) { // character not match
                    break;
                }
            }
        }
        
        return -1;
    }
};

// KMP Algorithm, time: O(n), space: O(m)
class Solution_KMP {
private:
    vector<int> getNextVal(string s) {
        int n = s.size();
        vector<int> next(n, 0);
        next[0] = -1;
        
        int i = 0, j = -1;
        while (i < n - 1) {
            // s[j] is the prefix, s[i] is the suffix
            if (j == -1 || s[i] == s[j]) {  // at the beginning or prefix and suffix matched
                i++;
                j++;
                
                if (s[i] != s[j]) {
                    next[i] = j;
                }
                else {
                    // if s[i] == s[next[i]], the next comparison will not match
                    // so keep searching recursively: j -> next[j] -> next[next[j]]
                    next[i] = next[j];
                }
            }
            else {
                // search recursively
                j = next[j];
            }
        }
        
        return next;
    }

public:    
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if (m == 0) {
            return 0;
        }
        
        // KMP lookup table
        vector<int> next = getNextVal(needle);
        int i = 0, j = 0;
        while (i < n && j < m) {
            if (j == -1 || haystack[i] == needle[j]) {
                i++;
                j++;
            }
            else {
                j = next[j];
            }
        }
            
        if (j == m) {   // substring matched
            return i - j;
        }
        
        // not matched
        return -1;
    }
};

int main() {
    string haystack = "mississippi", needle = "a";
    Solution_KMP sol;
    int ans = sol.strStr(haystack, needle);
    cout << ans << endl;
    cin.get();
    return 0;
}
