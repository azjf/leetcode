class Solution2 {
	public ListNode swapPairs(ListNode head) {
		return recur(head);
	}

	private ListNode recur(ListNode node) {
		if (node == null || node.next == null) {
			return node;
		}
		ListNode next = node.next;
		node.next = recur(next.next);
		next.next = node;
		return next;
	}
}
