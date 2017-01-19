//415. Add Strings
/**
 * Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
 * 
 * Note:
 * 1. The length of both num1 and num2 is < 5100.
 * 2. Both num1 and num2 contains only digits 0-9.
 * 3. Both num1 and num2 does not contain any leading zero.
 * 4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * 
 * Tags: Math
 * Similar Problems: (M) Add Two Numbers (M) Multiply Strings
 * 
 * @author Xinyue Zhang
 *
 */

public class Solution {
    public String addStrings(String num1, String num2) {
        StringBuilder res = new StringBuilder();
        int i = num1.length() - 1, j = num2.length() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry == 1) {
            int sum = 0;
            if (i >= 0) sum += num1.charAt(i--) - '0';
            if (j >= 0) sum += num2.charAt(j--) - '0';
            
            res.append((sum + carry) % 10);
            carry = (sum + carry) / 10;
        }
        return res.reverse().toString();
    }
    
    public static void main(String[] args) {
        String num1 = "123", num2 = "945";
        Solution sol = new Solution();
        System.out.println(sol.addStrings(num1, num2));
    }
}
