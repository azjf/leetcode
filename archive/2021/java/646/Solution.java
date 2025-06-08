import java.util.Arrays;

class Solution {
	public int findLongestChain(int[][] pairs) {
		Arrays.sort(pairs, (a, b) -> (a[0] - b[0]));

		int[] dp = new int[pairs.length];  // length of the chain ending with pairs[i]
		for (int i = 0; i < pairs.length; i++) {
			int max = 0;
			for (int j = 0; j < i; j++) {
				if (pairs[j][1] < pairs[i][0] && dp[j] > max) max = dp[j];
			}
			dp[i] = max + 1;
		}

		int max = 0;
		for (int len : dp) {
			if (len > max) max = len;
		}
		return max;
	}
}
