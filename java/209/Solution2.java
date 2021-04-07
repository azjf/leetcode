class Solution {
	public int minSubArrayLen(int target, int[] nums) {
		int ans = nums.length + 1;
		int sum = 0;
		for (int lo = 0, hi = 0; hi < nums.length; hi++) {
			sum += nums[hi];
			if (sum >= target) {
				while (sum >= target) {
					ans = Math.min(ans, hi - lo + 1);
					sum -= nums[lo++];
				}
			}
		}
		return ans == nums.length + 1 ? 0 : ans;
	}
}
