class Solution {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		ListNode dummyHead = new ListNode(), cur = dummyHead;
		int carry = 0;
		while (l1 != null || l2 != null) {
			int sum = carry;
			if (l1 != null) {
				sum += l1.val;
				l1 = l1.next;
			}
			if (l2 != null) {
				sum += l2.val;
				l2 = l2.next;
			}
			cur.next = new ListNode(sum % 10);
			carry = sum / 10;
			cur = cur.next;
		}

		if (carry == 1) {
			cur.next = new ListNode(1);
		}

		return dummyHead.next;
	}
}
