#include <string>


/*
 * Trie
 */
class WordDictionary
{
public:
    void addWord(const std::string &word)
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

    bool search(const std::string &word) { return search(root, word, 0); }

private:
    struct Node
    {
        Node *next[26]{};
        bool val = false;
    };
    Node *root = new Node();

    bool search(Node *pre, const std::string &key, int depth)
    {
        if (!pre) {
            return false;
        }
        if (depth == key.size()) {
            return pre->val;
        }

        bool res = false;
        char c = key[depth];
        if (c == '.') {
            for (auto n : pre->next) {
                if (!n) {
                    continue;
                }
                res = res || search(n, key, depth + 1);
                if (res) {
                    break;
                }
            }
        } else {
            res = search(pre->next[c - 'a'], key, depth + 1);
        }
        return res;
    }

    bool search2(Node *pre, const std::string &key, int d)
    {
        for (; d != key.size(); ++d) {
            char c = key[d];
            if (c == '.') {
                bool res = false;
                for (auto n : pre->next) {
                    if (!n) {
                        continue;
                    }
                    res = res || search(n, key, d + 1);
                    if (res) {
                        break;
                    }
                }
                return res;
            } else {
                pre = pre->next[c - 'a'];
                if (!pre) {
                    return false;
                }
            }
        }
        return pre->val;
    }
};

int main()
{
    WordDictionary wd;
    wd.addWord("bad");
    wd.search(".ad");
    return 0;
}
