#pragma once

#include <vector>

class Solution
{
public:
    int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes)
    {
        std::vector<int> count(100, 0);
        int ret = 0;
        for (const auto &d : dominoes) {
            int key = d[0] < d[1] ? d[0] * 10 + d[1] : d[1] * 10 + d[0];
            ret += count[key];
            ++count[key];
        }
        return ret;
    }
};
