#include <string>
#include <vector>

class Solution
{
public:
    int minDistance(std::string word1, std::string word2)
    {
        int m = word1.size(), n = word2.size();
        // dp[i][j] -> count of same chars between word1[0..i-1] and
        // word2[0..j-1]
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return m + n - 2 * dp[m][n];
    }
};
