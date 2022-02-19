class Solution {
	public int coinChange(int[] coins, int amount) {
		if (coins.length == 0) return -1;
		if (amount == 0) return 0;

		int[] dp = new int[amount];
		for (int i = 0; i < dp.length; i++) dp[i] = amount + 1;

		for (int i = 0; i < dp.length; i++) {
			for (int c : coins) {
				if (c == i + 1) {
					dp[i] = 1;
				} else if (c < i + 1) {
					dp[i] = Math.min(dp[i], dp[i - c] + 1);
				}
			}
		}
		return (int) (dp[dp.length - 1] == (int) amount + 1 ? -1 : dp[dp.length - 1]);
	}
}
