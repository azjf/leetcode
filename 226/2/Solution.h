#pragma once

#include <vector>
#include <queue>
#include "TreeNode.h"

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        if (root) {
            q.push(root);
        }
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            TreeNode *tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
            if (cur->left) {
                q.push(cur->left);
            }
            if (cur->right) {
                q.push(cur->right);
            }
        }
        return root;
    }
};
