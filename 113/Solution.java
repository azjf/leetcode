import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<List<Integer>> ans;

	public List<List<Integer>> pathSum(TreeNode root, int targetSum) {
		ans = new LinkedList<>();
		recur(root, targetSum, new LinkedList<>());
		return ans;
	}

	private void recur(TreeNode cur, int targetSum, LinkedList<Integer> list) {
		if (cur == null) return;
		list.add(cur.val);
		if (cur.val == targetSum && cur.left == null && cur.right == null) {
			ans.add(new LinkedList<Integer>(list));
		} else {
			recur(cur.left, targetSum - cur.val, list);
			recur(cur.right, targetSum - cur.val, list);
		}
		list.removeLast();
	}
}
