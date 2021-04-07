import java.util.HashMap;

class Solution {
	private HashMap<Integer, Integer> map;

	public int numTrees(int n) {
		map = new HashMap<>();
		return recur(n);
	}

	private int recur(int n) {
		if (map.containsKey(n)) return map.get(n);
		if (n <= 1) return 1;
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res += recur(i - 1) * recur(n - i);
		}
		map.put(n, res);
		return res;
	}
}
