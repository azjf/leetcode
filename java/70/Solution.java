class Solution {
	public int climbStairs(int n) {
		if (n <= 1) return n;

		int pre = 2;
		int ppre = 1;
		for (int i = 2; i < n; i++) {
			int cur = pre + ppre;
			ppre = pre;
			pre = cur;
		}
		return pre;
	}
}
