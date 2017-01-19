//67. Add Binary
/**
 * Given two binary strings, return their sum (also a binary string).
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100"
 * 
 * Tags: Math, String
 * Similar Problems:  (M) Add Two Numbers (M) Multiply Strings (E) Plus One
 * 
 * @author Xinyue Zhang
 *
 */

public class Solution {
    public String addBinary(String a, String b) {
        StringBuilder res = new StringBuilder();
        int i = a.length() - 1, j = b.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry == 1) {
            if (i >= 0) carry += a.charAt(i--) - '0';
            if (j >= 0) carry += b.charAt(j--) - '0';
            
            res.append(carry % 2);
            carry = carry / 2;
        }
        return res.reverse().toString();
    }
    
    public static void main(String[] args) {
        String a = "111", b = "10";
        Solution sol = new Solution();
        System.out.println(sol.addBinary(a, b));
    }
}
