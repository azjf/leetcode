/*
 * There are more 5s than 2s, therefore the number of trailing zeroes is the
 * number of 5s in its quality factors f(n) = n/5 + n/5^2 + n/5^3 + ...
 */
class Solution
{
public:
    int trailingZeroes(int n)
    {
        int res = 0;
        while (n /= 5) {
            res += n;
        }
        return res;
    }
};
