import java.util.HashMap;
//3. Longest Substring Without Repeating Characters
/**
 * Given a string, find the length of the longest substring without repeating characters.
 * 
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 * 
 * Tags: Hash Table, Two Pointers, String
 * Similar Problems: (H) Longest Substring with At Most Two Distinct Characters
 * 
 * @author Xinyue Zhang
 *
 */

public class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s.length() == 0) return 0;
        //create a Hashmap, where character is key and index of the character is value
        HashMap<Character, Integer> map = new HashMap<Character, Integer>();
        int max = 0;
        //two pointers
        for (int i = 0, j = 0; i < s.length(); i++) {
            if (map.containsKey(s.charAt(i)))   
                j = Math.max(j, map.get(s.charAt(i)) + 1);
            map.put(s.charAt(i), i);
            max = Math.max(max, i - j + 1);
        }
        return max;
    }
    
    public static void main(String args[]) {
        String s = "abba";
        Solution sol = new Solution();
        System.out.println(sol.lengthOfLongestSubstring(s));  
    }
}
