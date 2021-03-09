import java.util.LinkedList;
import java.util.List;

class Solution {
	public List<TreeNode> generateTrees(int n) {
		return recur(1, n);
	}

	private List<TreeNode> recur(int start, int end) {
		LinkedList<TreeNode> list = new LinkedList<>();
		if (start > end) {
			list.add(null);
			return list;
		}
		for (int i = start; i <= end; i++) {
			List<TreeNode> lList = recur(start, i - 1);
			List<TreeNode> rList = recur(i + 1, end);
			for (TreeNode l : lList) {
				for (TreeNode r : rList) {
					list.add(new TreeNode(i, l, r));
				}
			}
		}
		return list;
	}
}
