class Solution {
	public void rotate(int[][] matrix) {
		for (int i = 0; i < matrix.length; i++) {
			for (int j = 0; j < matrix.length - i; j++) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[matrix.length - 1 - j][matrix.length - 1 - i];
				matrix[matrix.length - 1 - j][matrix.length - 1 - i] = tmp;
			}
		}
		for (int j = 0; j < matrix.length; j++) {
			for (int i1 = 0, i2 = matrix.length - 1; i1 < i2; i1++, i2--) {
				int tmp = matrix[i1][j];
				matrix[i1][j] = matrix[i2][j];
				matrix[i2][j] = tmp;
			}
		}
	}
}
