import java.util.ArrayList;

class Solution {
	public int numSquares(int n) {
		ArrayList<Integer> squares = new ArrayList<>();
		int square = 1, diff = 3;
		while (square <= n) {
			// (n + 1)^2 = n^2 + 2n + 1
			squares.add(square);
			square += diff;
			diff += 2;
		}

		int[] dp = new int[n + 1];
		for (int i = 1; i < dp.length; i++) {
			// row: 	dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - i * i])  // i (item), j (space), dp[i][j] (value)
			// column:	dp[i][j] = min(dp[i][j - 1], 1 + dp[i - j * j][j])  // i (space), j (item), dp[i][j] (value)
			int min = n + 1;
			for (int s : squares) {  // column
				if (s > i) break;
				min = Math.min(min, 1 + dp[i - s]);
			}
			dp[i] = min;
		}
		return dp[dp.length - 1];
	}
}
