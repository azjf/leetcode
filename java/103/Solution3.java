import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

class Solution {
	ArrayList<List<Integer>> ans;

	public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
		ans = new ArrayList<>();
		recur(root, 0);
		return (List<List<Integer>>) ans;
	}

	private void recur(TreeNode cur, int level) {
		if (cur == null) return;
		if (level >= ans.size()) ans.add(new LinkedList<Integer>());
		if (level % 2 == 0) {
			ans.get(level).add(cur.val);
		} else {
			ans.get(level).add(0, cur.val);
		}
		recur(cur.left, level + 1);
		recur(cur.right, level + 1);
	}
}
