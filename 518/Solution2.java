class Solution {
	public int change(int amount, int[] coins) {
		int[][] dp = new int[coins.length + 1][amount + 1];
		for (int i = 0; i < dp.length; i++) dp[i][0] = 1;

		for (int i = 0; i < dp.length - 1; i++) {
			for (int j = 0; j <= amount; j++) {
				if (j < coins[i]) {
					dp[i + 1][j] = dp[i][j];
				} else {
					dp[i + 1][j] = dp[i][j] + dp[i + 1][j - coins[i]];
				}
			}
		}
		return dp[dp.length - 1][amount];
	}
}
