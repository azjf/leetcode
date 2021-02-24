import java.util.HashMap;
import java.util.LinkedList;

class Solution {
	public int[] intersection(int[] nums1, int[] nums2) {
		HashMap<Integer, Boolean> map = new HashMap<>();
		for (int num : nums1) {
			map.put(num, true);
		}

		LinkedList<Integer> list = new LinkedList<>();
		for (int num : nums2) {
			if (map.get(num) != null) {
				map.remove(num);
				list.add(num);
			}
		}

		return list.stream().mapToInt(i -> i).toArray();
	}
}
