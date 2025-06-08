#include <string>
#include <vector>

/*
 * 2D pack problem
 */
class Solution
{
public:
    int findMaxForm(std::vector<std::string> &strs, int m, int n)
    {
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        // dp[i][j][k] = max(dp[i - 1][j][k], 1 + dp[i - 1][j - n0][k - n1])
        for (const auto &str : strs) {
            int n0 = 0, n1 = 0;
            for (char c : str) {
                if (c == '0') { ++n0; }
            }
            n1 = str.size() - n0;
            // iterating from m to n0 so that dp[i - 1][<j][<k] is used
            for (int j = m; j >= n0; --j) {
                for (int k = n; k >= n1; --k) {
                    dp[j][k] = std::max(dp[j][k], 1 + dp[j - n0][k - n1]);
                }
            }
        }
        return dp[m][n];
    }
};
