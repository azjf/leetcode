import java.util.Stack;

class MyQueue2 {
	private Stack<Integer> pushStack, popStack;

	public MyQueue2() {
		pushStack = new Stack<>();
		popStack = new Stack<>();
	}

	public void push(int x) {
		while (!popStack.isEmpty()) {
			pushStack.push(popStack.pop());
		}
		pushStack.push(x);
	}

	public int pop() {
		while (!pushStack.isEmpty()) {
			popStack.push(pushStack.pop());
		}
		return popStack.pop();
	}

	public int peek() {
		while (!pushStack.isEmpty()) {
			popStack.push(pushStack.pop());
		}
		return popStack.peek();
	}

	public boolean empty() {
		return pushStack.isEmpty() && popStack.isEmpty();
	}
}
