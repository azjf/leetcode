class Solution {
	public void moveZeroes(int[] nums) {
		int ptr = -1;
		for (int i = 0; i < nums.length; i++) {
			if (nums[i] == 0) {
				ptr = ptr == -1 ? i : ptr;
			} else {
				if (ptr != -1) {
					nums[ptr++] = nums[i];
					nums[i] = 0;
				}
			}
		}
	}
}
