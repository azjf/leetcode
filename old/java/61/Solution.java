class Solution {
	public ListNode rotateRight(ListNode head, int k) {
		if (head == null || head.next == null) return head;

		ListNode l = head, r = head; 
		int len = 0;
		for (; r != null; r = r.next) len++;

		k %= len;
		if (k == 0) return head;

		r = head;
		for (int i = 0; i < k; i++) r = r.next;
		while (r.next != null) {
			//if (k-- <= 0) r = r.next;
			r = r.next;
			l = l.next;
		}

		ListNode ans = l.next;
		l.next = null;
		r.next = head;
		return ans;
	}
}
