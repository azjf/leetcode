#include <queue>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(right), right(right)
    {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root) { return recur(root); }

private:
    int recur(TreeNode *cur)
    {
        if (!cur) {
            return 0;
        }
        return 1 + std::max(recur(cur->left), recur(cur->right));
    }
};

class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root) {
            return 0;
        }

        std::queue<TreeNode *> q;
        q.push(root);
        int res = 0;
        while (!q.empty()) {
            ++res;
            auto sz = q.size();
            for (auto i = 0; i != sz; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
        }
        return res;
    }
};
