#pragma once

#include <vector>

class Solution
{
public:
    bool checkPossibility(std::vector<int> &nums)
    {
        bool ret = true;
        bool is_first_round = true;
        for (decltype(nums.size()) i = 1; i != nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (is_first_round) {
                    is_first_round = false;
                    if (i >= 2 && nums[i] < nums[i - 2]) {
                        nums[i] = nums[i - 1];
                    }
                } else {
                    ret = false;
                    break;
                }
            }
        }
        return ret;
    }
};
