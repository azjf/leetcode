#pragma once

#include <queue>
#include "TreeNode.h"

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        std::queue<TreeNode *> q;
        if (!root) {
            return 0;
        }
        int result = 0;
        q.push(root);
        while (!q.empty()) {
            ++result;
            auto sz = q.size();
            for (decltype(sz) i = 0; i != sz; ++i) {
                auto cur = q.front();
                if (cur->left) {
                    q.push(cur->left);
                }
                if (cur->right) {
                    q.push(cur->right);
                }
                q.pop();
            }
        }
        return result;
    }
};
