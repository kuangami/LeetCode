import java.util.HashMap;

// 454. 4Sum II
/**
 * Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.
 * 
 * To make problem a bit easier, all A, B, C, D have same length of N where 0 <= N <= 500. All integers are in the range of -2^28 to 2^28 - 1 
 * and the result is guaranteed to be at most 2^31 - 1.
 * 
 * Example:
 * 
 * Input:
 * A = [ 1, 2]
 * B = [-2,-1]
 * C = [-1, 2]
 * D = [ 0, 2]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two tuples are:
 * 1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
 * 2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
 * 
 * Tags: Binary Search, Hash Table
 * 
 * Similar Problems: (M) 4Sum
 * 
 * Author: Xinyue Zhang
 */
public class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        int n = A.length, res = 0;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        //initiate hashmap
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = -(A[i] + B[j]);
                map.put(sum, map.containsKey(sum) ? map.get(sum) + 1 : 1);
            }
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int sum = C[i] + D[j];
                if (map.containsKey(sum)) 
                    res += map.get(sum);
            }
        }
        
        return res;
    }
    
    public static void main(String[] args) {
        int[] A = {1, 2};
        int[] B = {-2, -1};
        int[] C = {-1, 2};
        int[] D = {0, 2};
        Solution sol = new Solution();
        int res = sol.fourSumCount(A, B, C, D);
        System.out.println(res);
    }
    
}
