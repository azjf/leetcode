class Solution {
	public ListNode removeElements(ListNode head, int val) {
		ListNode pre = new ListNode(0, head);
		ListNode cur = pre;
		while (cur.next != null) {
			if (cur.next.val == val) {
				cur.next = cur.next.next;
			} else {
				cur = cur.next;
			}
		}
		return pre.next;
	}
}
