class Solution {
	public int numSquares(int n) {
		int[] dp = new int[n + 1];
		for (int j = 0; j < dp.length; j++) dp[j] = n + 1;
		dp[0] = 0;

		for (int i = 1; i < dp.length; i++) {
			// row: 	dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - i * i])  // i (item), j (space), dp[i][j] (value)
			// column:	dp[i][j] = min(dp[i][j - 1], 1 + dp[i - j * j][j])  // i (space), j (item), dp[i][j] (value)
			for (int j = i * i; j < dp.length; j++) {  // row
				dp[j] = Math.min(dp[j], 1 + dp[j - i * i]);
			}
		}
		return dp[dp.length - 1];
	}
}
