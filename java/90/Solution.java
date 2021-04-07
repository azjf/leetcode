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
		if (lo == nums.length) {
			ans.add(new LinkedList<Integer>(list));
			return;
		}
		int hi = lo;
		for (; hi < nums.length && nums[hi] == nums[lo]; hi++);
		for (int i = lo; i < hi + 1; i++) {
			for (int j = lo; j < i; j++) list.add(nums[lo]);
			recur(nums, hi, list);
			for (int j = lo; j < i; j++) list.removeLast();
		}
	}
}
