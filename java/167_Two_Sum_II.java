//167. Two Sum II - Input array is sorted
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
 * Author: Xinyue Zhang
 */
public class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] res = new int[2];
        int n = numbers.length;
        if (n < 2) return res;
        //two pointers
        int i = 0, j = n - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target) {
                res[0] = i + 1;
                res[1] = j + 1;
                break;
            }
            else if (numbers[i] + numbers[j] < target)
                i++;
            else
                j--;
        }
        return res;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums = {0,2,3,4};
        int target = 5;
        int[] res = sol.twoSum(nums, target);
        System.out.println(res[0]);
        System.out.println(res[1]);
    }
}
