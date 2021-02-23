class Solution {
	public int maxDepth(TreeNode root) {
		return recur(root);
	}

	private int recur(TreeNode node) {
		if (node == null) {
			return 0;
		} else {
			return 1 + Math.max(recur(node.left), recur(node.right));
		}
	}
}
