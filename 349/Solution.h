#pragma once

#include <vector>
#include <unordered_set>

class Solution
{
public:
    std::vector<int> intersection(std::vector<int> &nums1,
            std::vector<int> &nums2)
    {
        std::unordered_set<int> iset;
        for (const auto &n : nums1) {
            iset.insert(n);
        }

        std::vector<int> result;
        for (const auto &n : nums2) {
            if (iset.count(n)) {
                result.push_back(n);
                iset.erase(n);
            }
        }
        return result;
    }
};
