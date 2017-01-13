// 18. 4Sum
/**
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 * 
 * Note: The solution set must not contain duplicate quadruplets.
 * 
 * For example, given array S = [1, 0, -1, 0, -2, 2], and target = 0.
 * 
 * A solution set is:
 * [
 *   [-1,  0, 0, 1],
 *   [-2, -1, 1, 2],
 *   [-2,  0, 0, 2]
 * ]
 * 
 * Tags: Array, Hash Table, Two Pointers
 * 
 * Similar Problems: (E) Two Sum, (M) 3Sum, (M) 4Sum II
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4)
            return ans;
        
        // sort the array
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 3; i++)
        {
            // possible minimum is larger than target
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            
            // skip duplicates
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            // possible maximum is smaller than target, move to the next number
            if (nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1] < target)
                continue;
            
            int threesum = target - nums[i]; // convert to three sum problem
            for (int j = i + 1; j < n - 2; j++)
            {
                // possible minimum is larger than threesum
                if (nums[j] + nums[j + 1] + nums[j + 2] > threesum)
                    break;
                
                // skip duplicates
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                
                // possible maximum is smaller than threesum, move to the next number
                if (nums[j] + nums[n - 2] + nums[n - 1] < threesum)
                    continue;
                
                int twosum = threesum - nums[j];    // convert to two sum problem
                int left = j + 1, right = n - 1;    // use two pointers
                while (left < right)
                {
                    int sum = nums[left] + nums[right];
                    if (sum < twosum)
                        while (++left < right && nums[left] == nums[left - 1]) {}   // skip duplicates from left
                    else if (sum > twosum)
                        while (left < --right && nums[right] == nums[right + 1]) {}   // skip duplicates from right
                    else    // sum == twosum
                    {
                        vector<int> quadruplets;
                        quadruplets.push_back(nums[i]);
                        quadruplets.push_back(nums[j]);
                        quadruplets.push_back(nums[left]);
                        quadruplets.push_back(nums[right]);
                        ans.push_back(quadruplets);
                        
                        while (++left < right && nums[left] == nums[left - 1]) {}   // skip duplicates from left
                        while (left < --right && nums[right] == nums[right + 1]) {}   // skip duplicates from right
                    }
                }
            }
        }
        
        return ans;
    }
};

int main()
{
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution sol;
    vector<vector<int>> res = sol.fourSum(nums, target);
    
    for (int i = 0; i < res.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        
        cout << "]" << endl;
    }
    cin.get();
    
    return 0;
}