#pragma once

#include <algorithm>
#include <vector>

class Solution
{
public:
    int findContentChildren(std::vector<int> &g, std::vector<int> &s)
    {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());

        int ans = 0;
        auto it_g = g.cbegin(), it_s = s.cbegin();
        while (it_g != g.cend() && it_s != s.cend()) {
            if (*it_g <= *it_s) {
                ++ans;
                ++it_g;
            }
            ++it_s;
        }
        return ans;
    }
};
