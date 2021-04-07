import java.util.ArrayList;
import java.util.List;

class Solution {
	ArrayList<List<Integer>> ans;

	public List<List<Integer>> levelOrder(TreeNode root) {
		ans = new ArrayList<>();
		recur(root, 0);
		return ans;
	}

	private void recur(TreeNode cur, int level) {
		if (cur == null) return;
		if (level >= ans.size()) ans.add(new ArrayList<Integer>());
		ans.get(level).add(cur.val);
		recur(cur.left, level + 1);
		recur(cur.right, level + 1);
	}
}
