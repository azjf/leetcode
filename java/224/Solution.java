import java.util.Stack;

class Solution {
	public int calculate(String s) {
		return recur((s + "$").toCharArray(), 0)[0];
	}

	int[] recur(char[] chs, int d) {
		Stack<Integer> stack = new Stack<>();
		int num = 0;
		int preOpt = '+';
		while (d < chs.length) {
			char c = chs[d++];  // d points to the next char
			if (c == ' ') {
				continue;
			} else if (c == '(') {
				int[] res = recur(chs, d);
				num = res[0];
				d = res[1];  // d points to the next char
			} else if (c >= '0' && c <= '9') {
				num = num * 10 + c - '0';
			} else {
				if (preOpt == '+') {
					stack.push(num);
				} else if (preOpt == '-') {
					stack.push(-num);
				/*} else if (preOpt == '*') {
					stack.push(stack.pop() * num);
				} else if (preOpt == '/') {
					stack.push(stack.pop() / num);*/
				}
				if (c == ')') break;  // d points to the next char
				num = 0;
				preOpt = c;
			}
		}

		int sum = 0;
		for (int x : stack) sum += x;
		return new int[] { sum, d };
	}
}
