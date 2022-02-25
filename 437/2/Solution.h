#pragma once

#include <unordered_map>
#include "TreeNode.h"

class Solution
{
public:
    int pathSum(TreeNode *root, int targetSum)
    {
        return dfs(root, targetSum, 0);
    }

private:
    std::unordered_map<int, int> prefix{ {0, 1} };

    int dfs(TreeNode *cur, int targetSum, int sum)
    {
        if (!cur) {
            return 0;
        }

        sum += cur->val;

        int cnt = 0;
        if (prefix.count(sum - targetSum)) {
            cnt += prefix[sum - targetSum];
        }

        ++prefix[sum];
        cnt += dfs(cur->left, targetSum, sum);
        cnt += dfs(cur->right, targetSum, sum);
        --prefix[sum];
        return cnt;
    }
};
