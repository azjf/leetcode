#include <vector>


/*
 * f(n) = max(i * f(n - i))
 */
class Solution
{
public:
    int integerBreak(int n)
    {
        // dp[i] -> i, and i < 2 will not be unused
        std::vector<int> dp(n + 1, 0);
        for (int i = 2; i != n + 1; ++i) {
            // dp[i] = max(j * max(dp[i - j], i - j) | 1 <= j < i)
            for (int j = 1; j != i; ++j) {
                // i = j + (i - j)
                dp[i] = std::max(dp[i], j * std::max(dp[i - j], i - j));
            }
        }
        return dp[n];
    }
};
