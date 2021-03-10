import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
	public List<List<Integer>> levelOrder(TreeNode root) {
		LinkedList<List<Integer>> ans = new LinkedList<>();
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		if (root != null) {
			queue.offer(root);
			queue.offer(null);
		}
		while (!queue.isEmpty()) {
			LinkedList<Integer> list = new LinkedList<>();
			TreeNode cur = queue.poll();
			while (cur != null) {
				if (cur.left != null) queue.offer(cur.left);
				if (cur.right != null) queue.offer(cur.right);
				list.add(cur.val);
				cur = queue.poll();
			}
			if (queue.size() > 0) queue.offer(null);
			ans.add(list);
		}
		return ans;
	}
}
