#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        int carry = 1;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            int &d = *it;
            d += carry;
            if (d == 10) {
                carry = 1;
                d = 0;
            } else {
                carry = 0;
                break;
            }
        }
        if (carry) {
            digits.insert(digits.cbegin(), 1);
        }
        return digits;
    }
};

int main()
{
    Solution s;

    std::vector<int> digits = {1, 2, 3};
    std::vector<int> res = s.plusOne(digits);
    for (int n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    digits = {4, 3, 2, 1};
    res = s.plusOne(digits);
    for (int n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    digits = {0};
    res = s.plusOne(digits);
    for (int n : res) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}
