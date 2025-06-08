#include <vector>


/*
 * dp[i]: result for i
 * dp[i] = min(dp[i], 1 + dp[i - j * j])
 * f(i) = min(f(i - j * j)) + 1
 *
 * dp[i][j] (pack value): i (pack space), j (item)
 * dp[i][j] = min(dp[i][j - 1], 1 + dp[i - j * j][j])
 */
class Solution
{
public:
    int numSquares(int n)
    {
        std::vector<int> squares;
        int square = 1, diff = 3;
        while (square <= n) {
            // (n + 1)^2 = n^2 + (2n + 1) = n^2 + ((2(n - 1) + 1) + 2)
            squares.push_back(square);
            square += diff;
            diff += 2;
        }

        std::vector<int> dp(n + 1, n + 1);  // dp[i] -> i - 1
        dp[0] = 0;
        for (int i = 1; i != n + 1; ++i) {  // iterating by pack space (row)
            for (int s : squares) {
                if (s > i) { break; }
                dp[i] = std::min(dp[i], 1 + dp[i - s]);
            }
        }
        return dp[n];
    }
};


class Solution2
{
public:
    int numSquares(int n)
    {
        std::vector<int> dp(n + 1, n + 1);
        dp[0] = 0;
        for (int j = 1; j != n + 1; ++j) {  // iterating by item (column)
            for (int i = j * j; i < n + 1; ++i) {
                dp[i] = std::min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];
    }
};


int main()
{
    Solution2().numSquares(12);
    return 0;
}
