class Solution {
	public ListNode reverseBetween(ListNode head, int left, int right) {
		ListNode dummy = new ListNode(0, head);
		ListNode cur = dummy, tail1;
		int m = 0;
		for (; m < left - 1; cur = cur.next) m++;
		tail1 = cur;
		cur = cur.next;

		ListNode head2 = null, tail2 = cur;
		for (int n = left; n <= right; n++) {
			ListNode next = cur.next;
			cur.next = head2;
			head2 = cur;
			cur = next;
		}
		tail2.next = cur;
		tail1.next = head2;
		return dummy.next;
	}
}
