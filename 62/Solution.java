class Solution {
	public int uniquePaths(int m, int n) {
		m -= 1;
		n -= 1;
		int min = m < n ? m : n;
		long ans = 1;
		for (int i = m + n; i > m + n - min; i--) ans *= i;
		for (int i = min; i >= 1; i--) ans /= i;
		return (int) ans;
	}

	public static void main(String[] args) {
		System.out.println((new Solution()).uniquePaths(10, 10));
	}
}
