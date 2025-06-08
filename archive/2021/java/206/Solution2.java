class Solution2 {
	public ListNode reverseList(ListNode head) {
		if (head == null) {
			return null;
		}
		return recur(head);
	}

	private ListNode recur(ListNode node) {
		if (node.next == null) {
			return node;
		} else {
			ListNode res = recur(node.next);
			node.next.next = res; // new tail == node.next
			node.next = null;
			return res;
		}
	}
}
