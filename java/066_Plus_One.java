//66. Plus One
/**
 * Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
 * 
 * You may assume the integer do not contain any leading zero, except the number 0 itself.
 * 
 * The digits are stored such that the most significant digit is at the head of the list.
 * 
 * Tags: Array, Math
 * 
 * Similar Problems:  (M) Multiply Strings (E) Add Binary (M) Plus One Linked List
 * 
 * @author Xinyue Zhang
 *
 */

public class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;
        
        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            else
                digits[i] = 0;
        }
        
        int[] res = new int[n + 1];
        res[0] = 1;
        return res;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] digits = {9,9,9,9};
        int[] res = sol.plusOne(digits);
        for (int i = 0; i < res.length; i++)
            System.out.println(res[i]);
    }
}
