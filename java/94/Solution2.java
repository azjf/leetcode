import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

class Solution {
	public List<Integer> inorderTraversal(TreeNode root) {
		TreeNode cur = root;
		Stack<TreeNode> stack = new Stack<>();
		LinkedList<Integer> list = new LinkedList<>();
		while (cur != null || !stack.isEmpty()) {
			while (cur != null) {
				stack.push(cur);
				cur = cur.left;
			}
			cur = stack.pop();
			list.add(cur.val);
			cur = cur.right;
		}
		return list;
	}
}
