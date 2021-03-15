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
		root = insert(root, word.toCharArray(), 0);
	}

	private Node insert(Node x, char[] key, int d) {
		if (x == null) x = new Node();
		if (d == key.length) {
			x.val = true;
			return x;
		}
		int idx = key[d] - 'a';
		x.next[idx] = insert(x.next[idx], key, d + 1);
		return x;
	}

	public boolean search(String word) {
		Node x = search(root, word.toCharArray(), 0);
		return x == null ? false : x.val;
	}

	private Node search(Node x, char[] key, int d) {
		if (x == null || d == key.length) return x;
		return search(x.next[key[d] - 'a'], key, d + 1);
	}

	public boolean startsWith(String prefix) {
		Node x = search(root, prefix.toCharArray(), 0);
		return x != null;
	}
}
