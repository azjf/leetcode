#pragma once

#include <string>
#include <vector>

class Solution
{
public:
    std::vector<int> shortestToChar(std::string s, char c)
    {
        std::vector<int> ret(s.size(), -10000);
        int l = -s.size();
        for (decltype(s.size()) i = 0; i != s.size(); ++i) {
            if (s[i] == c) {
                l = i;
            }
            ret[i] = i - l;
        }
        int r = s.size() * 2;
        for (decltype(s.size()) i = s.size() - 1; i != -1; --i) {
            if (s[i] == c) {
                r = i;
            }
            ret[i] = std::min(ret[i], r - (int) i);
        }
        return ret;
    }
};
