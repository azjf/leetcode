class Solution {
	public int numDecodings(String s) {
		int pre = 1, ppre = -1;
		for (int i = 0; i < s.length() && pre != 0; i++) {
			int cur = 0;
			if (s.charAt(i) != '0') cur += pre;
			if (i != 0 && s.charAt(i - 1) != '0' && (s.charAt(i - 1) - '0') * 10 + s.charAt(i) - '0' <= 26) cur += ppre;
			ppre = pre;
			pre = cur;
		}
		return pre;
	}
}
