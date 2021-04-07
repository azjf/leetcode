class Solution {
	public int maxProfit(int[] prices) {
		int buy1 = Integer.MIN_VALUE, sell1 = 0;
		int buy2 = Integer.MIN_VALUE, sell2 = 0;
		for (int p : prices) {
			if (buy1 < -p) buy1 = -p;
			if (sell1 < buy1 + p) sell1 = buy1 + p;
			if (buy2 < sell1 - p) buy2 = sell1 - p;
			if (sell2 < buy2 + p) sell2 = buy2 + p;
		}
		return sell2;
	}
}
