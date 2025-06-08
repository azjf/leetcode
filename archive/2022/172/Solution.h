#pragma once

#include <unordered_map>
#include <vector>

class Solution
{
public:
    int trailingZeroes(int n)
    {
        unsigned result = 0;
        while (n >= 5) {
            n /= 5;
            result += n;
        }
        return result;
    }
};
