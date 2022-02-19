import java.util.Arrays;
import java.util.HashSet;
import java.util.List;

class Solution {
	public int robotSim(int[] commands, int[][] obstacles) {
		HashSet<List<Integer>> set = new HashSet<>();
		for (int[] o : obstacles) {
			set.add(Arrays.asList(o[0], o[1]));
		}

		int dist = 0, dir = 1;
		int[] pos = { 0, 0 };
		for (int c : commands) {
			if (c < 0) {
				dir = (dir + (c == -2 ? 1 : 4 - 1)) % 4;
				continue;
			}

		switch (dir) {
				case 0:
					for (int i = 0; i < c && !set.contains(Arrays.asList(pos[0] + 1, pos[1])); i++) pos[0]++;
					break;
				case 1:
					for (int i = 0; i < c && !set.contains(Arrays.asList(pos[0], pos[1] + 1)); i++) pos[1]++;
					break;
				case 2:
					for (int i = 0; i < c && !set.contains(Arrays.asList(pos[0] - 1, pos[1])); i++) pos[0]--;
					break;
				case 3:
					for (int i = 0; i < c && !set.contains(Arrays.asList(pos[0], pos[1] - 1)); i++) pos[1]--;
					break;
			}
			dist = Math.max(dist, pos[0] * pos[0] + pos[1] * pos[1]);
		}
		return dist;
	}
}
