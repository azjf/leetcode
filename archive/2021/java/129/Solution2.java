import java.util.Stack;

class Solution {
	public int sumNumbers(TreeNode root) {
		int ans = 0;

		Stack<TreeNode> nodes = new Stack<>();
		Stack<Integer> sums = new Stack<>();
		TreeNode cur = root;
		int parentSum = 0;
		while (cur != null || !nodes.isEmpty()) {
			while (cur != null) {
				nodes.push(cur);
				int sum = parentSum * 10 + cur.val;
				sums.push(sum);
				cur= cur.left;
				parentSum = sum;
			}
			cur = nodes.pop();
			int sum = sums.pop();
			if (cur.left == null && cur.right == null) ans += sum;
			cur = cur.right;
			parentSum = sum;
		}

		return ans;
	}
}
