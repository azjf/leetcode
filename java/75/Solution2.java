class Solution {
	public void sortColors(int[] nums) {
		int[] cnts = new int[3];
		for (int num : nums) cnts[num]++;
		for (int i = 0; i < nums.length; i++) {
			if (i < cnts[0]) {
				nums[i] = 0;
			} else if (i < cnts[0] + cnts[1]) {
				nums[i] = 1;
			} else {
				nums[i] = 2;
			}
		}
	}
}
