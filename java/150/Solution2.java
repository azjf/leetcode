import java.util.Stack;

class Solution {
	public int evalRPN(String[] tokens) {
		int[] stack = new int[tokens.length / 2 + 1];
		int idx = 0;
		for (String token : tokens) {
			if (token.equals("+")) {
				stack[idx - 2] += stack[--idx];
			} else if (token.equals("-")) {
				stack[idx - 2] -= stack[--idx];
			} else if (token.equals("*")) {
				stack[idx - 2] *= stack[--idx];
			} else if (token.equals("/")) {
				stack[idx - 2] /= stack[--idx];
			} else {
				stack[idx++] = Integer.parseInt(token);
			}
		}
		return stack[0];
	}
}
