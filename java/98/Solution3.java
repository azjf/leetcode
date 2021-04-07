class Solution {
	public boolean isValidBST(TreeNode root) {
		return recur(root, null, null);
	}

	private boolean recur(TreeNode cur, Integer loVal, Integer hiVal) {
		if (cur == null) return true;
		if (loVal != null && cur.val <= loVal) return false;
		if (hiVal != null && cur.val >= hiVal) return false;
		return recur(cur.left, loVal, cur.val)
			&& recur(cur.right, cur.val, hiVal);
	}
}
