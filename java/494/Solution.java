class Solution {
	public int findTargetSumWays(int[] nums, int S) {
		/** sum(P) - sum(N) = target
		 * sum(P) - sum(N) + sum(P) + sum(N) = target + sum(P) + sum(N)
		 * 2 * sum(P) = target + sum(nums)
		 * sum(P) = (target + sum(nums)) / 2
		**/
		int sum = 0;
		for (int num : nums) sum += num;
		if (sum < S || (sum + S) % 2 != 0) return 0;
		sum = (sum + S) / 2;

		int[] dp = new int[sum + 1];
		dp[0] = 1;
		for (int num : nums) {
			for (int j = dp.length - 1; j >= num; j--) {
				dp[j] = dp[j] + dp[j - num];
			}
		}
		return dp[dp.length - 1];
	}
}
