#pragma once

#include <array>


class Solution
{
public:
    bool isUgly(int n)
    {
        std::array<int, 3> ugly{2, 3, 5};

        for (const auto &u : ugly) {
            while (n >= u && n % u == 0) {
                n /= u;
            }
        }
        return n == 1;
    }
};
