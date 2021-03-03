import java.util.List;

class Solution {
	public boolean wordBreak(String s, List<String> wordDict) {
		boolean[] dp = new boolean[s.length() + 1];
		dp[0] = true;
		for (int i = 1; i < dp.length; i++) { // current char is s.charAt(i - 1)
			for (String w : wordDict) {
				if (i >= w.length() && dp[i - w.length()] && s.substring(i - w.length(), i).equals(w)) dp[i] = true;
			}
		}
		return dp[dp.length - 1];
	}
}
