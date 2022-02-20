#include <vector>
#include "TreeNode.h"

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root) {
            return true;
        }
        return recur(root->left, root->right);
    }

private:
    bool recur(const TreeNode *l, const TreeNode *r)
    {
        if (!l && !r) {
            return true;
        } else if (!l || !r || l->val != r->val) {
            return false;
        }
        return recur(l->left, r->right) && recur(l->right, r->left);
    }
};
