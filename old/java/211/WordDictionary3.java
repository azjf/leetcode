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
		Node x = root;
		for (int i = 0; i < word.length(); i++) {
			char c = word.charAt(i);
			if (c == '.') {
				boolean res = false;
				for (int j = 0; j < x.next.length; j++) {
					if (res) return true;
					if (x.next[j] != null) res =
						res || search(word.substring(0, i) + (char)('a' + j) + word.substring(i + 1));
				}
				return res;
			} else {
				x = x.next[c - 'a'];
				if (x == null) return false;
			}
		}
		return x.val;
	}
}
