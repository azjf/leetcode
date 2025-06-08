#include <string>

/*
 * Sedgewich R-way, p732, recursive
 */
class Trie
{
public:
    Trie() = default;

    void insert(const std::string &word) { root = put(root, word, 0); }

    bool search(const std::string &word)
    {
        Node *x = get(root, word, 0);
        return x ? x->val : false;
    }

    bool startsWith(const std::string &prefix)
    {
        Node *x = get(root, prefix, 0);
        return x;
    }

private:
    struct Node
    {
        Node *next[26]{};
        bool val = false;
    };
    Node *root = nullptr;

    /*
     * x is the parent/pre node for key[d].
     * root node is a dummy node because it can not differenciate between
     * different chars.
     */
    Node *put(Node *pre, const std::string &key, int d)
    {
        if (!pre) {
            pre = new Node();
        }
        if (d == key.size()) {
            pre->val = true;
            return pre;
        }
        int idx = key[d] - 'a';
        pre->next[idx] = put(pre->next[idx], key, d + 1);
        return pre;
    }

    Node *get(Node *pre, const std::string &key, int d)
    {
        if (!pre || d == key.size()) {
            return pre;
        }
        return get(pre->next[key[d] - 'a'], key, d + 1);
    }
};


/*
 * Sedgewich ternary search tries (TSTs), p746, recursive
 */
class Trie2
{
public:
    void insert(const std::string &word) { root = put(root, word, 0); }

    bool search(const std::string &word)
    {
        Node *x = get(root, word, 0);
        return x ? x->val : false;
    }

    bool startsWith(const std::string &prefix)
    {
        Node *x = get(root, prefix, 0);
        return x;
    }

private:
    struct Node
    {
        Node() = default;
        Node(char c) : c(c) {}
        Node *left = nullptr, *mid = nullptr, *right = nullptr;
        char c = 0;
        bool val = false;
    };
    Node *root = nullptr;

    /*
     * x is current node (not parent/pre node)
     */
    Node *put(Node *cur, const std::string &key, int d)
    {
        if (!cur) {
            cur = new Node(key[d]);
        }
        if (key[d] < cur->c) {
            cur->left = put(cur->left, key, d);
        } else if (key[d] > cur->c) {
            cur->right = put(cur->right, key, d);
        } else if (d != key.size() - 1) {
            cur->mid = put(cur->mid, key, d + 1);
        } else {
            cur->val = true;
        }
        return cur;
    }

    Node *get(Node *cur, const std::string &key, int d)
    {
        if (!cur) {
            return cur;
        }
        if (key[d] < cur->c) {
            return get(cur->left, key, d);
        } else if (key[d] > cur->c) {
            return get(cur->right, key, d);
        } else if (d != key.size() - 1) {
            return get(cur->mid, key, d + 1);
        } else {
            return cur;
        }
    }
};


/*
 * Sedgewich R-way, p732, non-recursive
 */
class Trie3
{
public:
    void insert(const std::string &word)
    {
        Node *pre = root;
        for (char c : word) {
            Node *&next = pre->next[c - 'a'];
            if (!next) {
                next = new Node();
            }
            pre = next;
        }
        pre->val = true;
    }

    bool search(const std::string &word)
    {
        Node *x = get(root, word);
        return x ? x->val : false;
    }

    bool startsWith(const std::string &prefix)
    {
        Node *x = get(root, prefix);
        return x;
    }

private:
    struct Node
    {
        Node *next[26]{};
        bool val = false;
    };
    Node *root = new Node();

    Node *get(Node *pre, const std::string &key)
    {
        for (char c : key) {
            if (!pre) {
                break;
            }
            pre = pre->next[c - 'a'];
        }
        return pre;
    }
};


/*
 * Sedgewich ternary search tries (TSTs), p746, non-recursive
 */
class Trie4
{
public:
    void insert(const std::string &word)
    {
        Node *cur = root;
        for (int i = 0; i != word.size();) {
            char c = word[i];
            if (c < cur->c) {
                if (!cur->left) {
                    cur->left = new Node(c);
                }
                cur = cur->left;
            } else if (c > cur->c) {
                if (!cur->right) {
                    cur->right = new Node(c);
                }
                cur = cur->right;
            } else if (++i != word.size()) {
                if (!cur->mid) {
                    cur->mid = new Node(word[i]);  // not c
                }
                cur = cur->mid;
            } else {
                cur->val = true;
                break;
            }
        }
    }

    bool search(const std::string &word)
    {
        Node *x = get(root, word);
        return x ? x->val : false;
    }

    bool startsWith(const std::string &prefix)
    {
        Node *x = get(root, prefix);
        return x;
    }

private:
    struct Node
    {
        Node() = default;
        Node(char c) : c(c) {}
        Node *left = nullptr, *mid = nullptr, *right = nullptr;
        char c = 0;
        bool val = false;
    };
    Node *root = new Node();

    Node *get(Node *cur, const std::string &key)
    {
        for (int i = 0; i != key.size();) {
            if (!cur) {
                break;
            }
            if (key[i] < cur->c) {
                cur = cur->left;
            } else if (key[i] > cur->c) {
                cur = cur->right;
            } else if (++i != key.size()) {
                cur = cur->mid;
            } else {
                return cur;
            }
        }
        return nullptr;
    }
};


int main()
{
    int a = 1, b = 2;
    int *pa = &a, *&pb = pa;
    pb = &b;

    Trie3 trie3;
    trie3.insert("apple");
    trie3.search("apple");
    return 0;
}
