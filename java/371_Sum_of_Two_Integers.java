//371. Sum of Two Integers
/**
 * Calculate the sum of two integers a and b, 
 * but you are not allowed to use the operator + and -.
 * 
 * Example:
 * Given a = 1 and b = 2, return 3.
 * 
 * Tags: Bit Manipulation
 * Similar Problems: (M) Add Two Numbers
 * 
 * @author Xinyue Zhang
 *
 */
public class Solution {
    public int getSum(int a, int b) {
        if (a == 0) return b;
        if (b == 0) return a;
        
        while (b != 0) {
            int carry = a & b;  //find carry
            a = a ^ b;          //xor
            b = carry << 1;     //left shift carry bit
        }
        
        return a;
    }
    
    public static void main(String[] args) {
        int a = 7, b = 3;
        Solution sol = new Solution();
        System.out.println(sol.getSum(a, b));
    }
}
