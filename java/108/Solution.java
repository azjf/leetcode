class Solution {
	public TreeNode sortedArrayToBST(int[] nums) {
		if (nums == null) {
			return null;
		}
		return recur(nums, 0, nums.length - 1);
	}

	private TreeNode recur(int[] nums, int lo, int hi) {
		if (lo > hi) {
			return null;
		}

		int mid = (lo + hi) / 2;
		return new TreeNode(nums[mid], recur(nums, lo, mid - 1), recur(nums, mid + 1, hi));
	}
}

