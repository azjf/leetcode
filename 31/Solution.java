class Solution {
	public void nextPermutation(int[] nums) {
		if (nums == null || nums.length <= 1) return;

		int i = nums.length - 2;
		while (i >= 0 && nums[i] >= nums[i + 1]) i--;

		if (i >= 0) {
			int j = nums.length - 1;
			while (j > i && nums[j] <= nums[i]) j--;
			swap(nums, i, j);
		}

		reverse(nums, i + 1, nums.length - 1);
	}

	private void swap(int[] nums, int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}

	private void reverse(int[] nums, int start, int end) {
		while (start < end) swap(nums, start++, end--);
	}

	public static void main(String[] args) {
		int[] nums = { 1, 2, 3 };
		(new Solution()).nextPermutation(nums);
		for (int num : nums) {
			System.out.println(num);
		}
	}
}
