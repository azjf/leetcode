import java.util.LinkedList;
import java.util.List;

class Solution2 {
	private static String[] digitMap = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	public List<String> letterCombinations(String digits) {
		if (digits.equals("")) {
			return new LinkedList<String>();
		}
		return recur(digits.toCharArray(), 0);
	}

	private List<String> recur(char[] digits, int depth) {
		List<String> res = new LinkedList<String>();
		if (depth == digits.length) {
			res.add("");
			return res;
		}
		for (char c : digitMap[digits[depth] - '2'].toCharArray()) {
			for (String str : recur(digits, depth + 1)) {
				res.add(c + str);
			}
		}
		return res;
	}
}
