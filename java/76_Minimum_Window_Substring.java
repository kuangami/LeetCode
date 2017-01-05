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
 * Author: Xinyue Zhang
 */
 
public class Solution {
    public String minWindow(String s, String t) {
        if(s.isEmpty() || t.isEmpty()) 
            return "";
        int[] map = new int[128];
        int count = t.length();

        for(int i = 0; i < count; i++)
            map[t.charAt(i)]++;
        
        int left = 0, right = 0, len = Integer.MAX_VALUE, start = 0;
        while(right < s.length()){
                if(map[s.charAt(right++)]-- > 0)
                    count--;
            
            while(count == 0){
                if(right - left < len){
                    start = left;
                    len = right - left;
                }
                
                    if(map[s.charAt(left++)]++ == 0)
                        count ++;
            }
        }
        
        if(len == Integer.MAX_VALUE)
            return "";
        
        return s.substring(start, start + len);
    }
}
