#pragma once

#include <vector>
#include "TreeNode.h"

class Solution
{
public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        return recur(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *recur(const std::vector<int> &nums, int l, int r)
    {
        if (l > r) {
            return nullptr;
        }
        int mid = l + (r - l) / 2;
        return new TreeNode(nums[mid], recur(nums, l, mid - 1),
                recur(nums, mid + 1, r));
    }
};
