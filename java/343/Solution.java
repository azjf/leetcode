class Solution {
	public int integerBreak(int n) {
		if (n < 2) return 0;

		int[] dp = new int[n + 1];
		for (int i = 2; i <= n; i++) {
			// row:		dp[i][j] = max(dp[i - 1][j], j * max(dp[i][i - j], i - j))
			// column:	dp[i][j] = max(dp[i][j - 1], j * max(dp[i - j][j], i - j))
			for (int j = 1; j < i; j++) {
				dp[i] = Math.max(dp[i], j * Math.max(dp[i - j], i - j));
			}
		}
		return dp[dp.length - 1];
	}
}
