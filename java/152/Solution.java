class Solution {
	public int maxProduct(int[] nums) {
		int maxProd = 1, minProd = 1, ans = nums[0];
		// maxProd[i] = max(nums[i], nums[i] * maxProd[i - 1], nums[i] * minProd[i - 1])  // maxProd of the subarray end with nums[i]
		// minProd[i] = min(nums[i], nums[i] * maxProd[i - 1], nums[i] * minProd[i - 1])  // minProd of the subarray end with nums[i]
		// ans[i] = max(ans[i - 1], maxProd[i])  // maxProd of subarrays nums[0...i]
		for (int num: nums) {
			int a = maxProd * num, b = minProd * num;
			maxProd = Math.max(num, Math.max(a, b));
			minProd = Math.min(num, Math.min(a, b));
			ans = Math.max(ans, maxProd);
		}
		return ans;
	}
}
