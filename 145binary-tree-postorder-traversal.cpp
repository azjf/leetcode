#include <algorithm>
#include <stack>
#include <type_traits>
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
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        recur(root);
        return res;
    };

private:
    std::vector<int> res;
    void recur(TreeNode *cur)
    {
        if (!cur) { return; }
        recur(cur->left);
        recur(cur->right);
        res.push_back(cur->val);
    }
};


class Solution2
{
public:
    std::vector<int> postorderTraversal(TreeNode *root)
    {
        std::vector<int> res;
        std::stack<TreeNode *> stk;
        TreeNode *cur = root, *last = nullptr;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            if (cur->right && cur->right != last) {
                // right subtree has not been handled
                cur = cur->right;
            } else {
                stk.pop();
                res.push_back(cur->val);
                last = cur;
                cur = nullptr;
            }
        }
        return res;
    };
};
