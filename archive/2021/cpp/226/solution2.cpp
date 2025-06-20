#include <queue>


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right)
    {}
};


class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        if (root) q.push(root);
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
            std::swap(cur->left, cur->right);
        }
        return root;
    }
};
