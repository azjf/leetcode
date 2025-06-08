import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<Integer> ans;

	public List<Integer> postorderTraversal(TreeNode root) {
		ans = new LinkedList<>();
		dfs(root);
		return ans;
	}

	private void dfs(TreeNode cur) {
		if (cur == null) return;
		dfs(cur.left);
		dfs(cur.right);
		ans.add(cur.val);
	}
}
