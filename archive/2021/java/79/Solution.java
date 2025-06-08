class Solution {
	public boolean exist(char[][] board, String word) {
		for (int i = 0; i < board.length; i++) {
			for (int j = 0; j < board[0].length; j++) {
				if (board[i][j] == word.charAt(0) && recur(board, word.toCharArray(), 0, i, j)) return true;
			}
		}
		return false;
	}

	private boolean recur(char[][] board, char[] word, int lo, int i, int j) {
		if (lo == word.length) return true;
		if (i == -1 || i == board.length || j == -1 || j == board[0].length) return false;
		if (board[i][j] != word[lo]) return false;
		
		board[i][j] = '*';
		boolean res = recur(board, word, lo + 1, i + 1, j)
			|| recur(board, word, lo + 1, i - 1, j)
			|| recur(board, word, lo + 1, i, j + 1)
			|| recur(board, word, lo + 1, i, j - 1);
		board[i][j] = word[lo];
		return res;
	}
}
