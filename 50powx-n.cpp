#include <cmath>

/*
 * x^{2m} = (x^m)^2
 * x^{a + b} = x^a * x^b
 * n = \sum{a_i 2^i}
 */
class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0) {
            return 0;
        }

        bool posn = n > 0;
        unsigned un = posn ? n : -(long) n;

        double res = 1;
        while (un) {
            if (un & 1) {
                res *= x;
            }
            x *= x;
            un >>= 1;
        }
        return posn ? res : 1 / res;
    }
};


class Solution2
{
public:
    double myPow(double x, int n)
    {
        if (x == 0) {
            return 0;
        }

        bool posn = n > 0;
        unsigned un = posn ? n : -(long) n;
        double res = recur(x, n);
        return posn ? res : 1 / res;
    }

private:
    double recur(double x, int n)
    {
        if (n == 0) {
            return 1;
        }
        return recur(x * x, n / 2) * (n % 2 ? x : 1);
    }
};


int main()
{
    int a = -std::pow(2, 31);
    unsigned ua = std::abs(a);  // why not error?
    ua = std::abs((long) a);
    ua = -a;

    Solution().myPow(2, 10);
    Solution().myPow(2.1, 3);
    Solution().myPow(2, -2);
    return 0;
}
