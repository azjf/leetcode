class Solution {
	public boolean isPowerOfFour(int n) {
		//return (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
		return (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
	}
}
