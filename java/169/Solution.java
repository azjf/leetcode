class Solution {
	public int majorityElement(int[] nums) {
		int res = 0, cnt = 0;
		for (int num : nums) {
			if (cnt == 0) {
				res = num;
				cnt = 1;
				continue;
			}
			cnt += res == num ? 1 : -1;
		}
		return res;
	}
}
