import java.util.List;
import java.util.LinkedList;

class Solution {
	public List<Integer> rightSideView(TreeNode root) {
		List<Integer> ans = new LinkedList<>();
		if (root == null) return ans;

		LinkedList<TreeNode> queue = new LinkedList<>();
		queue.offer(root);
		while (!queue.isEmpty()) {
			int sz = queue.size();
			for (int i = 0; i < sz; i++) {
				TreeNode node = queue.poll();
				if (node.left != null) queue.offer(node.left);
				if (node.right != null) queue.offer(node.right);
				if (i == sz - 1) ans.add(node.val);
			}
		}
		return ans;
	}
}
