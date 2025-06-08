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
    bool isSymmetric(TreeNode *root)
    {
        if (!root) {
            return true;
        }
        return recur(root->left, root->right);
    }

private:
    bool recur(TreeNode *l, TreeNode *r)
    {
        if (!l && !r) {
            return true;
        }
        if (!l || !r || l->val != r->val) {
            return false;
        }
        return recur(l->left, r->right) && recur(l->right, r->left);
    }
};

class Solution2
{
public:
    bool isSymmetric(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        q.push(root);
        q.push(root);
        while (!q.empty()) {
            auto l = q.front();
            q.pop();
            auto r = q.front();
            q.pop();
            if (!l && !r) {
                continue;
            }
            if (!l || !r || l->val != r->val) {
                return false;
            }
            q.push(l->left);
            q.push(r->right);
            q.push(l->right);
            q.push(r->left);
        }
        return true;
    }
};
