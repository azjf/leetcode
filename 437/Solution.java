class Solution {
	private int sum;

	public int pathSum(TreeNode root, int sum) {
		this.sum = sum;
		return recur(root, sum);
	}

	private int recur(TreeNode node, int sum) {
		if (node == null) {
			return 0;
		}
		return recur(node.left, this.sum) + recur(node.right, this.sum) + helper(node, sum);
	}

	private int helper(TreeNode node, int sum) {
		if (node == null) {
			return 0;
		}
		return (node.val == sum ? 1 : 0) + helper(node.left, sum - node.val) + helper(node.right, sum - node.val);
	}
}
