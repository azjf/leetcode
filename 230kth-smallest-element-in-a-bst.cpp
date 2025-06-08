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
    int kthSmallest(TreeNode *root, int k)
    {
        recur(root, k);
        return res;
    }

private:
    int cnt = 0, res = 0;
    void recur(TreeNode *cur, int k)
    {
        if (!cur) { return; }
        recur(cur->left, k);
        if (++cnt == k) {
            res = cur->val;
            return;
        }
        recur(cur->right, k);
    }
};


class Solution2
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        int cnt = 0;
        std::stack<TreeNode *> stk;
        TreeNode *cur = root;
        while (cur || !stk.empty()) {
            while (cur) {
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if (++cnt == k) { return cur->val; }
            cur = cur->right;
        }
        return -1;
    }
};


class Solution3
{
public:
    int kthSmallest(TreeNode *root, int k) { return recur(root, k); }

private:
    int recur(TreeNode *root, int k)
    {
        int l = count(root->left);
        if (l == k - 1) {
            return root->val;
        } else if (l < k - 1) {
            return recur(root->right, k - l - 1);
        } else {
            return recur(root->left, k);
        }
    }

    int count(TreeNode *cur)
    {
        // TODO cache count in a map
        return cur ? 1 + count(cur->left) + count(cur->right) : 0;
    }
};
