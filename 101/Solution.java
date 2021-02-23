class Solution {
	public boolean isSymmetric(TreeNode root) {
		if (root == null) {
			return true;
		} else {
			return recur(root.left, root.right);
		}
	}

	private boolean recur(TreeNode l, TreeNode r) {
		if (l == null && r == null) {
			return true;
		}
		if (l == null || r == null || l.val != r.val) {
			return false;
		}
		return recur(l.left, r.right) && recur(l.right, r.left);
	}
}
