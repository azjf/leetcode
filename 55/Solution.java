class Solution {
	public boolean canJump(int[] nums) {
		if (nums.length == 1) return true;

		for (int farthest = nums[0], i = 1; i <= farthest; i++) {
			if (nums[i] + i > farthest) farthest = nums[i] + i;
			if (farthest >= nums.length - 1) return true;
		}
		return false;
	}
}
