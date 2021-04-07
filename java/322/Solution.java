class Solution {
	public int coinChange(int[] coins, int amount) {
		if (coins.length == 0) return -1;
		if (amount == 0) return 0;

		int[] dp = new int[amount];
		for (int i = 0; i < dp.length; i++) {
			dp[i] = Integer.MAX_VALUE;
		}

		for (int i = 0; i < dp.length; i++) {
			for (int c : coins) {
				if (c == i + 1) {
					dp[i] = 1;
				} else if (c < i + 1 && dp[i - c] != Integer.MAX_VALUE) {
					dp[i] = Math.min(dp[i], dp[i - c] + 1);
				}
			}
		}
		return dp[dp.length - 1] == Integer.MAX_VALUE ? -1 : dp[dp.length - 1];
	}
}
