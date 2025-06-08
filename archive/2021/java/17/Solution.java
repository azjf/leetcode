import java.util.LinkedList;
import java.util.List;

class Solution {
	private static String[] digitMap = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
	private List<String> ans = new LinkedList<String>();

	public List<String> letterCombinations(String digits) {
		if (!digits.equals("")) {
			recur(digits.toCharArray(), 0, "");
		}
		return ans;
	}

	private void recur(char[] digits, int depth, String str) {
		if (depth == digits.length) {
			ans.add(str);
			return;
		}
		for (char c : digitMap[digits[depth] - '2'].toCharArray()) {
			recur(digits, depth + 1, str + c);
		}
	}
}
