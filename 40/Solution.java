import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<List<Integer>> res = new LinkedList<>();

	public List<List<Integer>> combinationSum2(int[] candidates, int target) {
		if (candidates == null || candidates.length == 0) return res;
		Arrays.sort(candidates);
		recur(candidates, target, 0, new LinkedList<Integer>());
		return res;
	}

	private void recur(int[] nums, int target, int lo, LinkedList<Integer> list) {
		if (target == 0) {
			res.add(new LinkedList<Integer>(list));
			return;
		}
		for (int i = lo; i < nums.length && nums[i] <= target; i++) {
			//if (i != lo && nums[i] == nums[i - 1]) continue;
			list.add(nums[i]);
			recur(nums, target - nums[i], i + 1, list);
			while (i + 1 < nums.length && nums[i] == nums[i + 1]) i++;
			list.removeLast();
		}
	}
}
