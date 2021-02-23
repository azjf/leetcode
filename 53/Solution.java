class Solution {
	public int maxSubArray(int[] nums) {
		if (nums == null || nums.length == 0) {
			return 0;
		}
		return maxSubArray(nums, 0, nums.length - 1);
	}

	private int maxSubArray(int[] nums, int lo, int hi) {
		if (lo > hi) {
			return Integer.MIN_VALUE;
		}
		int mid = (lo + hi) >> 1;
		int left = maxSubArray(nums, lo, mid - 1);
		int right = maxSubArray(nums, mid + 1, hi);
		
		int leftMaxSum = 0;
		for (int i = mid - 1, sum = 0; i >= lo; i--) {
			sum += nums[i];
			leftMaxSum = Math.max(leftMaxSum, sum);
		}

		int rightMaxSum = 0;
		for (int i = mid + 1, sum = 0; i <= hi; i++) {
			sum += nums[i];
			rightMaxSum = Math.max(rightMaxSum, sum);
		}

		return Math.max(leftMaxSum + nums[mid] + rightMaxSum, Math.max(left, right));
	}
}
