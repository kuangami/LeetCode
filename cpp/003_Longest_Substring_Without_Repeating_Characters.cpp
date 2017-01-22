// 3. Longest Substring Without Repeating Characters
/**
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Examples:
 * 
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * 
 * Given "bbbbb", the answer is "b", with the length of 1.
 * 
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 * Tags: Hash Table, Two Pointers, String
 * 
 * Similar Problems: (H) Longest Substring with At Most Two Distinct Characters
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        
        vector<int> map(128, -1);    // hash table for ascii chars
        int left = 0, right = 0, len = 0;
        
        for (right = 0; right < n; right++) {
            if (map[s[right]] != -1) {   // s[right] found
                if (left < map[s[right]] + 1)
                    left = map[s[right]] + 1;    // update left position to the first non-repeating character
            }
            
            map[s[right]] = right;  // update the last appeared location of s[right]
            if (len < right - left + 1)
                len = right - left + 1;   // update the max length
        }
        
        return len;
    }
};

int main() {
    string s = "pwwkwe";
    Solution sol;
    int len = sol.lengthOfLongestSubstring(s);
    cout << len << endl;
    cin.get();
    
    return 0;
}