import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<Integer> ans;

	public List<Integer> preorderTraversal(TreeNode root) {
		ans = new LinkedList<>();
		recur(root);
		return ans;
	}

	private void recur(TreeNode cur) {
		if (cur == null) return;
		ans.add(cur.val);
		recur(cur.left);
		recur(cur.right);
	}
}
