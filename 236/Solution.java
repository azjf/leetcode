class Solution {
	public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
		return recur(root, p, q);
	}

	private TreeNode recur(TreeNode cur, TreeNode p, TreeNode q) {
		if (cur == null || cur.val == p.val || cur.val == q.val) return cur;  // return when arrive at null or find p or q
		TreeNode left = recur(cur.left, p, q);
		TreeNode right = recur(cur.right, p, q);
		if (left == null) {  // find no one at left
			return right;
		} else if (right == null) {  // find no one at right
			return left;
		} else {  // find one at both sides
			return cur;
		}
	}
}
