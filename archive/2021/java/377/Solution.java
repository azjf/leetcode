class Solution {
	public int combinationSum4(int[] nums, int target) {
		int[] dp = new int[target + 1];  // counts
		dp[0] = 1;
		// row:		dp[i][j] = dp[i - 1][j] + dp[i][j - nums[i]]
		// column:	dp[i][j] = dp[i][j - 1] + dp[i - nums[j][j]]
		// ordered, iterating by column
		for (int i = 1; i < dp.length; i++) {
			for (int num : nums) {
				if (num <= i) dp[i] += dp[i - num];
			}
		}
		return dp[dp.length - 1];
	}
}
