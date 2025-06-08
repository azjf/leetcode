#pragma once

class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        bool result = false;
        while (n) {
            if (n == 1) {
                result = true;
                break;
            }
            if (n & 3) {
                break;
            }
            n >>= 2;
        }
        return result;
    }
};
