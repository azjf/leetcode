class Solution {
	public int maximalSquare(char[][] matrix) {
		int[][] dp = new int[matrix.length + 1][matrix[0].length + 1];
		for (int i = 0; i < dp.length; i++) dp[i][0] = 0;
		for (int j = 0; j < dp[0].length; j++) dp[0][j] = 0;

		int len = 0;
		for (int i = 1; i < dp.length; i++) {
			for (int j = 1; j < dp[0].length; j++) {
				dp[i][j] = matrix[i - 1][j - 1] == '0' ? 0 : Math.min(dp[i - 1][j - 1], Math.min(dp[i][j - 1], dp[i - 1][j])) + 1;
				if (dp[i][j] > len) len = dp[i][j];
			}
		}
		return len * len;
	}
}
