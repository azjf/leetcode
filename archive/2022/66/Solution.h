#pragma once

#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int carry = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            carry += *it;
            *it = carry % 10;
            carry /= 10;
        }
        if (carry) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
