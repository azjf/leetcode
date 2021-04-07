import java.util.List;

class Solution {
	public boolean wordBreak(String s, List<String> wordDict) {
		boolean[] dp = new boolean[s.length() + 1];
		dp[0] = true;
		for (int i = 1; i < dp.length; i++) { // current char is s.charAt(i - 1)
			// column:	dp[i][j] = dp[i][j - 1] || (substr.equals(wj) && dp[i - wj.length()][j])
			for (String w : wordDict) {
				//if (i >= w.length() && dp[i - w.length()] && s.substring(i - w.length(), i).equals(w)) dp[i] = true;
				if (i >= w.length()) dp[i] = dp[i] || (s.substring(i - w.length(), i).equals(w) && dp[i - w.length()]);
			}
		}
		return dp[dp.length - 1];
	}
}
