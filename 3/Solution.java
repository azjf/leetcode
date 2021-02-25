import java.util.HashMap;

class Solution {
	public int lengthOfLongestSubstring(String s) {
		HashMap<Character, Integer> map = new HashMap<>();
		int res = 0;
		for (int i = 0, j = 0; j < s.length(); j++) {
			char c = s.charAt(j);
			if (map.containsKey(c) && map.get(c) >= i) {
				i = map.get(c) + 1;
			} else {
				res = Math.max(j - i + 1, res);
			}
			map.put(c, j);
		}
		return res;
	}

	public static void main(String[] args) {
		System.out.println((new Solution()).lengthOfLongestSubstring("tmmzuxt"));
	}
}
