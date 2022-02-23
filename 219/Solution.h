#pragma once

#include <vector>
#include <unordered_map>

class Solution
{
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k)
    {
        bool result = false;
        std::unordered_map<int, decltype(nums.size())> m;
        for (decltype(nums.size()) i = 0; i != nums.size(); ++i) {
            if (m.count(nums[i]) && m[nums[i]] + k >= i) {
                result = true;
                break;
            }
            m[nums[i]] = i;
        }
        return result;
    }
};
