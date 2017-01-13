// 16. 3Sum Closest
/**
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 * 
 *     For example, given array S = {-1 2 1 -4}, and target = 1.
 * 
 *     The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 * 
 * Tags: Array, Two Pointers
 * 
 * Similar Problems: (M) 3Sum, (M) 3Sum Smaller
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3)
            return 0;
        
        // sort the array
        sort(nums.begin(), nums.end());
        
        // possible maximum
        int res = nums[n - 3] + nums[n - 2] + nums[n - 1];
        if (res <= target)
            return res;
        
        // possible minimum
        res = nums[0] + nums[1] + nums[2];
        if (res >= target)
            return res;
        
        for (int i = 0; i < n - 2; i++)
        {
            // use two pointers to search the closest
            int left = i + 1, right = n - 1;
            
            while (left < right)
            {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < abs(res - target))  // res starts from possible minimum
                {
                    res = sum;  // sum is closer, record result
                }
                
                if (sum < target)
                    while (++left < right && nums[left] == nums[left - 1]) {}   // skip duplicates from left
                else if (sum > target)
                    while (left < --right && nums[right] == nums[right + 1]) {} // skip duplicates from right
                else
                    return sum;
            }
        }
        
        return res;
    }
};

int main()
{
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution sol;
    int res = sol.threeSumClosest(nums, target);
    cout << res << endl;
    cin.get();
    
    return 0;
}