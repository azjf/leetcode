import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

class Solution {
	public List<List<String>> groupAnagrams(String[] strs) {
		HashMap<String, List<String>> map = new HashMap<>();
		for (String str : strs) {
			int[] bucket = new int[26];
			for (char ch : str.toCharArray()) {
				bucket[ch - 'a'] += 1;
			}
			String key = Arrays.toString(bucket);
			if (!map.containsKey(key)) {
				List<String> list = new LinkedList<String>();
				list.add(str);
				map.put(key, list);
			} else {
				map.get(key).add(str);
			}
		}
		return new LinkedList<List<String>>(map.values());
	}
}
