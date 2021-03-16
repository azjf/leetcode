class Solution {
	public int minSubArrayLen(int target, int[] nums) {
		int ans = nums.length + 1;
		int lo = 0, hi = 0, sum = 0;
		while (hi < nums.length) {
			do {
				sum += nums[hi++];
			} while (hi < nums.length && sum < target);
			while (lo < hi && sum - nums[lo] >= target) sum -= nums[lo++];
			if (sum >= target) ans = Math.min(ans, hi - lo);
		}
		return ans == nums.length + 1 ? 0 : ans;
	}
}
