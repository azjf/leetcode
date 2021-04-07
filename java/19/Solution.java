class Solution {
	public ListNode removeNthFromEnd(ListNode head, int n) {
		if (n <= 0) return head;

		ListNode dummyHead = new ListNode(0, head);
		ListNode l = dummyHead, r = head;

		int i = 0;
		for (; i < n && r != null; i++) r = r.next;
		if (i < n) return head; // i == size

		while (r != null) {
			r = r.next;
			l = l.next;
		}
		l.next = l.next.next;
		return dummyHead.next;
	}
}
