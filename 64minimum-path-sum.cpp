#include <algorithm>
#include <vector>

/*
 * dp[i][j] = min(dp[i][j - 1], dp[i - 1][j]) + grid[i][j]
 */
class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        std::vector<int> dp(n + 1, 200 * 400);
        dp[1] = 0;  // dp[0] is a dummy number for min()
        for (int i = 0; i != m; ++i) {
            for (int j = 0; j != n; ++j) {
                dp[j + 1] =
                    std::min(dp[j + 1] /* previous pass */, dp[j]) + grid[i][j];
            }
        }
        return dp[n];
    }
};


int main()
{
    std::vector<std::vector<int>> grid{{1, 2, 3}, {4, 5, 6}};
    grid = {{1, 2}, {1, 1}};
    Solution().minPathSum(grid);
    return 0;
}
