class Solution {
	public void sortColors(int[] nums) {
		int r = 0, g = 0, b = 0;
		for (int n : nums) {
			// at last, r = num of 0s, g = num of 0s and 1s, b = num of 0s, 1s, and 2s
			// growing of throw blocks
			if (n == 0) {
				nums[b++] = 2;
				nums[g++] = 1;
				nums[r++] = 0;
			} else if (n == 1) {
				nums[b++] = 2;
				nums[g++] = 1;
			} else {
				nums[b++] = 2;
			}
		}
	}
}
