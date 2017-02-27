// 6. ZigZag Conversion
/**
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 * 
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * 
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 * 
 * string convert(string text, int nRows);
 * 
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 * 
 * Tags: String
 * 
 * Author: Xinyue Zhang
 */

public class Solution {
    public String convert(String s, int nRows) {
        if (s == null || s.isEmpty()) {
            return s;
        }

        int length = s.length();
        if (length <= nRows || nRows <= 1) {
            return s;
        }

        StringBuilder sb = new StringBuilder();

        int step = 2 * (nRows - 1);
        int count = 0;

        for (int i = 0; i < nRows; i++){
            int interval = step - 2 * i;

            for (int j = i; j < length; j += step){
                   sb.append(s.charAt(j));
                count++;
                if (interval > 0 && interval < step 
                    && j + interval < length 
                    && count <  length) {
                    sb.append(s.charAt(j + interval));
                    count++;
                }
            }
        }
        return sb.toString();  
    }
    
    public static void main(String args[]) {
        String s = "PAYPALISHIRING";
        Solution sol = new Solution();
        String res = sol.convert(s, 3);
        System.out.println(res);
    }
}
