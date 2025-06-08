#include <algorithm>
#include <vector>

class Solution
{
public:
    int findLongestChain(std::vector<std::vector<int>> &pairs)
    {
        std::sort(
            pairs.begin(), pairs.end(),
            [](const auto &lhs, const auto &rhs) { return lhs[0] < rhs[0]; });

        int sz = pairs.size();
        int dp[sz];  // dp[i]: max length of the chain ending with pairs[i]
        for (int i = 0; i != sz; ++i) {
            int max = 0;
            for (int j = 0; j != i; ++j) {
                if (pairs[j][1] < pairs[i][0] && dp[j] > max) { max = dp[j]; }
            }
            dp[i] = max + 1;
        }

        return *std::max_element(dp, dp + sz);
    }
};
