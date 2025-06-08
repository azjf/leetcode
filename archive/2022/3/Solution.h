#pragma once

#include <string>
#include <unordered_map>
#include <vector>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_map<char, int> m;
        int ret = 0;
        for (int l = 0, r = 0; r != s.size(); ++r) {
            if (m.count(s[r]) && m[s[r]] >= l) {
                l = m[s[r]] + 1;
            }
            m[s[r]] = r;
            ret = std::max(ret, r - l + 1);
        }
        return ret;
    }
};
