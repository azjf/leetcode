class Solution {
	public int numIslands(char[][] grid) {
		int ans = 0;
		for (int i = 0; i < grid.length; i++) {
			for (int j = 0; j < grid[0].length; j++) {
				if (grid[i][j] == '1') {
					ans++;
					mark(grid, i, j);
				}
			}
		}
		return ans;
	}

	public void mark(char[][] grid, int x, int y) {
		if (x < 0 || x >= grid.length || y < 0 || y >= grid[0].length) return;
		if (grid[x][y] != '1') return;

		grid[x][y] = '0';
		int[][] dirs = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
		for (int i = 0; i < dirs.length; i++) mark(grid, x + dirs[i][0], y + dirs[i][1]);
	}
}
