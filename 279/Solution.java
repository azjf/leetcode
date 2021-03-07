class Solution {
	public int numSquares(int n) {
		int[] dp = new int[n + 1];
		for (int i = 0; i < dp.length; i++) dp[i] = n + 1;
		dp[0] = 0;

		for (int i = 1; i < dp.length; i++) {
			// row: 	dp[i][j] = min(dp[i - 1][j], dp[i][i - j * j])
			// column:	dp[i][j] = min(dp[i][j - 1], dp[i - j * j][j])
			for (int j = 1; j * j <= i; j++) {
				dp[i] = Math.min(dp[i], 1 + dp[i - j * j]);
			}
		}
		return dp[dp.length - 1];
	}
}
