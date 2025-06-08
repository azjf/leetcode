#include <algorithm>
#include <string>

class Solution
{
public:
    int minDistance(std::string word1, std::string word2)
    {
        int m = word1.size(), n = word2.size();
        int dp[m + 1]
              [n + 1];  // result for sub-word word1[0..i] and word2[0..j]

        for (int i = 0; i != m + 1; ++i) { dp[i][0] = i; }
        for (int j = 0; j != n + 1; ++j) { dp[0][j] = j; }

        // delete, replace
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    // the two word corresponding to dp[i][j] are always of
                    // the same length because word2 has already been
                    // manipulated to be the same as word1?
                    dp[i + 1][j + 1] =
                        1 + std::min({dp[i][j] /* delete ? */,
                                      dp[i + 1][j] /* replace(s1) */,
                                      dp[i][j + 1] /* replace(s2) ? */});
                }
            }
        }
        return dp[m][n];
    }
};
