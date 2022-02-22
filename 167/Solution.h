#pragma once

#include <vector>
#include <unordered_map>

class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &numbers, int target)
    {
        std::vector<int> result{-1, -1};
        decltype(numbers.size()) l = 0, r = numbers.size() - 1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum > target) {
                --r;
            } else if (sum < target) {
                ++l;
            } else {
                result = {(int) ++l, (int) ++r};
                break;
            }
        }
        return result;
    }
};
