import java.util.LinkedList;
import java.util.Queue;

class Solution2 {
	public int maxDepth(TreeNode root) {
		if (root == null) {
			return 0;
		}

		Queue<TreeNode> q = new LinkedList<>();
		q.offer(root);

		int depth = 0;
		while (!q.isEmpty()) {
			int size = q.size();
			while (size-- > 0) {
				TreeNode node = q.poll();
				if (node.left != null) {
					q.offer(node.left);
				}
				if (node.right != null) {
					q.offer(node.right);
				}
			}
			depth++;
		}
		return depth;
	}
}
