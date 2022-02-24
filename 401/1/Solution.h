#pragma once

#include <vector>
#include <string>

class Solution
{
public:
    std::vector<std::string> readBinaryWatch(int turnedOn)
    {
        std::vector<std::string> ans;
        for (int i = 0; i != 12; ++i) {
            for (int j = 0; j != 64; ++j) {
                if (__builtin_popcount(i) + __builtin_popcount(j) == turnedOn) {
                    ans.push_back(std::to_string(i) + ":"
                            + (j < 10 ? "0" : "") + std::to_string(j));
                }
            }
        }
        return ans;
    }
};
