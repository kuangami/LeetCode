// 4. Median of Two Sorted Arrays
/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * 
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 *
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * Tags: Binary Search, Array, Divide and Conquer
 * 
 * Author: Xinyue Zhang
 */

public class Solution {
    /** merge sort, time: O(m + n), space: O(m + n)
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        if (n1 + n2 == 0) {
            return 0;
        }
        //combine the two arrays
        int[] nums = new int[n1 + n2];
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
               nums[k++] = nums1[i++];
            }
            else {
                nums[k++] = nums2[j++];
            }
        }
        //add the remaining elements
        while (i < n1) {
            nums[k++] = nums1[i++];
        }
        
        while (j < n2) {
            nums[k++] = nums2[j++];
        }
        
        int n = n1 + n2;
        double median = (nums[(n - 1) / 2] + nums[n / 2]) * 0.5;
        return median;
    }**/
    
    
    /**
    // divide and conquer, time: O(log(m + n)), space: O(1)
    //  recursive binary search
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        if (n1 + n2 == 0) {
            return 0;
        }
        double median = 0;
        if ((n1 + n2) % 2 == 1) //odd
            median = findkthElement(nums1, n1, 0, nums2, n2, 0, (n1 + n2 + 1) / 2);
        else //even
            median = 0.5 * (findkthElement(nums1, n1, 0, nums2, n2, 0, (n1 + n2) / 2) 
                    + findkthElement(nums1, n1, 0, nums2, n2, 0, (n1 + n2) / 2 + 1));
        
        return median;

    }
    
    public int findkthElement(int[] nums1, int size1, int begin1,
            int[] nums2, int size2, int begin2, int k) {
        
        if (size1 > size2) //make nums1 be shorter
            return findkthElement(nums2, size2, begin2, nums1, size1, begin1, k);
        
        if (size1 == 0) // if nums1 is empty, return the kth element of nums2
            return nums2[begin2 + k - 1];
        
        if (k == 1) // return the smaller of the first element
            return Math.min(nums1[begin1], nums2[begin2]);
        
        //In statistics, the median is used for dividing a set into two equal length subsets, 
        //that one subset is always greater than the other.
        int cut1 = Math.min(k / 2, size1), cut2 = k - cut1;
        if (nums1[begin1 + cut1 - 1] == nums2[begin2 + cut2 - 1])
            return nums1[begin1 + cut1 - 1];
        if (nums1[begin1 + cut1 - 1] > nums2[begin2 + cut2 - 1])
            return findkthElement(nums1, size1, begin1, nums2, size2 - cut2, begin2 + cut2, k - cut2);
        
        return findkthElement(nums1, size1 - cut1, begin1 + cut1, nums2, size2, begin2, k - cut1);
    }**/
    
    //In statistics, the median is used for dividing a set into two equal length subsets, 
    //that one subset is always greater than the other.
    
    // non-recursive binary search, time: O(log(min(m, n))), space: O(1)
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int n1 = nums1.length, n2 = nums2.length;
        if (n1 + n2 == 0) {
            return 0;
        }
        
        if (n1 > n2) //make nums1 be shorter
            return findMedianSortedArrays(nums2, nums1);
        
        if (n1 == 0) //nums1 is empty, return median of nums2
            return (nums2[(n2 - 1) / 2] + nums2[n2 / 2]) * 0.5;
        
        int cut = (n1 + n2 - 1) / 2, begin = 0, end = n1;
        while (begin < end) {
            int cut1 = (begin + end) / 2, cut2 = cut - cut1;
            
            if (nums1[cut1] < nums2[cut2])
                begin = cut1 + 1;
            else if (nums1[cut1] > nums2[cut2])
                end = cut1;
            else 
                return nums1[cut1];
        }
        
        int mid1_left = (begin == 0) ? Integer.MIN_VALUE : nums1[begin - 1];
        int mid2_left = (cut - begin < 0) ? Integer.MIN_VALUE : nums2[cut - begin];
        
        double median;
        if((n1 + n2) % 2 == 1) // odd
            median = Math.max(mid1_left, mid2_left);
        else {//even
            int mid1_right = (begin == n1) ? Integer.MAX_VALUE : nums1[begin];
            int mid2_right = (cut - begin + 1 == n2) ? Integer.MAX_VALUE : nums2[cut - begin + 1];
            median = 0.5 * (Math.max(mid1_left, mid2_left) + Math.min(mid1_right, mid2_right));
        }
            
        return median;
    }
    
    public static void main(String args[]) {
        int[] nums1 = {1, 2}, nums2 = {3, 4};
        Solution sol = new Solution();
        double median = sol.findMedianSortedArrays(nums1, nums2);
        System.out.println(median);  
    }
}
