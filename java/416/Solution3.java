class Solution {
	public boolean canPartition(int[] nums) {
		if (nums.length == 1) return false;

		int sum = 0;
		for (int num : nums) sum += num;
		if (sum % 2 != 0) return false;
		sum /= 2;

		return recur(nums, 0, sum, sum);

	}

	private boolean recur(int[] nums, int cur, int pickRemain, int discardRemain) {
		if (pickRemain == 0 || discardRemain == 0) return true;
		if (pickRemain < 0 || discardRemain < 0 || cur >= nums.length) return false;
		return recur(nums, cur + 1, pickRemain - nums[cur], discardRemain) ||
			recur(nums, cur + 1, pickRemain, discardRemain - nums[cur]);
	}
}
