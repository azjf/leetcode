import java.util.HashMap;

class Solution {
	public int[] twoSum(int[] nums, int target) {
		HashMap<Integer, Integer> hm = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			int x = nums[i], y = target - x;
			if (hm.containsKey(y)) {
				return new int[] {i, hm.get(y)};
			} else {
				hm.put(nums[i], i);
			}
		}
		return null;
	}
}
