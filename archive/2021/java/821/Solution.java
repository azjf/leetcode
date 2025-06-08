class Solution {
	public int[] shortestToChar(String s, char c) {
		int len = s.length();
		int[] idx = new int[len];
		int pre = -10000;
		for (int i = 0; i < len; i++) {
			if (s.charAt(i) == c) {
				pre = i;
			}
			idx[i] = i - pre;
		}

		int post = len + 9999;
		for (int i = len - 1; i >= 0; i--) {
			if (s.charAt(i) == c) {
				post = i;
			}
			idx[i] = Math.min(idx[i], post - i);
		}

		return idx;
	}
}
