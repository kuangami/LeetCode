import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

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

public class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Arrays.sort(nums);  //sort the input array
        int n = nums.length;
        
        for (int i = 0; i < n - 3; i++) {
            //minimum sum larger than target
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            //maximum sum smaller than target
            if (nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3] < target)
                continue;
            //skip duplicate number
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            
            //modify 3Sum function
            int threeSum = target - nums[i];
            for (int j = i + 1; j < n - 2; j++) {
                //similar to the above
                if (nums[j] + nums[j + 1] + nums[j + 2] > threeSum)
                    break;
                if (nums[j] + nums[n - 1] + nums[n - 2] < threeSum)
                    continue;
                if (j > i + 1 && nums[j] == nums[j - 1]) 
                    continue;
                
                int left = j + 1, right = n - 1; // two points
                int twoSum = threeSum - nums[j];
                while (left < right) {
                    if (nums[left] + nums[right] < twoSum)
                        left++;
                    else if (nums[left] + nums[right] > twoSum)
                        right--;
                    else {
                        res.add(Arrays.asList(nums[i], nums[j], nums[left], nums[right]));
                        left++;
                        right--;
                        while (left < right && nums[left] == nums[left - 1]) left++;
                        while (left < right && nums[right] == nums[right + 1]) right--;
                    } 
                }
            }
        }
        return res;
    }

    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {0, 0, 0, 0};
        int target = 0;
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        res = sol.fourSum(nums, target);
        for (int i = 0; i < res.size(); i++)
            System.out.println(res.get(i));
    }
}
