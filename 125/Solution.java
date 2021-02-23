class Solution {
	public boolean isPalindrome(String s) {
		if (s == null) {
			return false;
		}
		if (s.length() == 0) {
			return true;
		}

		char[] chs = s.toLowerCase().toCharArray();
		int i = 0, j = s.length() - 1;
		while (i < j) {
			if (!isValidChar(chs[i])) {
				i++;
				continue;
			}
			if (!isValidChar(chs[j])) {
				j--;
				continue;
			}
			if (chs[i++] != chs[j--]) return false;
		}
		return true;

	}

	private boolean isValidChar(char c) {
		return (c >= 'a' && c < 'z') || (c >= '0' && c <= '9');
	}
}
