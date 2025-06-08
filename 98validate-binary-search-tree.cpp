#include <limits>
#include <list>
#include <stack>

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
 * in-order traversal
 */
class Solution
{
public:
    bool isValidBST(TreeNode *root) { return recur(root); }

private:
    TreeNode *pre = nullptr;  // pre is the node before cur in the in-order,
                              // which may be a parent node or a right node
    bool recur(TreeNode *cur)
    {
        if (!cur) {
            return true;
        }
        if (!recur(cur->left)) {  // in-order traversal to set *pre* correctly
            return false;
        }
        if (pre && cur->val <= pre->val) {
            return false;
        }
        pre = cur;
        return recur(cur->right);
    }
};


/*
 * non-recursive version of Solution
 */
class Solution2
{
public:
    bool isValidBST(TreeNode *root)
    {
        TreeNode *cur = root, *pre = nullptr;
        std::stack<TreeNode *> stk;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top(), stk.pop();
            if (pre && cur->val <= pre->val) {
                return false;
            }
            pre = cur;
            cur = cur->right;
        }
        return true;
    }
};


class Solution3
{
public:
    bool isValidBST(TreeNode *root)
    {
        return recur(root, std::numeric_limits<long>::min(),
                     std::numeric_limits<long>::max());
    }

private:
    bool recur(TreeNode *cur, long min, long max)
    {
        if (!cur) {
            return true;
        }
        if (cur->val <= min || cur->val >= max) {
            return false;
        }
        return recur(cur->left, min, cur->val) &&
               recur(cur->right, cur->val, max);
    }
};
