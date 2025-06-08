#include <cstring>
#include <memory>
#include <vector>

class Solution
{
public:
    int distMoney(int money, int children)
    {
        if (money < children) {
            return -1;
        }
        money -= children;
        int res = std::min(money / 7, children);
        money -= res * 7;
        children -= res;
        if (!children && money || children == 1 && money == 3) {
            --res;
        }
        return res;
    }
};

class Solution2
{
public:
    int distMoney(int money, int children)
    {
        // dp[i][j]: i - 1 moeny, j - 1 children
        // dp[i][j] = max(dp[i][j], dp[i - k][j - 1] + (k == 8))
        std::vector<std::vector<int>> dp(
            money + 1,
            std::vector<int>(children + 1, -100));  // 2 <= children <= 30
        dp[0][0] = 0;
        for (int i = 1; i != money + 1; ++i) {
            for (int j = 1; j != children + 1; ++j) {
                for (int k = 1; k != i + 1; ++k) {  // why not ~k != i~
                    if (k == 4) {                   // why ?
                        continue;
                    }
                    dp[i][j] = std::max(dp[i][j], dp[i - k][j - 1] + (k == 8));
                }
            }
        }
        return dp[money][children] < 0 ? -1 : dp[money][children];
    }
};
