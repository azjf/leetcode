import java.util.Stack;

class Solution {
	public boolean isValidBST(TreeNode root) {
		Stack<TreeNode> stack = new Stack<TreeNode>();
		// pre is a parent node or right node
		// cur is a right node
		// pre is just one node before cur in the inorder
		TreeNode cur = root, pre = null;
		while (cur != null || !stack.isEmpty()) {
			while (cur != null) {
				stack.push(cur);
				cur = cur.left;
			}
			cur = stack.pop();
			if (pre != null && cur.val <= pre.val) return false;
			pre = cur;
			cur = cur.right;
		}
		return true;
	}
}
