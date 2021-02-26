import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

class Solution {
	public List<List<Integer>> threeSum(int[] nums) {
		Arrays.sort(nums);
		List<List<Integer>> ans = new LinkedList<>();
		for (int i = 0; i < nums.length - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (int j = i + 1, k = nums.length - 1; j < k;) {
				int sum = nums[i] + nums[j] + nums[k];
				if (sum == 0) {
					List<Integer> list = new LinkedList<>(Arrays.asList(nums[i], nums[j], nums[k]));
					ans.add(list);
				}
				if (sum <= 0) {
					while (j < k && nums[j] == nums[j + 1]) j++;
					j++;
				}
				if (sum >= 0) {
					while (j < k && nums[k] == nums[k - 1]) k--;
					k--;
				}
			}
		}
		return ans;
	}
}
