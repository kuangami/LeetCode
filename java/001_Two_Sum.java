import java.util.HashMap;
import java.util.Map;

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

 * @author Xinyue Zhang
 *
 */

public class Solution {
//    public int[] twoSum(int[] nums, int target) {
//        int[] res = new int[2];
//
//        for (int i = 0; i < nums.length; i++) {
//            for (int j = i + 1; j < nums.length; j++)
//                if (nums[i] + nums[j] == target) {
//                    res[0] = i;
//                    res[1] = j;
//                }   
//        }
//        return res;
//    }
    
    public int[] twoSum(int[] nums, int target) {
        int[] res = new int[2];
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(target - nums[i])) {
                res[1] = i;
                res[0] = map.get(target - nums[i]);
            }
            else map.put(nums[i], i);
        }
        return res;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {0,3,2,4,0};
        int target = 0;
        int[] res = sol.twoSum(nums, target);
        System.out.println(res[0]);
        System.out.println(res[1]);
    }
}
