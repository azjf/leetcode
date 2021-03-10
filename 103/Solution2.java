import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		LinkedList<List<Integer>> ans = new LinkedList<>();
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		boolean isForward = true;
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
				if (isForward) {
					list.add(cur.val);
				} else {
					list.addFirst(cur.val);
				}
				cur = queue.poll();
			}
			if (queue.size() > 0) queue.offer(null);
			ans.add(list);
			isForward = !isForward;
		}
		return ans;
	}
}
