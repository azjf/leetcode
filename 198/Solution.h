#pragma once

#include <vector>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        // dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])
        int ppre = 0, pre = 0;
        for (const auto &n : nums) {
            int cur = std::max(ppre + n, pre);
            ppre = pre;
            pre  = cur;
        }
        return pre;
    }
};
