#pragma once

#include <vector>
#include <unordered_map>

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
