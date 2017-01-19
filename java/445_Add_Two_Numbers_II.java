package Solution;

import java.util.ArrayList;

//445. Add Two Numbers II
/**
 * You are given two non-empty linked lists representing two non-negative integers. 
 * The most significant digit comes first and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Follow up:
 * What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
 * 
 * Example:
 * Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 8 -> 0 -> 7
 * 
 * Tags: Linked List
 * Similar Problems: (M) Add Two Numbers
 * 
 * @author Xinyue Zhang
 *
 */

//ListNode class
//package Solution;
//
//public class ListNode {
//    int val;
//    ListNode next;
//    ListNode(int x) { val = x; }
//    ListNode(int x, ListNode node) { val = x; next = node; } 
//}

public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ArrayList<Integer> num1 = new ArrayList<Integer>();
        ArrayList<Integer> num2 = new ArrayList<Integer>();
        while (l1 != null) {
            num1.add(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            num2.add(l2.val);
            l2 = l2.next;
        }
        ListNode head = new ListNode(0);

        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        
        while (i >= 0 || j >= 0) {
            int sum = 0;
            if (i != -1) sum += num1.get(i--);
            if (j != -1) sum += num2.get(j--);
            
            head.val = (sum + carry) % 10;
            carry = (sum + carry) / 10;
            ListNode dummy = new ListNode(carry);
            dummy.next = head;
            head = dummy;
        }
        
        return head.val == 0 ? head.next : head;   
    }
    
    public static void main(String[] args) {
        ListNode l1 = new ListNode(1);
        
        ListNode l2 = new ListNode(9), l2_1 = new ListNode(9, l2);
        
        System.out.println("Sum = ");
        ListNode sum = new ListNode(0);
        Solution sol = new Solution();
        sum = sol.addTwoNumbers(l1, l2_1);
        while (sum != null) {
            System.out.println(sum.val);
            sum = sum.next;
        }
    }
}
