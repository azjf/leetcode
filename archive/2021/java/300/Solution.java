class Solution {
	public int lengthOfLIS(int[] nums) {
		int[] dp = new int[nums.length];  // length of the increasing subsequence ending with nums[i]
		for (int i = 0; i < nums.length; i++) {
			// dp[i] = 1 + max(dp[j] | nums[j] < nums[i], j < i)
			int max = 0;
			for (int j = 0; j < i; j++) {
				if (nums[j] < nums[i] && dp[j] > max) {
					max = dp[j];
				}
			}
			dp[i] = max + 1;
		}

		int max = 0;
		for (int cnt : dp) {
			if (cnt > max) max = cnt;
		}
		return max;
	}
}
