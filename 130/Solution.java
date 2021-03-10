class Solution {
	public void solve(char[][] board) {
		for (int i = 0; i < board.length; i++) {
			if (board[i][0] == 'O') recur(board, i, 0);
			if (board[i][board[0].length - 1] == 'O') recur(board, i, board[0].length - 1);
		}
		for (int j = 1; j < board[0].length - 1; j++) {
			if (board[0][j] == 'O') recur(board, 0, j);
			if (board[board.length - 1][j] == 'O') recur(board, board.length - 1, j);
		}
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == 'A') board[i][j] = 'O';
			}
		}
	}

	private void recur(char[][] board, int x, int y) {
		if (x < 0 || x >= board.length || y < 0 || y >= board[0].length) return;
		if (board[x][y] != 'O') return;
		board[x][y] = 'A';
		int[][] dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
		for (int[] dir : dirs) recur(board, x + dir[0], y + dir[1]);
	}
}
