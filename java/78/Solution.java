import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<List<Integer>> ans;

	public List<List<Integer>> subsets(int[] nums) {
		ans = new LinkedList<>();
		recur(nums, 0, new LinkedList<Integer>());
		return ans;
	}

	private void recur(int[] nums, int lo, LinkedList<Integer> list) {
		if (lo == nums.length) {
			ans.add(new LinkedList<Integer>(list));
			return;
		}
		recur(nums, lo + 1, list);  // do not use num[i]
		list.add(nums[lo]);  // use num[i]
		recur(nums, lo + 1, list);
		list.removeLast();
	}
}
