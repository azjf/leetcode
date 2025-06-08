#pragma once

#include <map>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == -2147483648) {
            return dividend == -2147483648 ? 1 : 0;
        }
        if (dividend == -2147483648) {
            if (divisor == -1) {
                return 2147483647;
            }
            if (divisor == 1) {
                return -2147483648;
            }
            int abs_divisor = divisor > 0 ? divisor : -divisor;
            auto ret = pos_divide(2147483647, abs_divisor);
            if (ret.second + 1 == abs_divisor) {
                ++ret.first;
            }
            return divisor > 0 ? -ret.first : ret.first;
        }

        bool pos1 = dividend > 0, pos2 = divisor > 0, pos = !(pos1 ^ pos2);
        if (!pos1) {
            dividend = -dividend;
        }
        if (!pos2) {
            divisor = -divisor;
        }
        auto ret = pos_divide(dividend, divisor);
        return pos ? ret.first : -ret.first;
    }

private:
    std::pair<int, int> pos_divide(int dividend, int divisor)
    {
        // power = divisor * 2^n
        int n = 0, power = divisor;
        while (power <= dividend >> 1) {
            power += power;
            ++n;
        }

        int q = 0, r = dividend;
        while (r && n >= 0) {
            if (power <= r) {
                r -= power;
                q |= 1 << n;
            }
            power >>= 1;
            --n;
        }
        return {q, r};
    }
};
