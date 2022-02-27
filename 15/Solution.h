#pragma once

#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < (int ) nums.size() - 2; ++i) {
            if (i && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (!sum) {
                    ret.push_back({nums[i], nums[l], nums[r]});
                }
                if (sum <= 0) {
                    ++l;
                    while (l > r && nums[l] == nums[l - 1]) {
                        ++l;
                    }
                }
                if (sum >= 0) {
                    --r;
                    while (r > l && nums[r] == nums[r + 1]) {
                        --r;
                    }
                }
            }
        }
        return ret;
    }
};
