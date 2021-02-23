import java.util.Stack;

class MinStack {
	private Stack<Integer> dataStack;
	private Stack<Integer> minStack;

	public MinStack() {
		dataStack = new Stack<>();
		minStack = new Stack<>();
	}

	public void push(int x) {
		dataStack.push(x);
		if (minStack.isEmpty() || x <= minStack.peek()) minStack.push(x);
	}

	public void pop() {
		int top = dataStack.pop();
		if (top == minStack.peek()) minStack.pop();
	}

	public int top() {
		return dataStack.peek();
	}

	public int getMin() {
		return minStack.peek();
	}
}
