class Trie {
	private Node root;

	private class Node {
		boolean val;
		Node[] next = new Node[26];
	}

	public Trie() {
		root = new Node();
	}

	public void insert(String word) {
		Node x = root;
		for (char c : word.toCharArray()) {
			int idx = c - 'a';
			if (x.next[idx] == null) x.next[idx] = new Node();
			x = x.next[idx];
		}
		x.val = true;
	}

	public boolean search(String word) {
		Node x = root;
		for (char c : word.toCharArray()) {
			int idx = c - 'a';
			x = x.next[idx];
			if (x == null) return false;
		}
		return x.val;
	}

	public boolean startsWith(String prefix) {
		Node x = root;
		for (char c : prefix.toCharArray()) {
			int idx = c - 'a';
			x = x.next[idx];
			if (x == null) return false;
		}
		return true;
	}
}
