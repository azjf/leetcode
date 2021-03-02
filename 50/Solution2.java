class Solution2 {
	public double myPow(double x, int n) {
		long n1 = n;
		boolean isPos = n1 >= 0;
		if (!isPos) n1 = -n1;

		double ans = recur(x, n1);
		return isPos ? ans : 1 / ans;
	}

	private double recur(double x, long n) {
		if (n == 0) return 1;
		if (n == 1) return x;
		return recur(x * x, n / 2) * (n % 2 == 0 ? 1 : x);
	}
}
