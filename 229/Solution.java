import java.util.LinkedList;
import java.util.List;

class Solution {
	public List<Integer> majorityElement(int[] nums) {
		int c1 = 0, c2 = 0, v1 = -1, v2 = -2;
		// two nums: 1 - >1/3 - >1/3 < 1/3
		// one num: (1 - >1/3) / 2 < 1/3
		for (int num : nums) {
			if (num == v1) {
				c1++;
			} else if (num == v2) {
				c2++;
			} else if (c1 == 0) {
				v1 = num;
				c1++;
			} else if (c2 == 0) {
				v2 = num;
				c2++;
			} else {
				c1--;
				c2--;
			}
		}

		c1 = 0;
		c2 = 0;
		for (int num : nums) {
			if (num == v1) c1++;
			if (num == v2) c2++;
		}

		List<Integer> ans = new LinkedList<>();
		if (c1 > nums.length / 3) ans.add(v1);
		if (c2 > nums.length / 3) ans.add(v2);
		return ans;
	}
}
