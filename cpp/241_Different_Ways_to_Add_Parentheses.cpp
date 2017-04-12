// 241. Different Ways to Add Parentheses
/**
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and 
 * operators. The valid operators are +, - and *.
 * 
 * Example 1
 * Input: "2-1-1".
 * 
 * ((2-1)-1) = 0
 * (2-(1-1)) = 2
 * Output: [0, 2]
 * 
 * Example 2
 * Input: "2*3-4*5"
 * 
 * (2*(3-(4*5))) = -34
 * ((2*3)-(4*5)) = -14
 * ((2*(3-4))*5) = -10
 * (2*((3-4)*5)) = -10
 * (((2*3)-4)*5) = 10
 * Output: [-34, -14, -10, -10, 10]
 * 
 * Tags: Divide and Conquer
 * 
 * Similar Problems: (M) Unique Binary Search Trees II, (H) Basic Calculator, (H) Expression Add Operators
 * 
 * Author: Kuang Qin
 */
 
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdlib>

using namespace std;

// divide and conquer, recursive
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        int n = input.size();
        for (int i = 0; i < n; i++) {
            char ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                // divide the string into two parts
                vector<int> res1 = diffWaysToCompute(input.substr(0, i));
                vector<int> res2 = diffWaysToCompute(input.substr(i + 1));
                
                // calculate result from the two parts
                for (int j = 0; j < res1.size(); j++) {
                    for (int k = 0; k < res2.size(); k++) {
                        if (ch == '+') {
                            res.push_back(res1[j] + res2[k]);
                        }
                        else if (ch == '-') {
                            res.push_back(res1[j] - res2[k]);
                        }
                        else {  // ch == '*'
                            res.push_back(res1[j] * res2[k]);
                        }
                    }
                }
            }
        }
        
        if (res.empty()) {  // input has only numbers
            res.push_back(atoi(input.c_str()));
        }
        
        return res;
    }
};

// divide and conquer + DP
class Solution_DP {
    vector<int> compute(string input, unordered_map<string, vector<int>>& dpMap) {
        vector<int> res;
        int n = input.size();
        for (int i = 0; i < n; i++) {
            char ch = input[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                // divide the string into two parts
                vector<int> res1, res2;
                string str = input.substr(0, i);
                if (dpMap.find(str) != dpMap.end()) {
                    res1 = dpMap[str];
                }
                else {
                    res1 = compute(str, dpMap);
                }
                
                str = input.substr(i + 1);
                if (dpMap.find(str) != dpMap.end()) {
                    res2 = dpMap[str];
                }
                else {
                    res2 = compute(str, dpMap);
                }
                
                // calculate result from the two parts
                for (int j = 0; j < res1.size(); j++) {
                    for (int k = 0; k < res2.size(); k++) {
                        if (ch == '+') {
                            res.push_back(res1[j] + res2[k]);
                        }
                        else if (ch == '-') {
                            res.push_back(res1[j] - res2[k]);
                        }
                        else {  // ch == '*'
                            res.push_back(res1[j] * res2[k]);
                        }
                    }
                }
            }
        }
        
        if (res.empty()) {  // input has only numbers
            res.push_back(atoi(input.c_str()));
        }
        
        dpMap[input] = res;
        return res;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        // use a hashmap to store calculated results
        unordered_map<string, vector<int>> dpMap;
        return compute(input, dpMap);
    }
};

int main() {
    string input = "2*3-4*5";
    Solution sol;
    vector<int> res = sol.diffWaysToCompute(input);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    cin.get();
    return 0;
}