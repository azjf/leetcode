import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<Integer> ans;

	public List<Integer> inorderTraversal(TreeNode root) {
		ans = new LinkedList<Integer>();
		recur(root);
		return ans;
	}

	private void recur(TreeNode node) {
		if (node == null) return;
		recur(node.left);
		ans.add(node.val);
		recur(node.right);
	}
}
