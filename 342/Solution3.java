class Solution3 {
	public boolean isPowerOfFour(int n) {
		if (n == 0) {
			return false;
		}
		return recur(n);
	}

	private boolean recur(int n) {
		if (n == 1) {
			return true;
		}
		if (n % 4 != 0) {
			return false;
		} else {
			return recur(n / 4);
		}
	}
}
