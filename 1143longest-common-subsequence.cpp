#include <string>
#include <vector>

/*
 * 583 delete-operation-for-two-strings
 */
class Solution
{
public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        int m = text1.size(), n = text2.size();
        // dp[i][j] -> count of same chars between word1[0..i-1] and
        // word2[0..j-1]
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (text1[i] == text2[j]) {
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                } else {
                    dp[i + 1][j + 1] = std::max(dp[i][j + 1], dp[i + 1][j]);
                }
            }
        }
        return dp[m][n];
    }
};
