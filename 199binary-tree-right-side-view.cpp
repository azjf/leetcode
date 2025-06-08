#include <queue>
#include <vector>

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
    std::vector<int> rightSideView(TreeNode *root)
    {
        std::vector<int> res;
        std::queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i != sz; ++i) {
                TreeNode *cur = q.front();
                q.pop();
                if (i == sz - 1) {
                    res.push_back(cur->val);
                }
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
            }
            TreeNode *cur = q.front();
        }
        return res;
    }
};
