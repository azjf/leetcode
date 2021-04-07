class Solution {
	public int numEquivDominoPairs(int[][] dominoes) {
		int[] counts = new int[9 * 9];
		int cnt = 0;
		for (int[] d : dominoes) {
			int key = d[0] < d[1] ? (d[0] - 1) + (d[1] - 1) * 9 : (d[1] - 1) + (d[0] - 1) * 9;
			cnt += counts[key];
			counts[key] += 1;
		}
		return cnt;
	}
}
