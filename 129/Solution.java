class Solution {
	public int sumNumbers(TreeNode root) {
		return recur(root, 0);
	}

	private int recur(TreeNode cur, int sum) {
		if (cur == null) return 0;
		sum = sum * 10 + cur.val;
		if (cur.left == null && cur.right == null) {
			return sum;
		}
		return recur(cur.left, sum) + recur(cur.right, sum);
	}
}
