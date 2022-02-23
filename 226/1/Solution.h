#pragma once

#include <vector>
#include "TreeNode.h"

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        return recur(root);
    }

private:
    TreeNode *recur(TreeNode *cur)
    {
        if (!cur) {
            return cur;
        }
        TreeNode *tmp = cur->left;
        cur->left = recur(cur->right);
        cur->right = recur(tmp);
        return cur;
    }
};
