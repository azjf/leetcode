import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<List<Integer>> ans;

	public List<List<Integer>> subsetsWithDup(int[] nums) {
		Arrays.sort(nums);
		ans = new LinkedList<>();
		recur(nums, 0, new LinkedList<Integer>());
		return ans;
	}

	private void recur(int[] nums, int lo, LinkedList<Integer> list) {
		ans.add(new LinkedList<Integer>(list));
		// append the effective nums to the list one by one
		// len(list)++
		for (int i = lo; i < nums.length; i++) {
			if (i > lo && nums[i] == nums[i - 1]) continue;
			list.add(nums[i]);
			recur(nums, i + 1, list);
			list.removeLast();
		}
	}
}
