import java.util.Arrays;
import java.util.Comparator;

class Solution {
	public int[][] merge(int[][] intervals) {
		Arrays.sort(intervals, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return Integer.compare(a[0], b[0]);
			}
		});
		
		int[] marked = new int[intervals.length];
		int n = 1;
		marked[0] = 1;
		for (int l = 0, r = 1; r < intervals.length; r++) {
			if (intervals[l][1] >= intervals[r][0]) {
				if (intervals[l][1] < intervals[r][1]) intervals[l][1] = intervals[r][1];
			} else {
				l = r;
				marked[l] = 1;
				n++;
			}
		}

		int[][] ans = new int[n][2];
		for (int i = 0, j = 0; j < intervals.length; j++) {
			if (marked[j] == 1) ans[i++] = intervals[j];
		}
		return ans;
	}
}
