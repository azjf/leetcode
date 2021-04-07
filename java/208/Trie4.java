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
		Node x = root;
		for (int i = 0; i < word.length();) {
			char c = word.charAt(i);
			if (c < x.c) {
				if (x.left == null) {
					Node node = new Node();
					node.c = c;
					x.left = node;
				}
				x = x.left;
			} else if (c > x.c) {
				if (x.right == null) {
					Node node = new Node();
					node.c = c;
					x.right = node;
				}
				x = x.right;
			} else if (i < word.length() - 1) {
				if (x.mid == null) {
					Node node = new Node();
					node.c = word.charAt(i + 1);  // not word.charAt(i)
					x.mid = node;
				}
				x = x.mid;
				i++;
			} else {
				x.val = true;
				break;
			}
		}
	}

	public boolean search(String word) {
		Node x = root;
		for (int i = 0; i < word.length();) {
			char c = word.charAt(i);
			if (c < x.c) {
				x = x.left;
			} else if (c > x.c) {
				x = x.right;
			} else if (i < word.length() - 1) {
				x = x.mid;
				i++;
			} else {
				break;
			}
			if (x == null) return false;
		}
		return x.val;
	}

	public boolean startsWith(String prefix) {
		Node x = root;
		for (int i = 0; i < prefix.length();) {
			char c = prefix.charAt(i);
			if (c < x.c) {
				x = x.left;
			} else if (c > x.c) {
				x = x.right;
			} else if (i < prefix.length() - 1) {
				x = x.mid;
				i++;
			} else {
				break;
			}
			if (x == null) return false;
		}
		return true;
	}
}
