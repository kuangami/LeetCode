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
 * Author: Xinyue Zhang
 */

/** First solution: Time Limit Exceeded
 
public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ans = new ArrayList<Integer>();
        if(s == null || words == null || words.length == 0)
            return ans;
        
        HashMap<String,Integer> map = new HashMap<String,Integer>();
        int wordCount = words.length;
        
        for(int i = 0; i < wordCount; i++)
            map.put(words[i], map.containsKey(words[i]) ? map.get(words[i]) + 1 : 1);
        
        int len = words[0].length();
        for(int i = 0; i < s.length() - len * wordCount + 1; i++){
            HashMap<String,Integer> seen = new HashMap<String,Integer>();
            int j = 0;
            for(; j < wordCount; j++){
                String str = s.substring(i + j * len, i + (j + 1) * len);
                if(map.containsKey(str)){
                    seen.put(str, seen.containsKey(str) ? seen.get(str) + 1 : 1);
                    if(seen.get(str) > map.get(str))
                        break;
                }
                else break;
            }
            
            if(j == wordCount)
                ans.add(i);
        }
        
        return ans;
    }
}**/


public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> ans = new ArrayList<Integer>();
        int wordCount = words.length;
        
        if(s == null || words == null || wordCount == 0 || s.length() == 0)
            return ans;
        
        HashMap<String,Integer> map = new HashMap<String,Integer>();
        
        for(int i = 0; i < wordCount; i++)
            map.put(words[i], map.containsKey(words[i]) ? map.get(words[i]) + 1 : 1);
        
        int len = words[0].length();
        for(int i = 0; i < len; i++) {
            HashMap<String,Integer> seen = new HashMap<String,Integer>();
            int start = i, count = 0;
            for(int j = i; j < s.length() - len + 1; j += len) {
                String str = s.substring(j, j + len);
                if(map.containsKey(str)) {
                    seen.put(str, seen.containsKey(str) ? seen.get(str) + 1 : 1);
                    if(seen.get(str) <= map.get(str))
                        count++;
                    
                    while(seen.get(str) > map.get(str)) {
                        String strLeft = s.substring(start, start + len);
                        seen.put(strLeft, seen.get(strLeft) - 1);
                        if(seen.get(strLeft) < map.get(strLeft))
                            count--;
                        start += len;
                    }
                    
                    if(count == wordCount) {
                        ans.add(start);
                        seen.put(s.substring(start, start + len), seen.get(s.substring(start, start + len)) - 1);
                        start += len;
                        count--;
                    }
                }
                else {
                    count = 0;
                    start = j + len;
                    seen.clear();
                }
            }
        }
        
        return ans;
    }
    
}
