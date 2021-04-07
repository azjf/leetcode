class Solution {
	public int search(int[] nums, int target) {
		if (nums == null || nums.length == 0) return -1;

		int lo = 0, hi = nums.length - 1, kk = -1;
		while (lo <= hi) {
			int mid = (lo + hi) / 2;
			if (mid < hi && nums[mid] > nums[mid + 1]) {
				kk = mid;
				break;
			}
			if (nums[mid] > nums[lo]) {
				lo = mid + 1;
			} else if (nums[mid] < nums[lo]) {
				hi = mid;
			} else {
				break;
			}
		}

		lo = kk + 1;
		hi = nums.length + kk;
		while (lo <= hi) {
			int mid = (lo + hi) / 2, mid1 = mid % nums.length;
			if (target > nums[mid1]) {
				lo = mid + 1;
			} else if (target < nums[mid1]) {
				hi = mid - 1;
			} else {
				return mid1;
			}
		}
		return -1;
	}
}
