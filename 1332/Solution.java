class Solution {
	public int removePalindromeSub(String s) {
		if (s.equals("")) {
			return 0;
		} else if (isParlindromic(s)) {
			return 1;
		} else {
			return 2;
		}
	}

	private boolean isParlindromic(String s) {
		int i = 0, j = s.length() - 1;
		while (i < j) {
			if (s.charAt(i++) != s.charAt(j--)) {
				return false;
			}
		}
		return true;
	}
}
