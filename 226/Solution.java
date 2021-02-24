class Solution {
	public TreeNode invertTree(TreeNode root) {
		return recur(root);
	}

	private TreeNode recur(TreeNode node) {
		if (node == null) {
			return node;
		}
		TreeNode left = node.left;
		node.left = recur(node.right);
		node.right = recur(left);
		return node;
	}
}
