class Solution {
	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		return recur(root, p, q);
	}

	private TreeNode recur(TreeNode cur, TreeNode p, TreeNode q) {
		if (cur == null) return null;
		if (cur.val == p.val || cur.val == q.val) return cur;
		boolean pFind = find(cur.left, p);
		boolean qFind = find(cur.left, q);
		if (pFind && qFind) {
			return recur(cur.left, p, q);
		} else if (!pFind && !qFind) {
			return recur(cur.right, p, q);
		} else {
			return cur;
		}
	}

	private boolean find(TreeNode cur, TreeNode node) {
		if (cur == null) return false;
		if (cur.val == node.val) return true;
		return find(cur.left, node) || find(cur.right, node);
	}
}
