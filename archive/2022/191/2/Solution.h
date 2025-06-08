#pragma once

#include <cstdint>

class Solution
{
public:
    int hammingWeight(std::uint32_t n)
    {
        int result = 0;
        while (n) {
            n &= n - 1;
            ++result;
        }
        return result;
    }
};
