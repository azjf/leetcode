import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<String> ans = new LinkedList<String>();
	private int n;

	public List<String> generateParenthesis(int n) {
		this.n = n;
		recur(0, 0, "");
		return ans;
	}

	private void recur(int l, int r, String s) {
		if (l > n || r > n) return;
		if (l == r && r == n) {
			ans.add(s);
			return;
		}
		if (l < r) return;
		recur(l + 1, r, s + "(");
		recur(l, r + 1, s + ")");
	}

	public static void main(String[] args) {
		for (String s : (new Solution()).generateParenthesis(4)) {
			System.out.println(s);
		}
	}
}
