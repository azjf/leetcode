import java.util.LinkedList;
import java.util.Queue;

class Solution {
	public int sumNumbers(TreeNode root) {
		int ans = 0;

		Queue<TreeNode> nodes = new LinkedList<>();
		Queue<Integer> sums = new LinkedList<>();
		if (root != null) {
			nodes.offer(root);
			sums.offer(root.val);
		}
		while (!nodes.isEmpty()) {
			int sz = nodes.size();
			for (int i = 0; i < sz; i++) {
				TreeNode cur = nodes.poll();
				int sum = sums.poll();
				if (cur.left == null && cur.right == null) ans += sum;
				if (cur.left != null) {
					nodes.offer(cur.left);
					sums.offer(sum * 10 + cur.left.val);
				}
				if (cur.right != null) {
					nodes.offer(cur.right);
					sums.offer(sum * 10 + cur.right.val);
				}
			}
		}

		return ans;
	}
}
