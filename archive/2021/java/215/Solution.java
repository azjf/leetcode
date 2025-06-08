class Solution {
	public int findKthLargest(int[] nums, int k) {
		if (nums.length == 1) return nums[0];

		int lo = 0, hi = nums.length - 1;
		while (lo <= hi) {
			int idx = partition(nums, lo, hi);
			if (idx < nums.length - k) {
				lo = idx + 1;
			} else if (idx > nums.length - k) {
				hi = idx - 1;
			} else {
				return nums[idx];
			}
		}
		return -1;
	}

	public int findKthLargest2(int[] nums, int k) {
		return recur(nums, 0, nums.length - 1, nums.length - k);
	}

	private int recur(int[] nums, int lo, int hi, int k) {
		if (lo == hi) return nums[lo];
		int j = partition(nums, lo, hi);
		if (j > k) {
			return recur(nums, lo, j - 1, k);
		} else if (j < k) {
			return recur(nums, j + 1, hi, k);
		} else {
			return nums[j];
		}
	}

	private int partition(int[] nums, int lo, int hi) {
		int j = lo;
		int pivot = nums[lo];
		for (int i = lo + 1; i <= hi; i++) {
			if (nums[i] < pivot) exch(nums, i, ++j);
		}
		exch(nums, lo, j);  // lo, not 0
		return j;
	}

	private int partition2(int[] nums, int lo, int hi) {
		int pivot = nums[lo];
		exch(nums, lo, hi);
		int j = lo;
		for (int i = lo; i < hi; i++) {
			if (nums[i] < pivot) exch(nums, i, j++);
		}
		exch(nums, hi, j);
		return j;
	}

	private int partition3(int[] nums, int lo, int hi) {
		int i = lo, j = hi + 1;
		int pivot = nums[lo];
		while (true) {
			while (nums[++i] < pivot) if (i == hi) break;
			while (nums[--j] > pivot) if (j == lo) break;
			if (i >= j) break;
			exch(nums, i, j);
		}
		exch(nums, lo, j);  // lo, not 0
		return j;
	}

	private void exch(int[] nums, int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}
