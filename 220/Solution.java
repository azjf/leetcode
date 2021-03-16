import java.util.HashMap;

class Solution {
	public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
		HashMap<Integer, Integer> map = new HashMap<>();
		for (int i = 0; i < nums.length; i++) {
			int idx = (int) Math.floorDiv(nums[i], (long) t + 1);
			//System.out.printf("%d, %d\n", nums[i], idx);
			if (map.containsKey(idx)) return true;
			if (map.containsKey(idx - 1) && Math.abs((long) nums[i] - (long) map.get(idx - 1)) <= (long) t) return true;
			if (map.containsKey(idx + 1) && Math.abs((long) nums[i] - (long) map.get(idx + 1)) <= (long) t) return true;
			map.put(idx, nums[i]);
			if (i >= k) map.remove((int) Math.floorDiv(nums[i - k], (long) t + 1));
		}
		return false;
	}
}
