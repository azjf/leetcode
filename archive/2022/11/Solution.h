#pragma once

#include <vector>

class Solution
{
public:
    int maxArea(std::vector<int> &height)
    {
        int ret = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            ret = std::max(ret, std::min(height[l], height[r]) * (r - l));
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ret;
    }
};
