import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
	public List<List<Integer>> levelOrder(TreeNode root) {
		LinkedList<List<Integer>> ans = new LinkedList<>();
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		if (root != null) queue.offer(root);
		while (!queue.isEmpty()) {
			int sz = queue.size();
			LinkedList<Integer> list = new LinkedList<>();
			for (int i = 0; i < sz; i++) {
				TreeNode cur = queue.poll();
				if (cur.left != null) queue.offer(cur.left);
				if (cur.right != null) queue.offer(cur.right);
				list.add(cur.val);
			}
			ans.add(list);
		}
		return ans;
	}
}
