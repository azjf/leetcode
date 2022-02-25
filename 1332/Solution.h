#pragma once

#include <string>

class Solution
{
public:
    int removePalindromeSub(std::string s)
    {
        if (s.empty()) {
            return 0;
        }
        return s == std::string(s.crbegin(), s.crend()) ? 1 : 2;
        //return isPalindromic(s) ? 1 : 2;
    }

private:
    bool isPalindromic(const std::string &s)
    {
        bool ret = true;
        auto l = s.cbegin(), r = s.cend() - 1;
        while (l < r) {
            if (*l++ != *r--) {
                ret = false;
                break;
            }
        }
        return ret;
    }
};
