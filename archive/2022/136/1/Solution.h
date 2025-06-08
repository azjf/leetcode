#pragma once

#include <vector>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        int result = 0;
        for (const auto &n : nums) {
            result ^= n;
        }
        return result;
    }
};
