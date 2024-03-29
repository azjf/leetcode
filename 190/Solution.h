#pragma once

#include <cstdint>

class Solution
{
public:
    std::uint32_t reverseBits(std::uint32_t n)
    {
        std::uint32_t result = 0;
        for (int i = 0; i != 32; ++i) {
            result = (result << 1) | (n & 1);
            n >>= 1;
        }
        return result;
    }
};
