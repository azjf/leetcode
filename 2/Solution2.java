class Solution2 {
	public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		return recur(l1, l2, 0);
	}

	private ListNode recur(ListNode l1, ListNode l2, int carry) {
		if (l1 == null && l2 == null) {
			if (carry == 1) {
				return new ListNode(1);
			}
		}
		int sum = carry;
		if (l1 != null) {
			sum += l1.val;
			l1 = l1.next;
		}
		if (l2 != null) {
			sum += l2.val;
			l2 = l2.next;
		}
		return new ListNode(sum % 10, recur(l1, l2, sum / 10));
	}

	public static void main(String[] args) {
		ListNode l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
		ListNode l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
		ListNode node = (new Solution()).addTwoNumbers(l1, l2);
		while (node != null) {
			System.out.println(node.val);
			node = node.next;
		}
	}
}
