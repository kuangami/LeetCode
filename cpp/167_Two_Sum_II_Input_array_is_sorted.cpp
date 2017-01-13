// 167. Two Sum II - Input array is sorted
/**
 * Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
 * 
 * The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 * 
 * You may assume that each input would have exactly one solution.
 * 
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 * 
 * Tags: Array, Two Pointers, Binary Search
 * 
 * Similar Problems: (E) Two Sum
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int n = numbers.size();
        if (n < 2)
            return res;
        
        // use two pointers
        int left = 0, right = n - 1;
        
        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            
            if (sum == target)
            {
                res.push_back(left + 1);
                res.push_back(right + 1);
                break;
            }
            else if (sum < target)
                left++;
            else    // sum > target
                right--;
        }
        
        return res;
    }
};

int main()
{
    vector<int> numbers = {2, 3, 4};
    int target = 6;
    Solution sol;
    vector<int> res = sol.twoSum(numbers, target);
    cout << "index1 = " << res[0] << ", index2 = " << res[1] << endl;
    cin.get();
    
    return 0;
}
