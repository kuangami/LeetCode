# LeetCode

  \#  |         Title         | Difficulty |       Tags       |      Notes
 --- | --------------------- | ---------- | --------------- | ---------------
1 | Two Sum | Easy | Hash Table | build hash table while searching
2 | Add Two Numbers | Medium | Linked List, Math | save a dummy head for output
7 | Reverse Integer | Easy | Math | test overflow
8 | String to Integer (atoi) | Easy | String | remove leading white spaces, test overflow
15 | 3Sum | Medium | Two Pointers | sort first, convert into two sum problem then approach from both sides
16 | 3Sum Closest | Medium | Two Pointers | calculate the absolute value
18 | 4Sum | Medium | Two Pointers | 4Sum -> 3Sum -> 2Sum
30 | Substring with Concatenation of All Words | Hard | Hash Table, String | build one hash table with the goal, update the other while searching
43 | Multiply Strings | Medium | String, Math | use an array of integers to store results from multiplying single digit serparately
65 | Valid Number | Hard | String, Math | use two flags for '.' and 'e', check the number before and after 'e' for output
66 | Plus One | Easy | Math | push back a '0' instead of add a '1' at the front to save time
67 | Add Binary | Easy | String, Math | add if either of a, b or carry is not empty
76 | Minimum Window Substring | Hard | Hash Table, Two Pointers, String | build hash table, move right pointer to match, move left pointer to find minimum
155 | Min Stack | Easy | Stack, Design | use two stacks to implement, keep the current minimum on the top
167 | Two Sum II - Input array is sorted | Medium | Two Pointers | approach from both sides
239 | Sliding Window Maximum | Hard | Queue | use a double-ended queue (deque) to store the potential maximum
306 | Additive Number | Medium | String, Math | handle leading zero cases and recursively test if it is additive
371 | Sum of Two Integers | Easy | [Bit Manipulation](https://discuss.leetcode.com/topic/50315/a-summary-how-to-use-bit-manipulation-to-solve-problems-easily-and-efficiently) | use XOR to handle '0 + 0', '0 + 1', '1 + 0', use AND then left shift to handle '1 + 1'
415 | Add Strings | Easy | 
454 | 4Sum II | Medium | Hash Table | use hash table for search purpose
