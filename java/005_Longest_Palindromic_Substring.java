//5. Longest Palindromic Substring
/**
 * Given a string s, find the longest palindromic substring in s. 
 * You may assume that the maximum length of s is 1000.
 * 
 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * 
 * Example:
 * Input: "cbbd"
 * Output: "bb"
 * 
 * Tags: String
 * Similar Problems: (H) Shortest Palindrome (E) Palindrome Permutation (H) Palindrome Pairs
 * 
 * @author Xinyue Zhang
 *
 */
public class Solution {
    public String longestPalindrome(String s) {
        int n = s.length();
        if (n < 2) return s;
        
        int start = 0, i = 0, maxLen = 0;
        //the max length is 2 * (n - i)
        while (i < n - 1 && maxLen < 2 * (n - i)) {
            int left = i, right = i;
            //skip duplicates, which are palindromic string
            while (right < n - 1 && s.charAt(right) == s.charAt(right + 1)) 
                right++;
            
            i = right + 1; 
            
            while (left > 0 && right < n - 1 && s.charAt(left - 1) == s.charAt(right + 1)) {
                left--;
                right++;
            }
            //update max length
            int curLen = right - left + 1;
            if (curLen > maxLen) {
                maxLen = curLen;
                start = left;
            }  
        }
        
        return s.substring(start, start + maxLen);
    }
    
    public static void main(String args[]) {
        String s = "babbad";
        Solution sol = new Solution();
        System.out.println(sol.longestPalindrome(s));
    }
}
