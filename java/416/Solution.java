class Solution {
	public boolean canPartition(int[] nums) {
		if (nums.length == 1) return false;

		int sum = 0;
		for (int num : nums) sum += num;
		if (sum % 2 != 0) return false;
		sum /= 2;

		boolean[] dp = new boolean[sum + 1];
		dp[0] = true;
		for (int num : nums) {
			for (int t = sum; t >= num; t--) {  // target
				dp[t] = dp[t] || dp[t - num];
			}
		}
		return dp[dp.length - 1];
	}
}
