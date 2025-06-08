#pragma once

#include <unordered_map>
#include <vector>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, decltype(nums.size())> m;
        std::vector<int> result;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            int x = nums[i], y = target - x;
            if (m.find(y) != m.cend()) {
                result = {(int) m[y], (int) i};
                break;
            } else {
                m[x] = i;
            }
        }
        return result;
    }
};
