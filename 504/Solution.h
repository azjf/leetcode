#pragma once

#include <string>

class Solution
{
public:
    std::string convertToBase7(int num)
    {
        if (!num) {
            return "0";
        }

        std::string ans(num < 0 ? "-" : "");
        num = std::abs(num);

        std::string s;
        while (num) {
            s += '0' + (num % 7);
            num /= 7;
        }
        std::copy(s.crbegin(), s.crend(), std::back_inserter(ans));
        return ans;
    }
};
