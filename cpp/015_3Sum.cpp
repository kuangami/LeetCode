// 15. 3Sum
/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note: The solution set must not contain duplicate triplets.
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * 
 * A solution set is:
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 *
 * Tags: Array, Two Pointers
 *
 * Similar Problems: (E) Two Sum, (M) 3Sum Closest, (M) 4Sum, (M) 3Sum Smaller
 *
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        
        if (n < 3)
            return ans;
        
        // sort the array
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; i++)
        {
            // use two pointers, search if nums[left] + nums[right] = -nums[i]
            int left = i + 1, right = n - 1;
            
            // nums[i] <= nums[left] <= nums[right], so nums[i] must not be bigger than zero
            if (nums[i] > 0)
                break;
            
            // skip duplicates
            if ((i > 0) && nums[i] == nums[i - 1])
                continue;
            
            while (left < right)
            {
                // stop if the sum of two smaller numbers is already bigger than zero
                if (nums[i] + nums[left] > 0)
                    break;
                
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum < 0)
                    while (++left < right && nums[left] == nums[left - 1]) {}   // skip duplicates from left  
                else if (sum > 0)
                    while (left < --right && nums[right] == nums[right + 1]) {} // skip duplicates from right 
                else    // sum == 0
                {
                    vector<int> triplets;
                    triplets.push_back(nums[i]);
                    triplets.push_back(nums[left]);
                    triplets.push_back(nums[right]);
                    ans.push_back(triplets);
                    
                    
                    while (++left < right && nums[left] == nums[left - 1]) {}   // skip duplicates from left
                    while (left < --right && nums[right] == nums[right + 1]) {} // skip duplicates from right 
                }
            }
        }
        
        return ans;
    }
};

int main()
{
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution sol;
    vector<vector<int>> ans = sol.threeSum(nums);
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        
        cout << "]" << endl;
    }
    cin.get();

    return 0;
}