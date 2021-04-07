class WordDictionary {
	Node root;
	
	private class Node {
		boolean val;
		Node[] next = new Node[26];
	}

	public WordDictionary() {
		root = new Node();
	}

	public void addWord(String word) {
		Node x = root;
		for (char c : word.toCharArray()) {
			int idx = c - 'a';
			if (x.next[idx] == null) x.next[idx] = new Node();
			x = x.next[idx];
		}
		x.val = true;
	}

	public boolean search(String word) {
		return search(root, word, 0);
	}

	private boolean search(Node x, String word, int d) {
		if (d == word.length()) return x.val;
		char c = word.charAt(d);
		if (c == '.') {
			boolean res = false;
			for (Node n : x.next) {
				if (res) return true;
				if (n != null) res = res || search(n, word, d + 1);
			}
			return res;
		} else {
			x = x.next[c - 'a'];
			return x == null ? false : search(x, word, d + 1);
		}
	}
}
