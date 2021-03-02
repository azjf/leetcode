import java.util.ArrayList;

class Solution {
	public String getPermutation(int n, int k) {
		int fact = 1;
		for (int i = 2; i < n; i++) fact *= i;

		ArrayList<Character> charset = new ArrayList<>();
		for (int i = 0; i < n; i++) charset.add((char) ('1' + i));

		k--;
		StringBuilder ans = new StringBuilder();
		boolean[] marked = new boolean[n];
		for (int i = n - 1; i >= 0; i--) {
			if (k == 0) {
				for (char ch : charset) ans.append(ch);
				break;
			}

			int idx = k / fact;
			ans.append(charset.get(idx));
			charset.remove(idx);
			k = k % fact;
			fact /= i;
			//System.out.println(k + " " + fact);
		}
		return ans.toString();
	}

	public static void main(String[] args) {
		System.out.println((new Solution()).getPermutation(3, 4));
	}
}
