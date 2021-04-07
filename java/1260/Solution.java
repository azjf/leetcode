import java.util.List;
import java.util.LinkedList;

class Solution {
	public List<List<Integer>> shiftGrid(int[][] grid, int k) {
		int m = grid.length, n = grid[0].length, size = m * n;

		k %= size;
		if (k % size != 0) {
			reverse(grid, 0, size - k - 1);
			reverse(grid, size - k, size - 1);
			reverse(grid, 0, size - 1);
		}

		List<List<Integer>> res = new LinkedList<>();
		for (int i = 0; i < m; i++) {
			List<Integer> list = new LinkedList<>();
			res.add(list);
			for (int j = 0; j < n; j++) {
				list.add(grid[i][j]);
			}
		}
		return res;
	}

	private void reverse(int[][] grid, int start, int end) {
		int n = grid[0].length;
		while (start < end) {
			int i1 = start / n, j1 = start % n;
			int i2 = end / n, j2 = end % n;
			int tmp = grid[i1][j1];
			grid[i1][j1] = grid[i2][j2];
			grid[i2][j2] = tmp;
			start++;
			end--;
		}
	}
}
