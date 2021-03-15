class Trie {
	private Node root;

	private class Node {
		char c;
		boolean val;
		Node left, mid, right;
	}

	public Trie() {
		root = new Node();
	}

	public void insert(String word) {
		root = insert(root, word.toCharArray(), 0);
	}

	private Node insert(Node x, char[] key, int d) {
		if (x == null) {
			x = new Node();
			x.c = key[d];
		}
		if (key[d] < x.c) {
			x.left = insert(x.left, key, d);
		} else if (key[d] > x.c) {
			x.right = insert(x.right, key, d);
		} else if (d < key.length - 1) {
			x.mid = insert(x.mid, key, d + 1);
		} else {
			x.val = true;
		}
		return x;
	}

	public boolean search(String word) {
		Node x = search(root, word.toCharArray(), 0);
		return x == null ? false : x.val;
	}

	private Node search(Node x, char[] key, int d) {
		if (x == null) return null;
		if (key[d] < x.c) {
			return search(x.left, key, d);
		} else if (key[d] > x.c) {
			return search(x.right, key, d);
		} else if (d < key.length - 1) {
			return search(x.mid, key, d + 1);
		} else {
			return x;
		}
	}

	public boolean startsWith(String prefix) {
		Node x = search(root, prefix.toCharArray(), 0);
		return x != null;
	}
}
