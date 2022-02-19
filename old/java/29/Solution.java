class Solution {
	public int divide(int dividend, int divisor) {
		if (divisor == -2147483648) {
			return dividend == -2147483648 ? 1 : 0;
		}
		if (dividend == -2147483648) {
			if (divisor == -1) return 2147483647;
			int absDivisor = divisor < 0 ? -divisor : divisor;
			int[] res = div(2147483647, absDivisor);
			if (res[1] + 1 == absDivisor) res[0]++;
			return divisor <= 0 ? res[0] : -res[0];
		}

		boolean pos1 = dividend > 0, pos2 = divisor > 0, pos = !(pos1 ^ pos2);
		if (!pos1) dividend = -dividend;
		if (!pos2) divisor = -divisor;

		int q = div(dividend, divisor)[0];
		return pos ? q : -q;
	}

	private int[] div(int dividend, int divisor) {
		int power = divisor, n = 0;
		while (power <= dividend >> 1) {
			power += power;
			n++;
		}

		int q = 0, r = dividend;
		while (n >= 0 && r > 0) {
			//System.out.println(n + " " + power + " " + r + " " + q);
			if (r >= power) {
				r -= power;
				q |= (int) 1 << n;
			}
			power >>= 1;
			n--;
			//System.out.println(n + " " + power + " " + r + " " + q);
		}

		return new int[] { q, r };
	}

	public static void main(String[] args) {
		System.out.println((new Solution()).divide(-2147483648, -1));
		System.out.println((new Solution()).divide(-1, -2147483648));
		System.out.println((new Solution()).divide(2147483647, 3));
	}
}
