class Solution {
	public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
		ListNode n1 = headA, n2 = headB;
		while (n1 != n2) {
			n1 = n1 == null ? headB : n1.next;
			n2 = n2 == null ? headA : n2.next;
		}
		return n1; // 若不相交，n1, n2在走完A+B后都会走到null
	}
}
