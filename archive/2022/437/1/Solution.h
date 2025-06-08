#pragma once

#include <vector>
#include "TreeNode.h"

class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        int cnt = 0;
        backtrack(root, targetSum, cnt);
        return cnt;
    }

private:
    void backtrack(TreeNode *cur, int sum, int &cnt)
    {
        if (!cur) {
            return;
        }
        backtrack(cur->left, sum, cnt);
        backtrack(cur->right, sum, cnt);
        helper(cur, sum, cnt);
    }

    void helper(TreeNode *cur, int sum, int &cnt)
    {
        if (!cur) {
            return;
        }
        if (cur->val == sum) {
            ++cnt;
        }
        helper(cur->left, sum - cur->val, cnt);
        helper(cur->right, sum - cur->val, cnt);
    }
};
