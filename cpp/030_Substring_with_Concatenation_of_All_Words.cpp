// 30. Substring with Concatenation of All Words
/**
 * You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
 * 
 * For example, given:
 * s: "barfoothefoobarman"
 * words: ["foo", "bar"]
 * 
 * You should return the indices: [0,9].
 * (order does not matter).
 * 
 * Tags: Hash Table, Two Pointers, String
 * 
 * Similar Problems: (H) Minimum Window Substring
 * 
 * Author: Kuang Qin
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// move one pointer till the end of string l times, l = words[0].size() 
// time complexity: O(l*n)
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size(), wordCount = words.size();
        if (n == 0 || wordCount == 0)
            return ans;
        
        // hash map to track each word in words
        unordered_map<string, int> map;
        for (int i = 0; i < wordCount; i++)
            map[words[i]]++;    // initialize the hash map
        
        int len = words[0].size();
        for (int i = 0; i < len; i++)
        {
            int start = i, count = 0;   // record the starting location and found word counter
            unordered_map<string, int> seen;    // hash map to track how many times a word is seen
            for (int j = i; j < n - len + 1; j += len)  // advance by word length till the end
            {
                string str = s.substr(j, len);
                if (map.find(str) != map.end()) // found the word
                {
                    if (++seen[str] <= map[str])
                    {
                        count++;
                    }
                    
                    // the word is seen more than it should be
                    // shift the window from the left to the location right after that word
                    while (seen[str] > map[str])
                    {
                        string strLeft = s.substr(start, len);
                        if (--seen[strLeft] < map[strLeft])
                            count--;
                        start += len;
                    }
                    
                    if (count == wordCount)     // all words found
                    {
                        ans.push_back(start);   // record the result
                        // shift window from left by one word
                        seen[s.substr(start, len)]--;
                        count--;
                        start += len;
                    }
                }
                else    // not found, shift the starting location by one word
                {
                    seen.clear();
                    count = 0;
                    start = j + len;
                }
            }
        }
        
        return ans;
    }
};

// check for k * l each time in the inner loop, k = words.size(), l = words[0].size()
// time complexity: O(k*l*n)
class Solution2 {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int n = s.size(), wordCount = words.size();
        if (n == 0 || wordCount == 0)
            return ans;
        
        // hash map to track each word in words
        unordered_map<string, int> map;
        for (int i = 0; i < wordCount; i++)
            map[words[i]]++;    // initialize the hash map
        
        int len = words[0].size();
        for (int i = 0; i < n - wordCount * len + 1; i++)   // check wordCount * len
        {
            unordered_map<string, int> seen;    // hash map to track how many times a word is seen
            int j = 0;
            for (; j < wordCount; j++)
            {
                string str = s.substr(i + j * len, len);
                if (map.find(str) != map.end()) // found the word
                {
                    seen[str]++;
                    if (seen[str] > map[str]) // the word is seen more than it should be
                        break;
                }
                else    // not found
                    break;
            }
            
            if (j == wordCount)     // all words found
                ans.push_back(i);
        }
        
        return ans;
    }
};

int main()
{
    string s = "barfoofoobarthefoobarman";
    vector<string> words;
    words.push_back("bar");
    words.push_back("foo");
    words.push_back("the");
    
    Solution sol;
    vector<int> ans = sol.findSubstring(s, words);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
    cin.get();

    return 0;
}