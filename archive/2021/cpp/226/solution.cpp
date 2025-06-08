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
    TreeNode *invertTree(TreeNode *root) { return recur(root); }

private:
    TreeNode *recur(TreeNode *cur)
    {
        if (!cur) return nullptr;
        TreeNode *tmp = cur->left;
        cur->left = recur(cur->right);
        cur->right = recur(tmp);
        return cur;
    }
};
