import java.util.Stack;

class Solution2 {
	public TreeNode invertTree(TreeNode root) {
		if (root == null) return null;

		Stack<TreeNode> stack= new Stack<>();
		stack.push(root);
		while (!stack.isEmpty()) {
			TreeNode node = stack.pop(), l = node.left, r = node.right;
			if (l != null) stack.push(l);
			if (r != null) stack.push(r);
			node.left = r;
			node.right = l;
		}
		return root;
	}
}
