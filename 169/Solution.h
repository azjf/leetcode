#pragma once

#include <vector>
#include <unordered_map>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int result = 0, cnt = 0;
        for (const auto &n : nums) {
            if (n == result) {
                ++cnt;
            } else {
                if (cnt) {
                    --cnt;
                } else {
                    result = n;
                    cnt = 0;
                }
            }
        }
        return result;
    }
};
