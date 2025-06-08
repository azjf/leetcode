class Solution {
	public int minSteps(int n) {
		if (n == 1) return 0;

		return recur(n);
	}

	private int recur(int n) {
		for (int i = 2; i <= Math.sqrt(n); i++) {
			if (n % i == 0) return i + recur(n / i);  // copy 1 + paste (i - 1)
		}
		return n;  // copy 1 + paste (n - 1)
	}
}
