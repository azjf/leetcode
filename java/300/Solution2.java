class Solution {
	public int lengthOfLIS(int[] nums) {
		int[] tails = new int[nums.length];
		int len = 0;
		for (int num : nums) {
			int idx = binarySearch(tails, len, num);
			tails[idx] = num;
			if (idx == len) len++;
		}
		return len;
	}

	private int binarySearch(int[] nums, int len, int num) {
		int lo = 0, hi = len - 1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (nums[mid] > num) {
				hi = mid - 1;
			} else if (nums[mid] < num) {
				lo = mid + 1;
			} else {
				return mid;
			}
		}
		return lo;
	}
}
