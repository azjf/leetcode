class Solution {
	public boolean isUgly(int num) {
		if (num == 0) {
			return false;
		}

		int[] ugly = { 2, 3, 5 };
		for (int u : ugly) {
			while (num % u == 0) {
				num /= u;
			}
		}
		return num == 1;
	}
}
