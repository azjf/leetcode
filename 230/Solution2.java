class Solution {
	private int cnt;
	private int ans;

	public int kthSmallest(TreeNode root, int k) {
		recur(root, k);
		return ans;
	}

	private void recur(TreeNode cur, int k) {
		if (cur == null) return;
		recur(cur.left, k);
		if (++cnt == k) {
			ans = cur.val;
			return;
		}
		recur(cur.right, k);
	}
}
