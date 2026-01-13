/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy = new ListNode(0);
        ListNode temp = dummy;
        for(ListNode head:lists){
            while(head != null){
                temp.next = new ListNode(head.val);
                temp = temp.next;
                head = head.next;
            }
        }
        dummy.next = sortList(dummy.next);
        return dummy.next;
    }
    public static ListNode sortList(ListNode head){
        ListNode temp = head;
        ArrayList<Integer> list = new ArrayList<>();
        while(temp != null){
            list.add(temp.val);
            temp = temp.next;
        }
        Collections.sort(list);
        temp = head;
        for(int i=0; i<list.size(); i++){
            temp.val = list.get(i);
            temp = temp.next;
        }

        return head;
    }
}