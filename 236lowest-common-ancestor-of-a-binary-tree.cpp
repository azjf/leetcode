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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return recur(root, p, q);
    }

private:
    TreeNode *recur(TreeNode *cur, TreeNode *p, TreeNode *q)
    {
        if (!cur || cur == p || cur == q) { return cur; }
        auto l = recur(cur->left, p, q);
        auto r = recur(cur->right, p, q);
        // if p/q is found in both left and right trees, then cur is the lowest
        // common ancestor.
        return l && r ? cur : (l ? l : r);
    }
};


class Solution2
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        return recur(root, p, q);
    }

private:
    TreeNode *recur(TreeNode *cur, TreeNode *p, TreeNode *q)
    {
        if (!cur || cur == p || cur == q) {
            // p and q must be in the cur tree, so if cur == p/q, then cur must
            // be the lowest common ancestor
            return cur;
        }
        bool pFind = find(cur->left, p);  // TODO cache it
        bool qFind = find(cur->left, q);
        if (pFind && qFind) {
            return recur(cur->left, p, q);
        } else if (!pFind && !qFind) {
            return recur(cur->right, p, q);
        } else {
            return cur;
        }
    }

    bool find(TreeNode *cur, TreeNode *target)
    {
        if (!cur) { return false; }
        return cur == target
                   ? true
                   : (find(cur->left, target) || find(cur->right, target));
    }
};
