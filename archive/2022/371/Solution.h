#pragma once

class Solution
{
public:
    int getSum(int a, int b)
    {
        if (a == 0) {
            return b;
        }
        while (b) {
            int carry = (unsigned) (a & b) << 1;
            a ^= b;
            b = carry;
        }
        return a;
    }
};
