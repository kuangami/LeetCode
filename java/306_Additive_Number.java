// 306. Additive Number
/**
 * Additive number is a string whose digits can form additive sequence.
 *
 * A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
 *
 * For example:
 * "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
 * 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
 *
 * "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
 * 1 + 99 = 100, 99 + 100 = 199
 * Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
 *
 * Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
 *
 * Follow up:
 * How would you handle overflow for very large input integers?
 *
 * Author: Xinyue Zhang
 */

package Solution;

import java.util.ArrayList;

public class Solution {
    public boolean isAdditiveNumber(String num) {
        int n = num.length();
        
        for (int i = 1; i <= n / 2; i++)
            for (int j = 1; j <= (n - i) / 2; j++)
                if (isSum(num.substring(0, i), num.substring(i, i + j), num.substring(i+j)))
                    return true;
        return false;
    }
    
    public boolean isSum(String num1, String num2, String str) {
        if ((num1.length() > 1 && num1.charAt(0) == '0') || (num2.length() > 1 && num2.charAt(0) == '0'))
            return false;
        
        String sum = strAdd(num1, num2);
        
        if (str.equals(sum))
            return true;
        
        if (str.length() <= sum.length() || !sum.equals(str.substring(0, sum.length())))
            return false;
        else
            return isSum(num2, sum, str.substring(sum.length()));
    }
    
    public String strAdd(String num1, String num2) {
        ArrayList<Character> strSum = new ArrayList<Character>();
        int n1 = num1.length() - 1, n2 = num2.length() - 1, carry = 0;
        String res = "";
        
        while (n1 >= 0 || n2 >= 0) {
            int sum = carry + (n1 >= 0 ? num1.charAt(n1--) - '0' : 0) + (n2 >= 0 ? num2.charAt(n2--) - '0' : 0);
            strSum.add((char) (sum % 10 + '0'));
            carry = sum / 10;
        }
        
        if (carry == 1)
            strSum.add((char) (carry + '0'));
        
        StringBuilder builder = new StringBuilder(strSum.size());
        for (Character ch: strSum) {
            builder.append(ch);
        }
        res = builder.toString();
        res = new StringBuilder(res).reverse().toString();
        return res;
    }
    
    
    public static void main(String[] args) {
        
        String num = "100010";
        Solution sol = new Solution();
        boolean bAdditive = sol.isAdditiveNumber(num);
        if(bAdditive)
            System.out.println("true");
        else
            System.out.println("false");
        
        String a = "199100199";
        boolean d = sol.isAdditiveNumber(a);
        System.out.printf("199100199? = %b\n",d);
    }
    
}