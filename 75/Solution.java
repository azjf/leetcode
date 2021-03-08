class Solution {
	public void sortColors(int[] nums) {
		int lt = 0, i = 0, gt = nums.length - 1;
		while (i <= gt) {
			if (nums[i] == 0) {
				int tmp = nums[lt];
				nums[lt++] = nums[i];
				nums[i++] = tmp;
			} else if (nums[i] == 2) {
				int tmp = nums[gt];
				nums[gt--] = nums[i];
				nums[i] = tmp;
			} else {
				i++;
			}
		}
	}
}
