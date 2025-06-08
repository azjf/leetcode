#include <algorithm>


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
    int maxDepth(TreeNode *root) { return recur(root); }

private:
    int recur(TreeNode *cur)
    {
        if (!cur) return 0;
        return 1 + std::max(recur(cur->left), recur(cur->right));
    }
};
