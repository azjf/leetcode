#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>

/*
 * dividend = divisor * (2^0 + 2^1 + ...)
 */
class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        bool pos1 = dividend > 0, pos2 = divisor > 0, pos = !(pos1 ^ pos2);
        auto res = posDiv(pos1 ? dividend : -(long) dividend,
                          pos2 ? divisor : -(long) divisor);
        return pos ? std::min(res.first, (1U << 31) - 1) : -res.first;
    }

private:
    std::pair<unsigned, unsigned> posDiv(unsigned dividend, unsigned divisor)
    {
        unsigned power = 1;
        while (divisor <= dividend >> 1) {
            divisor <<= 1;
            power <<= 1;
        }
        unsigned q = 0;
        while (dividend && power) {
            if (divisor <= dividend) {
                dividend -= divisor;
                q |= power;
            }
            divisor >>= 1;
            power >>= 1;
        }
        return {q, dividend};
    }
};

int main()
{
    int a1 =
        -std::pow(2, 31);  // typename __gnu_cxx::__promote_2<_Tp, _Up>::__type
    int a2 = std::abs(a1);
    long a3 = std::abs((long) a1);
    std::cout << a1 << " " << a2 << " " << a3 << std::endl;
    unsigned u = 1U << 31;
    std::cout << u << " " << (u <= 0) << std::endl;
    std::cout << Solution().divide(10, 3) << std::endl;
    // std::cout << Solution().divide(-2147483648, -1) << std::endl;
    // std::cout << Solution().divide(2147483647, 3) << std::endl;
    // std::cout << Solution().divide(1, 1) << std::endl;
    return 0;
}
