//8. String to Integer (atoi)
/**
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 * 
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
 * 
 * Requirements for atoi:
 * The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.
 * The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.
 * If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.
 * If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
 * 
 * Tags: Math, String
 * 
 * Similar Problems: (E) Reverse Integer (H) Valid Number
 * 
 * @author Xinyue Zhang
 *
 */
public class Solution {
    public int myAtoi(String str) {
        int i = 0, res = 0, sign = 1;
        
        if (str == null || str.length() == 0)
            return 0;
        
        while (i < str.length() && str.charAt(i) == ' ')
            i++;
        
        if (str.charAt(i) == '-') {
            sign = -1;
            i++;
        }   
        else if (str.charAt(i) == '+') 
            i++;
        
        for(; i < str.length(); i++) {
            int tail = str.charAt(i) - '0';
            if (tail <= 9 && tail >= 0) {
                if( Integer.MAX_VALUE/10 < res || Integer.MAX_VALUE/10 == res && Integer.MAX_VALUE %10 < tail)
                    return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
                res = res * 10 + tail;
            }
            else break;
        }

        return sign * res;
    }
    
    public static void main(String[] args) {
        String str1 = "-2147483647", str2 = "", str3 = "  -dfds909", str4 = "1234", str5 = "+-1", str6 = "786872346283746287346234";
        Solution sol = new Solution();
        System.out.printf("str1 = %d\n", sol.myAtoi(str1));
        System.out.printf("str2 = %d\n", sol.myAtoi(str2));
        System.out.printf("str3 = %d\n", sol.myAtoi(str3));
        System.out.printf("str4 = %d\n", sol.myAtoi(str4));
        System.out.printf("str5 = %d\n", sol.myAtoi(str5));
        System.out.printf("str6 = %d\n", sol.myAtoi(str6));
        
    }

}
