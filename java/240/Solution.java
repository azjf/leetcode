class Solution {
	public boolean searchMatrix(int[][] matrix, int target) {
		// search from matrix[m - 1][0] or matrix[0][n - 1]
		int i = matrix.length - 1, j = 0;
		while (i >= 0 && j < matrix[0].length) {
			if (matrix[i][j] > target) {
				i--;
			} else if (matrix[i][j] < target) {
				j++;
			} else {
				return true;
			}
		}
		return false;
	}
}
