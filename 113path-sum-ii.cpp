#include <functional>
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
    std::vector<std::vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        recur(root, targetSum);
        return res;
    }

private:
    std::vector<std::vector<int>> res;
    std::vector<int> ivec;

    void recur(TreeNode *cur, int sum)
    {
        if (!cur) {
            return;
        }
        ivec.push_back(cur->val);
        if (cur->val == sum && !cur->left && !cur->right) {
            res.push_back(ivec);
        } else {
            recur(cur->left, sum - cur->val);
            recur(cur->right, sum - cur->val);
        }
        ivec.pop_back();
    }
};
