#pragma once

#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        if (nums.empty()) {
            return -1;
        }
        int sum = 0, min_sum = 0, result = nums[0];
        for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            result = std::max(result, sum - min_sum);
            min_sum = std::min(min_sum, sum);
        }
        return result;
    }
};
