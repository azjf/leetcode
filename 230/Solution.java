import java.util.Stack;

class Solution {
	public int kthSmallest(TreeNode root, int k) {
		int cnt = 0, ans = 0;
		Stack<TreeNode> stack = new Stack<>();
		TreeNode cur = root;
		while (cur != null || !stack.isEmpty()) {
			while (cur != null) {
				stack.push(cur);
				cur = cur.left;
			}
			cur = stack.pop();
			if (++cnt == k) {
				ans = cur.val;
				break;
			}
			cur = cur.right;
		}
		return ans;
	}
}
