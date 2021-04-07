import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<List<String>> ans;

	public List<List<String>> partition(String s) {
		ans = new LinkedList<>();
		recur(s, 0, new LinkedList<String>());
		return ans;
	}

	private void recur(String s, int lo, LinkedList<String> list) {
		if (lo == s.length()) {
			ans.add(new LinkedList<String>(list));
		}
		for (int i = lo; i < s.length(); i++) {
			if (isPalindrome(s, lo, i)) {
				list.add(s.substring(lo, i + 1));
				recur(s, i + 1, list);
				list.removeLast();
			}
		}
	}

	private boolean isPalindrome(String s, int lo, int hi) {
		for (; lo < hi && s.charAt(lo) == s.charAt(hi); lo++, hi--);
		return lo >= hi;
	}
}
