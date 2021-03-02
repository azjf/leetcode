class Solution {
	public double myPow(double x, int n) {
		long n1 = n;
		boolean isPos = n1 >= 0;
		if (!isPos) n1 = -n1;

		double ans = 1;
		while (n1 != 0) {
			if ((n1 & 1) == 1) ans *= x;
			n1 >>= 1;
			x *= x;
		}
		return isPos ? ans : 1 / ans;
	}
}
