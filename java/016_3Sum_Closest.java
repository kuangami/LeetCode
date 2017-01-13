import java.util.Arrays;

//16. 3Sum Closest
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
* Author: Xinyue Zhang
*/

public class Solution {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int n = nums.length;
        if (n < 3) return 0;
        
        //if maximum smaller than target, then return
        int res = nums[n - 1] + nums[n - 2] + nums[n - 3];
        if (res <= target) return res;
        
        //if minimum larger than target, then return
        res = nums[0] + nums[1] + nums[2];
        if (res >= target) return res;
        
        for (int i = 0; i < n - 2; i++) {

            if (i > 0 && nums[i] == nums[i - 1]) continue;
            //two pointers
            int j = i + 1, k = n - 1;
            
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(Math.abs(sum - target) < Math.abs(res - target))
                    res = sum;
                
                if (sum > target) {
                    k--;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if (sum < target) {
                    j++;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                }
                else
                    return sum;
            }
        }
        return res;
    }

    
    public static void main(String[] args) {
        int[] nums = {0, 2, 1, -3};
        int target = 1;
        Solution sol = new Solution();
        int res = sol.threeSumClosest(nums, target);
        System.out.println(res);
    }
}
