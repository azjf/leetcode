#include <cmath>


class Solution
{
public:
    int minSteps(int n) { return n == 1 ? 0 : recur(n); }

private:
    int recur(int n)
    {
        for (int i = 2; i <= std::sqrt(n); ++i) {
            if (!(n % i)) {
                return i + recur(n / i);  // copy (1) + paste (i - 1)
            }
        }
        return n;  // copy (1) + paste (n - 1)
    }
};


class Solution2
{
public:
    int minSteps(int n)
    {
        // not so efficient as the recursion method because of so many
        // computations for unnecessary dp[..]
        int dp[n + 1];  // dp[i] -> i
        dp[1] = 0;
        for (int i = 2; i != n + 1; ++i) {
            dp[i] = i;
            for (int j = 2; j < i; ++j) {
                if (!(i % j)) {
                    dp[i] = dp[i / j] + j;  // copy (1) + paste (j - 1)
                    break;
                }
            }
        }
        return dp[n];
    }
};


int main()
{
    Solution().minSteps(6);
    return 0;
}
