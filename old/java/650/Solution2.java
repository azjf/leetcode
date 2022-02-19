class Solution {
	public int minSteps(int n) {
		// dp[] is only for the backup of dp[i / j]
		// not so efficient as the recursion method because of so many computations for unnecessary dp[..]
		int[] dp = new int[n + 1];
		for (int i = 2; i < dp.length; i++) {
			dp[i] = i;
			for (int j = 2; j <= Math.sqrt(n); j++) {
				if (i % j == 0) {  // j <= i
					dp[i] = j + dp[i / j];  // copy (1) + paste (j - 1)
					//dp[i] = dp[j] + dp[i / j];  // dp[j] = j for primes
					break;
				}
			}
		}
		return dp[dp.length - 1];
	}
}
