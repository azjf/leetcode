class Solution {
	public ListNode partition(ListNode head, int x) {
		ListNode dummy = new ListNode(0, head), l = dummy, r = dummy;
		while (r.next != null && r.next.val < x) {
			r = r.next;
			l = l.next;
		}
		if (r == null) return dummy.next;

		while (r != null && r.next != null) {
			ListNode cur = r.next;
			if (cur.val < x) {
				r.next = cur.next;
				cur.next = l.next;
				l.next = cur;
				l = l.next;
			} else {
				r = r.next;
			}
		}
		return dummy.next;
	}
}
