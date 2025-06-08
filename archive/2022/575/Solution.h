#pragma once

#include <set>
#include <vector>

class Solution
{
public:
    int distributeCandies(std::vector<int> &candyType)
    {
        std::set<int> uniqCandyType;
        for (const auto &c : candyType) {
            uniqCandyType.insert(c);
        }
        return std::min(candyType.size() / 2, uniqCandyType.size());
    }
};
