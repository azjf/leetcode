import java.util.LinkedList;
import java.util.List;

class Solution2 {
	private List<List<Integer>> res = new LinkedList<>();

	public List<List<Integer>> permute(int[] nums) {
		recur(nums, 0);
		return res;
	}

	private void recur(int[] nums, int lo) {
		if (lo == nums.length - 1) {
			LinkedList<Integer> list = new LinkedList<>();
			for (int i = 0; i < nums.length; i++) list.add(nums[i]);
			res.add(list);
			return;
		}
		for (int i = lo; i < nums.length; i++) {
			swap(nums, lo, i);
			recur(nums, lo + 1);
			swap(nums, lo, i);
		}
	}

	private void swap(int[] nums, int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}
