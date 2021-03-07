class Solution {
	public int findTargetSumWays(int[] nums, int S) {
		return recur(nums, 0, S);
	}

	private int recur(int[] nums, int lo, int target) {
		if (lo == nums.length) return target == 0 ? 1 : 0;
		return recur(nums, lo + 1, target - nums[lo])  // target - (+nums[lo])
			+ recur(nums, lo + 1, target + nums[lo]);  // target - (-nums[lo])
	}
}
