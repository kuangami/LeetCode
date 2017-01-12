//1. Two Sum
/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution.
 *
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * 
 * The return format had been changed to zero-based indices. Please read the above updated description carefully.
 * 
 * Tags: Array, Hash Table
 * 
 * Similar Problems: (M) 3Sum, (M) 4Sum, (M) Two Sum II - Input array is sorted, (E) Two Sum III - Data structure design
 *
 * Author: Kuang Qin
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        vector<int> res;
        unordered_map<int, int> map;

        for (int i = 0; i < len; i++)
        {
            int diff = target - nums[i];
            if (map.find(diff) != map.end())    // use hash map to quick search, if found, ouput the result
            {
                res.push_back(map[diff]);
                res.push_back(i);
                break;
            }

            // Save the numbers into an unordered map when searching
            map[nums[i]] = i;
        }

        return res;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution sol;
    vector<int> ans = sol.twoSum(nums, target);
    cout << "[" << ans[0] << ", " << ans[1] << "]" << endl;
    cin.get();
    
    return 0;
}