#include <algorithm>
#include <vector>


class Solution
{
public:
    int maximalSquare(std::vector<std::vector<char>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        int maxLen = 0;
        // dp[i][j] -> max square length for matrix[i - 1][j - 1]
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                dp[i + 1][j + 1] = matrix[i][j] == '0'
                                       ? 0
                                       : (1 + std::min({dp[i][j], dp[i][j + 1],
                                                        dp[i + 1][j]}));
                maxLen = std::max(maxLen, dp[i + 1][j + 1]);
            }
        }
        return maxLen * maxLen;
    }
};
