class Solution {
	public ListNode reverseList(ListNode head) {
		ListNode res = null, cur = head;
		while (cur != null) {
			ListNode next = cur.next;
			cur.next = res;
			res = cur;
			cur = next;
		}
		return res;
	}
}
