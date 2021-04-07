import java.util.HashSet;

class Solution {
	public int distributeCandies(int[] candyType) {
		HashSet<Integer> set = new HashSet<>();
		for (int c : candyType) {
			set.add(c);
		}
		return set.size() <= candyType.length / 2 ? set.size() : candyType.length / 2;
	}
}
