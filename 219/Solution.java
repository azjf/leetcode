import java.util.HashMap;

class Solution {
	public boolean containsNearbyDuplicate(int[] nums, int k) {
		HashMap<Integer, Integer> hm = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			if (hm.get(nums[i]) != null && hm.get(nums[i]) >= i - k) {
				return true;
			} else {
				hm.put(nums[i], i);
			}
		}
		return false;
	}
}
