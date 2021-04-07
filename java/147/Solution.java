class Solution {
	public ListNode insertionSortList(ListNode head) {
		ListNode dummy = new ListNode(0);
		ListNode cur = head;
		while (cur != null) {
			ListNode next = cur.next;
			ListNode n = dummy;
			while (n.next != null && n.next.val < cur.val) n = n.next;
			cur.next = n.next;
			n.next = cur;
			cur = next;
		}
		return dummy.next;
	}
}
