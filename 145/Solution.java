import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

class Solution {
	public List<Integer> postorderTraversal(TreeNode root) {
		List<Integer> ans = new LinkedList<>();
		Stack<TreeNode> stack = new Stack<>();
		TreeNode cur = root, pre = null;
		while (cur != null || !stack.isEmpty()) {
			while (cur != null) {
				stack.push(cur);
				cur = cur.left;
			}
			cur = stack.peek();
			if (cur.right == null || cur.right == pre) {
				// cur will be processed only when there is no need to process cur.right (cur.right == null, or cur.right has been processed)
				ans.add(cur.val);
				stack.pop();
				pre = cur;  // parent node will be processed after cur (right node)
				cur = null;
			} else {
				cur = cur.right;
			}
		}
		return ans;
	}
}
