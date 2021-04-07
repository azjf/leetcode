class Solution {
	public ListNode partition(ListNode head, int x) {
		ListNode dummy1 = new ListNode(), dummy2 = new ListNode();
		ListNode head1 = dummy1, head2 = dummy2;
		for (; head != null; head = head.next) {
			if (head.val < x) {
				head1.next = head;
				head1 = head1.next;
			} else {
				head2.next = head;
				head2 = head2.next;
			}
		}
		head2.next = null;
		head1.next = dummy2.next;
		return dummy1.next;
	}
}
