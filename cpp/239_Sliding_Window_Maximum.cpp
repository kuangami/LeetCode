// 239. Sliding Window Maximum
/**
 * Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
 * 
 * For example,
 * Given nums = [1,3,-1,-3,5,3,6,7], and k = 3.
 * 
 * Window position                Max
 * ---------------               -----
 * [1  3  -1] -3  5  3  6  7       3
 *  1 [3  -1  -3] 5  3  6  7       3
 *  1  3 [-1  -3  5] 3  6  7       5
 *  1  3  -1 [-3  5  3] 6  7       5
 *  1  3  -1  -3 [5  3  6] 7       6
 *  1  3  -1  -3  5 [3  6  7]      7
 * Therefore, return the max sliding window as [3,3,5,5,6,7].
 * 
 * Note: 
 * You may assume k is always valid, ie: 1 ¡Ü k ¡Ü input array's size for non-empty array.
 * 
 * Follow up:
 * Could you solve it in linear time?
 * 
 * Hint:
 * 1. How about using a data structure such as deque (double-ended queue)?
 * 2. The queue size need not be the same as the window¡¯s size.
 * 3. Remove redundant elements and the queue should store only elements that need to be considered.
 * 
 * Tags: Heap
 * 
 * Similar Problems: (H) Minimum Window Substring (E) Min Stack (H) Longest Substring with At Most Two Distinct Characters (H) Paint House II
 * 
 * Author: Kuang Qin
 */

#include <iostream>
#include <vector>
#include <deque>
 
using namespace std;
 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> output;
        deque<int> dq;      // a double-ended queue that stores the index of potential maximum elements
        for (int i = 0; i < n; i++)
        {
            if (!dq.empty() && dq.front() == i - k)
                dq.pop_front();     // remove element out of range k
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();      // remove element that has no chance to be the maximum
            
            dq.push_back(i);        // push index
            if (i >= k - 1)
                output.push_back(nums[dq.front()]);  // the front element in the deque is the current maximum in the window
        }
        
        return output;
    }
};

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution sol;
    vector<int> output = sol.maxSlidingWindow(nums, k);
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << " ";
    }
    cout << endl;
    cin.get();
    
    return 0;
}