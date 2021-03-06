class Solution {
	public int coinChange(int[] coins, int amount) {
		if (coins.length == 0) return -1;
		if (amount == 0) return 0;

		int[] dp = new int[amount + 1];
		for (int i = 0; i < dp.length; i++) dp[i] = amount + 1;
		dp[0] = 0;
		for (int coin : coins) {
			for (int j = coin; j < dp.length; j++) {
				dp[j] = Math.min(dp[j], 1 + dp[j - coin]);
			}
		}
		return dp[dp.length - 1] == amount + 1 ? -1 : dp[dp.length - 1];
	}
}
