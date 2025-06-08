#pragma once

#include <cstdint>

class Solution
{
public:
    int hammingWeight(std::uint32_t n)
    {
        int result = 0;
        while (n) {
            result += n & 1;
            n >>= 1;
        }
        return result;
    }
};
