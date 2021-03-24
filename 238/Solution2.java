class Solution {
	public int[] productExceptSelf(int[] nums) {
		int[] pre = new int[nums.length];
		int[] post = new int[nums.length];
		pre[0] = 1;
		post[nums.length - 1] = 1;
		for (int i = 1; i < nums.length; i++) pre[i] = nums[i - 1] * pre[i - 1];
		for (int i = nums.length - 2; i >= 0; i--) post[i] = nums[i + 1] * post[i + 1];
		for (int i = 0; i < nums.length; i++) nums[i] = pre[i] * post[i];
		return nums;
	}
}
