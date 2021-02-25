class Solution {
	public boolean checkPossibility(int[] nums) {
		boolean isFirstTime = true;
		for (int i = 1; i < nums.length; i++) {
			if (nums[i] < nums[i - 1]) {
				if (isFirstTime) {
					isFirstTime = false;
					if (i >= 2 && nums[i] < nums[i - 2]) {
						nums[i] = nums[i - 1];
					}
				} else {
					return false;
				}
			}
		}
		return true;
	}
}
