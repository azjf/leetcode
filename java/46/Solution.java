import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<List<Integer>> res = new LinkedList<>();

	public List<List<Integer>> permute(int[] nums) {
		recur(nums, 0, new LinkedList<Integer>());
		return res;
	}

	private void recur(int[] nums, int lo, List<Integer> list) {
		if (lo == nums.length) {
			res.add(new LinkedList<Integer>(list));
			return;
		}
		for (int i = 0; i <= list.size(); i++) {
			list.add(i, nums[lo]);
			recur(nums, lo + 1, list);
			list.remove(i);
		}
	}
}
