//43. Multiply Strings
/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
 * 
 * Note:
 * 1. The length of both num1 and num2 is < 110.
 * 2. Both num1 and num2 contains only digits 0-9.
 * 3. Both num1 and num2 does not contain any leading zero.
 * 4. You must not use any built-in BigInteger library or convert the inputs to integer directly.
 * 
 * Tags:  Math, String
 * Show Similar Problems: (M) Add Two Numbers (E) Plus One (E) Add Binary (E) Add Strings
 * 
 * @author Xinyue Zhang
 *
 */

public class Solution {
    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0"))
            return "0";
        //product length is smaller than the sum of two multipliers length
        int n1 = num1.length(), n2 = num2.length(), n = n1 + n2;
        int[] product = new int[n];
        //record the product of each digit
        for (int i = n1 - 1; i >= 0; i--)
            for (int j = n2 - 1; j >= 0; j--)
                product[i + j + 1] += (num1.charAt(i) - '0') * (num2.charAt(j) - '0');
        //make each digit valid
        for (int i = n - 1; i > 0; i--) {
            product[i - 1] += product[i] / 10;
            product[i] = product[i] % 10;
        }
        //convert product to string
        StringBuilder res = new StringBuilder();
        if (product[0] != 0)
            res.append(product[0]);
        for (int i = 1; i < n; i++)
            res.append(product[i]);
        
        return res.toString();
    }
    
    public static void main(String[] args) {
        String num1 = "13", num2 = "12";
        Solution sol = new Solution();
        String res = sol.multiply(num1, num2);
        System.out.println(res);
    }
}
