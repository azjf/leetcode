import java.util.Arrays;

class Solution {
	public int numberOfArithmeticSlices(int[] nums) {
		if (nums.length < 3) return 0;

		int[] dp = new int[nums.length];  // count of arithmetic slices end with nums[i]
		for (int i = 2; i < nums.length; i++) {
			if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
				dp[i] = dp[i - 1] + 1;
			}
		}
		//System.out.println(Arrays.toString(dp));

		int sum = 0;
		for (int c : dp) sum += c;
		return sum;
	}

	public static void main(String[] args) {
		System.out.println(new Solution().numberOfArithmeticSlices(new int[] { 1, 2, 3, 4, 5, 6 }));
	}
}
