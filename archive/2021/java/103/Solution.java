import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

class Solution {
	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		LinkedList<List<Integer>> ans = new LinkedList<>();
		Queue<TreeNode> queue = new LinkedList<TreeNode>();
		if (root != null) queue.offer(root);
		boolean isForward = true;
		while (!queue.isEmpty()) {
			int sz = queue.size();
			LinkedList<Integer> list = new LinkedList<>();
			for (int i = 0; i < sz; i++) {
				TreeNode cur = queue.poll();
				if (cur.left != null) queue.offer(cur.left);
				if (cur.right != null) queue.offer(cur.right);
				if (isForward) {
					list.add(cur.val);
				} else {
					list.addFirst(cur.val);
				}
			}
			ans.add(list);
			isForward = !isForward;
		}
		return ans;
	}
}
