#include <limits>
#include <vector>

class Solution
{
public:
    int change(int amount, std::vector<int> &coins)
    {
        std::vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                // iterating from coin to amount so that coin can be consumed
                // multi-times
                if (dp[i] > std::numeric_limits<int>::max() - dp[i - coin]) {
                    // The answer is guaranteed to fit into a signed 32-bit
                    // integer.
                    return 0;
                }
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};
