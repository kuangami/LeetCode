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
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// merge sort, time: O(m + n), space: O(m + n)
class Solution_Merge_Sort {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 + n2 == 0) {
            return 0;
        }
        
        vector<int> nums;   // merge two arrays into one
        int i = 0, j = 0, k = 0;
        while (i < n1 && j < n2) {
            if (nums1[i] <= nums2[j]) {
                nums.push_back(nums1[i++]);
            }
            else {
                nums.push_back(nums2[j++]);
            }
        }
        
        // push back the remaining elements
        while (i < n1) {
            nums.push_back(nums1[i++]);
        }
        
        while (j < n2) {
            nums.push_back(nums2[j++]);
        }
        
        int n = n1 + n2;
        double median = 0.5 * (nums[(n - 1) / 2] + nums[n / 2]);
        
        return median;
    }
};

// divide and conquer, time: O(log(m + n)), space: O(1)
// recursive binary search
class Solution_Div_and_Conq {
public:
    // find the kth element, index starting from 1
    int findkthElement(vector<int>& nums1, int size1, int begin1, vector<int>& nums2, int size2, int begin2, int k) {
        if (size1 > size2) {    // let nums1 be shorter
            return findkthElement(nums2, size2, begin2, nums1, size1, begin1, k);
        }
        
        if (size1 == 0) {   // if nums1 is empty, return the kth element of nums2
            return nums2[begin2 + k - 1];
        }
        
        if (k == 1) {   // return the smaller of the first element
            return min(nums1[begin1], nums2[begin2]);
        }
        
        // cut each array at k/2 position
        int cut1 = min(k/2, size1), cut2 = k - cut1;
        if (nums1[begin1 + cut1 - 1] == nums2[begin2 + cut2 - 1]) { // return if equal
            return nums1[begin1 + cut1 - 1];
        }
        
        // binary search, move to the direction that tends to have equal value at k/2 posotion
        // if nums1 value is larger, move to the right side of cut2 to make k/2 element of nums2 larger
        if (nums1[begin1 + cut1 - 1] > nums2[begin2 + cut2 - 1]) {
            // set the begin point at nums2 from cut2, finding (k - cut2)th element
            return findkthElement(nums1, size1, begin1, nums2, size2 - cut2, begin2 + cut2, k - cut2);
        }
        
        // nums1[begin1 + cut1 - 1] < nums2[begin2 + cut2 - 1]
        // if nums1 value is smaller, move to the right side of cut1 to make k/2 element of nums1 larger
        // set the begin point at nums1 from cut1, finding (k - cut1)th element
        return findkthElement(nums1, size1 - cut1, begin1 + cut1, nums2, size2, begin2, k - cut1);
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 + n2 == 0) {
            return 0;
        }
        
        double median;
        if ((n1 + n2) % 2) {    // odd number
            median = findkthElement(nums1, n1, 0, nums2, n2, 0, (n1 + n2 + 1) / 2);
        }
        else {  // even number
            median = 0.5 * (findkthElement(nums1, n1, 0, nums2, n2, 0, (n1 + n2) / 2)
                + findkthElement(nums1, n1, 0, nums2, n2, 0, (n1 + n2) / 2 + 1));
        }
        
        return median;
    }
};

// non-recursive binary search, time: O(log(min(m, n))), space: O(1)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        if (n1 + n2 == 0) {
            return 0;
        }
        
        if (n1 > n2) {  // let nums1 be shorter
            return findMedianSortedArrays(nums2, nums1);
        }
        
        if (n1 == 0) {  // find the median of nums2 if nums1 is empty
            return 0.5 * (nums2[(n2 - 1) / 2] + nums2[n2 / 2]);
        }
        
        // odd number: cut at the middle element
        // even number: cut at the left one of two middle elements
        int cut = (n1 + n2 - 1) / 2;
        
        int begin = 0, end = n1;
        while (begin < end) {
            int cut1 = (begin + end) / 2, cut2 = cut - cut1;
            
            // compare values at the cut position of each array
            if (nums1[cut1] < nums2[cut2]) {
                // move to the right side of nums1
                begin = cut1 + 1;
            }
            else if (nums1[cut1] > nums2[cut2]) {
                // move to the left side of nums1
                end = cut1;
            }
            else {  // nums1[cut1] == nums2[cut2]
                return nums1[cut1];
            }
        }
        
        // after binary search
        // odd number: the correspoding middle element in each array
        // even numnber: the left one of two middle elements in each array
        // put INT_MIN for comparison if the index is at the left boudary
        int mid1_left = (begin == 0) ? INT_MIN : nums1[begin - 1];          // index: begin - 1
        int mid2_left = (cut - begin < 0) ? INT_MIN : nums2[cut - begin];   // index: cut - begin
        
        double median;
        if ((n1 + n2) % 2)    // odd number
        {
            median = max(mid1_left, mid2_left);
        }
        else    // even number
        {
            // the corresponding right one of two middle elements in each array
            // put INT_MAX for comparison if the index is at the right boundary
            int mid1_right = (begin == n1) ? INT_MAX : nums1[begin];                      // index: begin
            int mid2_right = (cut - begin + 1 == n2) ? INT_MAX : nums2[cut - begin + 1];  // index: cut - begin + 1
            median = 0.5 * (max(mid1_left, mid2_left) + min(mid1_right, mid2_right));
        }

        return median;
    }
};

int main() {
    vector<int> nums1 = {1, 2}, nums2 = {3, 4};
    Solution sol;
    double median = sol.findMedianSortedArrays(nums1, nums2);
    cout << median << endl;
    cin.get();
    
    return 0;
}