package ListNode;

//2. Add Two Numbers
/**
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * 
 * Tags:  Linked List, Math
 * Similar Problems:  (M) Multiply Strings (E) Add Binary (E) Sum of Two Integers (E) Add Strings (M) Add Two Numbers II
 * 
 * @author Xinyue Zhang
 *
 */

//ListNode class
/**
package ListNode;

public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
    
    public static void insertList(int val, ListNode head) {
        ListNode node = new ListNode(0);
        node.val = val;
        while (head.next != null)
            head = head.next;
        head.next = node;
    }
}**/

public class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode prev = new ListNode(0);
        ListNode head = prev;
        int carry = 0, sum = 0;
        
        while (l1 != null || l2 != null || carry != 0) {
            sum = carry + ((l1 == null) ? 0 : l1.val) + ((l2 == null) ? 0 : l2.val);
            carry = sum / 10;
            
            prev.next = new ListNode(sum % 10);
            prev = prev.next;
            
            l1 = l1 == null ? l1 : l1.next;
            l2 = l2 == null ? l2 : l2.next;
        }
        return head.next;
    }
    
    public static void main(String[] args) {
        ListNode l1 = new ListNode(2);
        ListNode.insertList(4, l1);
        ListNode.insertList(3, l1);
        
        ListNode l2 = new ListNode(5);
        ListNode.insertList(6, l2);
        ListNode.insertList(4, l2);
        
        System.out.println("Sum = ");
        ListNode sum = new ListNode(0);
        Solution sol = new Solution();
        sum = sol.addTwoNumbers(l1, l2);
        while (sum != null) {
            System.out.println(sum.val);
            sum = sum.next;
        }
    }
}
