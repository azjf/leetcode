class Solution {
	public boolean isUgly(int num) {
		if (num == 0) {
			return false;
		}
		return recur(num);
	}
	
	private boolean recur(int num) {
		if (num == 1) {
			return true;
		}
		
		int[] uglys = { 2, 3, 5 };
		for (int u : uglys) {
			if (num % u == 0) {
				return recur(num / u);
			}
		}

		return false;
	}
}

