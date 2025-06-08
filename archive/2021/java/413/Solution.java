class Solution {
	public int numberOfArithmeticSlices(int[] nums) {
		if (nums.length < 3) return 0;

		int[] dp = new int[nums.length];
		int cnt = 1, delta = 0;
		for (int i = 1; i < nums.length; i++, cnt++) {
			if (nums[i] - nums[i - 1] != delta) {
				delta = nums[i] - nums[i - 1];
				cnt = 1;
			}
			dp[i] = dp[i - 1] + cnt - 1;
		}

		return dp[dp.length - 1];
	}
}
