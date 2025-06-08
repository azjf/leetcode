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

/*
 * Invert all nodes is all you need, i.e. tree traversal
 */
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        recur(root);
        return root;
    }

private:
    void recur(TreeNode *cur)
    {
        if (!cur) {
            return;
        }
        auto tmp = cur->left;
        cur->left = cur->right;
        cur->right = tmp;
        recur(cur->left);
        recur(cur->right);
    }
};

class Solution2
{
public:
    TreeNode *invertTree(TreeNode *root) { return recur(root); }

private:
    TreeNode *recur(TreeNode *cur)
    {
        if (!cur) {
            return cur;
        }
        auto tmp = cur->left;
        cur->left = recur(cur->right);
        cur->right = recur(tmp);
        return cur;
    }
};

class Solution3
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root) {
            return root;
        }
        std::queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            auto tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        return root;
    }
};
