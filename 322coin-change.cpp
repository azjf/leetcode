#include <algorithm>
#include <vector>


/*
 * dp[i] = min(dp[i - k] + 1)
 */
class Solution
{
public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::sort(coins.begin(), coins.end());
        std::vector<int> dp(amount + 1, amount + 2);  // i -> dp[i + 1]
        dp[0] = 0;
        for (int i = 1; i != amount + 1; ++i) {
            for (int j = 0; j != coins.size() && coins[j] <= i; ++j) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        return dp[amount] == amount + 2 ? -1 : dp[amount];
    }
};


int main()
{
    std::vector<int> coins{1, 2, 5};
    Solution().coinChange(coins, 11);
    return 0;
}
