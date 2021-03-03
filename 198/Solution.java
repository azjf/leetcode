class Solution {
	public int rob(int[] nums) {
		int pre = 0, ppre = 0;
		for (int i = 0; i < nums.length; i++) {
			int cur = Math.max(pre, ppre + nums[i]);
			ppre = pre;
			pre = cur;
		}
		return pre;
	}
}
