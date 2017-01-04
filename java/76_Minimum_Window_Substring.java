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
        
        HashMap<Character,Integer> map = new HashMap<Character,Integer>();
        int count = t.length();
        char c;
        for(int i = 0; i < count; i++){
            c = t.charAt(i);
            map.put(c, map.containsKey(c) ? map.get(c) + 1 : 1);
        }
        
        int left = 0, right = 0, len = Integer.MAX_VALUE, start = 0;
        while(right < s.length()){
            c = s.charAt(right++);
            if(map.containsKey(c)){
                if(map.get(c) > 0)
                    count--;
                map.put(c, map.get(c) - 1);
            }
            
            while(count == 0){
                if(right - left < len){
                    start = left;
                    len = right - left;
                }
                
                c = s.charAt(left++);
                if(map.containsKey(c)){
                    if(map.get(c) == 0)
                        count ++;
                    map.put(c, map.get(c) + 1);
                }
            }
        }
        
        if(len == Integer.MAX_VALUE)
            return "";
        
        return s.substring(start, start + len);
    }
}
