import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

class Solution {
	public List<Integer> preorderTraversal(TreeNode root) {
		List<Integer> ans = new LinkedList<>();
		Stack<TreeNode> nodes = new Stack<>();
		TreeNode cur = root;
		while (cur != null || !nodes.isEmpty()) {
			while (cur != null) {
				nodes.push(cur);
				ans.add(cur.val);
				cur = cur.left;
			}
			cur = nodes.pop();
			cur = cur.right;
		}
		return ans;
	}
}
