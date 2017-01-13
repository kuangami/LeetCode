import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

//15. 3Sum
/**
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * Note: The solution set must not contain duplicate triplets.
 * 
 * For example, given array S = [-1, 0, 1, 2, -1, -4],
 * A solution set is:
 * [
 *      [-1, 0, 1],
 *      [-1, -1, 2]
 * ]
 * 
 * Tags: Array, Two Pointers
 * 
 * Similar Problems:  (E) Two Sum (M) 3Sum Closest (M) 4Sum (M) 3Sum Smaller
 * 
 * @author Xinyue Zhang
 *
 */

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        
        Arrays.sort(nums);
        int n = nums.length;
        
        for (int i = 0; i < n - 2; i++) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1, k = n - 1;
            
            while (j < k) {
                if(nums[i] + nums[j] + nums[k] == 0) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
                else if (nums[j] + nums[k] > -nums[i])
                    k--;
                else if (nums[j] + nums[k] < -nums[i])
                    j++;
            }
        }
        
        return res;
    }

    
    public static void main(String[] args) {
        int[] nums = {-2, 0, 1, 1, 2};
        Solution sol = new Solution();
        List<List<Integer>> res = sol.threeSum(nums);
        for (int i = 0; i < res.size(); i++)
        System.out.println(res.get(i));
    }
}
