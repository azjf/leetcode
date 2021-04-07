class Solution {
	public ListNode swapPairs(ListNode head) {
		ListNode dummy = new ListNode(0, head);
		ListNode pre = dummy, cur = head, next;
		while (cur != null && cur.next != null) {
			next = cur.next;
			cur.next = next.next;
			next.next = cur;
			pre.next = next;
			pre = cur;
			cur = cur.next;
		}
		return dummy.next;
	}
}
