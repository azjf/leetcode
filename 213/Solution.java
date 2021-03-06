class Solution {
	public int rob(int[] nums) {
		if (nums.length == 1) return nums[0];

		return Math.max(rob(nums, 0, nums.length - 2), rob(nums, 1, nums.length - 1));
	}

	public int rob(int[] nums, int l, int r) {
		int pre = 0, ppre = 0;
		for (int i = l; i <= r; i++) {
			int cur = Math.max(pre, nums[i] + ppre);
			ppre = pre;
			pre = cur;
		}
		return pre;
	}
}
