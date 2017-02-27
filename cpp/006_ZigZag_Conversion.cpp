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
 * Author: Kuang Qin
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows <= 1) {
            return s;
        }
        
        string res;
        
        // P   | A   | H   | N
        // A P | L S | I I | G
        // Y   | I   | R   |
        // each row has 2 elements except the first row and the last row in one period
        int period = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {         // build each row
            for (int j = i; j < s.size(); j += period) {    // build string in each period
                res += s[j];
                
                // 0     : 0                            |
                // 1     : 1                   p - 1    |
                // .       .                  .         |
                // .       .                 .          |
                // .       .                .           |
                // i     : j            p - i           |
                // .       .           .                |
                // .       .          .                 |
                // .       .         .                  |
                // n - 2 : n - 2    p - (n - 2)         |
                // n - 1 : n - 1                        |
                // calculate the position of the second element
                int k = j - i + period - i;
                
                // if not the first or last row append the second element
                if (i != 0 && i != numRows - 1 && k < s.size()) {
                    res += s[k];
                }
            }
        }
        
        return res;
    }
};

int main() {
    string s = "PAYPALISHIRING";
    Solution sol;
    string res = sol.convert(s, 3);
    cout << res << endl;
    cin.get();
    
    return 0;
}