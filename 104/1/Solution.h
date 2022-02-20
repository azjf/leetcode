#include <vector>
#include "TreeNode.h"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return recur(root);
    }

private:
    int recur(const TreeNode *cur)
    {
        if (!cur) {
            return 0;
        }
        return 1 + std::max(recur(cur->left), recur(cur->right));
    }
};
