class Solution {
	public int findMaxForm(String[] strs, int m, int n) {
		int[][] dp = new int[m + 1][n + 1];  // rolling array
		for (String str : strs) {
			// dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - n0][k - n1])
			int n0 = 0, n1 = 0;
			for (char c : str.toCharArray()) {
				if (c == '0') n0++;
			}
			n1 = str.length() - n0;

			for (int j = m; j >= n0; j--) {
				for (int k = n; k >= n1; k--) {
					dp[j][k] = Math.max(dp[j][k], 1 + dp[j - n0][k - n1]);
				}
			}
		}
		return dp[m][n];
	}
}
