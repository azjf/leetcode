class Solution {
	private TreeNode pre;
	public boolean isValidBST(TreeNode root) {
		pre = null;
		return recur(root);
	}

	// do not use recur(TreeNode cur, TreeNode pre), which leads to an incorrect pre,
	// because the correct pre do not always follow cur
	private boolean recur(TreeNode cur) {
		// pre is a parent node or right node
		// cur is a right node
		// pre is just one node before cur in the inorder
		if (cur == null) return true;
		if (!recur(cur.left)) return false;
		if (pre != null && cur.val <= pre.val) return false;
		pre = cur;
		return recur(cur.right);
	}
}
