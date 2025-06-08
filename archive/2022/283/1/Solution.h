#pragma once

#include <unordered_map>
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        decltype(nums.size()) l = 0, r = 0;
        for (; r != nums.size(); ++r) {
            if (nums[r]) {
                nums[l++] = nums[r];
            }
        }
        while (l != nums.size()) {
            nums[l++] = 0;
        }
    }
};
