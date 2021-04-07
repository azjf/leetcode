import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
	private List<List<Integer>> res = new LinkedList<>();

	public List<List<Integer>> permuteUnique(int[] nums) {
		Arrays.sort(nums);
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
			if (nums[i] == nums[lo] && i != lo) continue; // is nums[i] already at head? if so, there is no need to move (swap) it to head again, otherwise repeated results will be produced.
			swap(nums, lo, i);
			recur(Arrays.copyOf(nums, nums.length), lo + 1);
		}
	}

	private void swap(int[] nums, int i, int j) {
		int tmp = nums[i];
		nums[i] = nums[j];
		nums[j] = tmp;
	}
}
