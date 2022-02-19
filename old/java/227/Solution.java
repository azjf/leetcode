import java.util.Stack;

class Solution {
	public int calculate(String s) {
		Stack<Integer> stack = new Stack<>();
		int num = 0;
		char preOpt = '+';
		for (char c : (s + "$").toCharArray()) {
			if (c == ' ') {
				continue;
			} else if (Character.isDigit(c)) {
				num = 10 * num + c - '0';
			} else {
				if (preOpt == '+') {
					stack.push(num);
				} else if (preOpt == '-') {
					stack.push(-num);
				} else if (preOpt == '*') {
					stack.push(stack.pop() * num);
				} else if (preOpt == '/') {
					stack.push(stack.pop() / num);
				}
				num = 0;
				preOpt = c;
			}
		}

		int ans = 0;
		for (int n : stack) ans += n;
		return ans;
	}
}
