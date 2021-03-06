class Solution {
	public boolean canPartition(int[] nums) {
		if (nums.length == 1) return false;

		int sum = 0;
		for (int num : nums) sum += num;
		if (sum % 2 != 0) return false;
		sum /= 2;

		boolean[][] dp = new boolean[nums.length + 1][sum + 1];
		for (int i = 0; i < dp.length; i++) {
			dp[i][0] = true;
		}
		for (int i = 0; i < dp.length - 1; i++) {
			for (int j = 0; j < dp[0].length; j++) {
				dp[i + 1][j] = j - nums[i] >= 0 ? dp[i][j] || dp[i][j - nums[i]] : dp[i][j];
			}
		}
		return dp[dp.length - 1][sum];
	}
}
