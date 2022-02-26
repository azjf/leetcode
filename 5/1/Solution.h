#pragma once

#include <string>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        int start = 0, max_len = 0;
        for (int i = 0; i != s.size(); ++i) {
            int len1 = extend(s, i, i);
            int len2 = extend(s, i, i + 1);
            int len = std::max(len1, len2);
            if (max_len < len) {
                start = i - (len - 1) / 2;
                max_len = len;
            }
        }
        return s.substr(start, max_len);
    }

private:
    int extend(const std::string &s, int l, int r)
    {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            --l;
            ++r;
        }
        return r - l - 1;
    }
};
