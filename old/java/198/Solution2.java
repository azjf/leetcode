class Solution {
	public int rob(int[] nums) {
		int cur = 0, pre = 0;
		for (int num: nums) {
			int tmp = cur;
			cur = Math.max(cur, pre + num);
			pre = tmp;
		}
		return cur;
	}
}
