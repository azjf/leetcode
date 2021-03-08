class Solution {
	public int maxProfit(int[] prices, int fee) {
		if (prices.length == 0) return 0;

		int[] buy = new int[prices.length];
		int[] sell = new int[prices.length];
		int[] s1 = new int[prices.length];
		int[] s2 = new int[prices.length];
		buy[0] = s1[0] = -prices[0];
		sell[0] = s2[0] = 0;
		for (int i = 1; i < prices.length; i++) {
			buy[i] = Math.max(sell[i - 1], s2[i - 1]) - prices[i];
			s1[i] = Math.max(s1[i - 1], buy[i - 1]);
			sell[i] = Math.max(buy[i - 1], s1[i - 1]) + prices[i] - fee;
			s2[i] = Math.max(s2[i - 1], sell[i - 1]);
		}
		return Math.max(sell[sell.length - 1], s2[s2.length - 1]);
	}
}
