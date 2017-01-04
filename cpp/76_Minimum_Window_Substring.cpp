//76. Minimum Window Substring
/**
 * Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
 * 
 * For example,
 * S = "ADOBECODEBANC"
 * T = "ABC"
 * Minimum window is "BANC".
 * 
 * Note:
 * If there is no such window in S that covers all characters in T, return the empty string "".
 * 
 * If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 * 
 * Tags: Hash Table, Two Pointers, String
 *
 * Similar Problems: (H) Substring with Concatenation of All Words, (M) Minimum Size Subarray Sum, (H) Sliding Window Maximum
 *
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() == 0 || t.size() == 0)
            return "";
        
        vector<int> map(128, 0);    // hash map for ascii char
        int count = t.size();   // number of char needs to be matched
        for (int i = 0; i < count; i++)
            map[t[i]]++;    // initialize the hash map
        
        int left = 0, right = 0, len = INT_MAX, start = 0;
        while (right < s.size())
        {
            if (map[s[right++]]-- > 0)   // move right pointer to find match in t
                count--;
            
            while (count == 0)  // all characters found
            {
                if (right - left < len) // assign start and length for output
                {
                    start = left;
                    len = right - left;
                }
                
                if (map[s[left++]]++ == 0)  // move left pointer to find the minimum length
                    count++;    // make it invalid, go back to right pointer move
            }
        }
        
        if (len == INT_MAX) // not found
            return "";
        
        return s.substr(start, len);
    }
};

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    string str = sol.minWindow(s, t);
    
    cout << s << endl;
    cout << t << endl;
    cout << str << endl;
    cin.get();
    
    return 0;
}