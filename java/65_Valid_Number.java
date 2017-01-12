//65. Valid Number
/**
 * Validate if a given string is numeric.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
 * 
 * Tags: Math, String
 * 
 * Similar Problems: (E) String to Integer (atoi)
 * 
 * @author Xinyue Zhang
 *
 */
public class Solution {
    public boolean isNumber(String s) {
        boolean e = false;
        boolean dot = false;
        boolean number = false;
        boolean numberAfterE = false;

        s = s.trim();
        
        for (int i = 0; i < s.length(); i++) {
        	if (s.charAt(i) == '-' || s.charAt(i) == '+') {
        		if (i != 0 && s.charAt(i - 1) != 'e')
        		    return false;
        	}
        	else if (s.charAt(i) >= '0' && s.charAt(i) <= '9') {
        		number = true;
        		numberAfterE = true;
        	}
        	else if (s.charAt(i) == 'e') {
        		if (e || !number)
        			return false;
        		e = true;
        		numberAfterE = false;
        	}
        	else if (s.charAt(i) == '.') {
        		if (e || dot)
        			return false;
        		dot = true;
        	}
        	else 
        		return false;
        		
        }
    	return number && numberAfterE;
    }
    
    public static void main(String[] args) {
    	String s1 = "1", s2 = " +1", s3 = "2s2e342",
    			s4 = " +-1 ", s5 = "2.4", s6 = ".4", s7 = "2e4", s8 = "-12e-10";
    	Solution sol = new Solution();
    	System.out.println(sol.isNumber(s1));
    	System.out.println(sol.isNumber(s2));
    	System.out.println(sol.isNumber(s3));
    	System.out.println(sol.isNumber(s4));
    	System.out.println(sol.isNumber(s5));
    	System.out.println(sol.isNumber(s6));
    	System.out.println(sol.isNumber(s7));
    	System.out.println(sol.isNumber(s8));
    }
}
