#include <stack>
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
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        recur(root);
        return res;
    }

private:
    std::vector<int> res;
    void recur(TreeNode *cur)
    {
        if (!cur) {
            return;
        }
        res.push_back(cur->val);
        recur(cur->left);
        recur(cur->right);
    }
};


class Solution2
{
public:
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        std::stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                res.push_back(cur->val);
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top(), stk.pop();
            cur = cur->right;
        }
        return res;
    }
};
