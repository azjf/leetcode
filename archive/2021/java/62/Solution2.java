class Solution {
	public int uniquePaths(int m, int n) {
		m -= 1;
		n -= 1;
		int min = m < n ? m : n;
		long ans = 1;
		for (int i = 1; i <= min; i++) ans = ans * (m + n + 1 - i) / i; // do not use "ans *= " (integer division)
		return (int) ans;
	}

	public static void main(String[] args) {
		System.out.println((new Solution()).uniquePaths(4, 4));
	}
}
