#include <map>
#include <vector>

/*
 * dp[i, j] = dp[i - 1, j] + dp[i, j - 1]
 * bottom up
 */
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        std::vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 0; i != m; ++i) {
            for (int j = 1; j != n; ++j) {  // dp[i, 0] == dp[i - 1, 0]
                dp[j] += dp[j - 1];         // dp[i - 1, j] -> dp[i, j]
            }
        }
        return dp[n - 1];
    }
};


/*
 * top down
 * f(i, j) = f(i - 1, j) + f(i, j - 1)
 * save f(i, j) to map to prevent unnecessary recuring
 */
class Solution2
{
public:
    int uniquePaths(int m, int n) { return recur(--m, --n); }

private:
    std::map<int, int> imap;

    int recur(int m, int n)  // m and n start with 0
    {
        if (!m || !n) {  // when reaching the down or right side, there are only
                         // one path
            return 1;
        }
        auto getKey = [](int m, int n) { return m << 7 | n; };
        int key = getKey(m, n);
        if (imap.count(key)) {
            return imap[key];
        }

        int res = recur(m - 1, n) + recur(m, n - 1);
        imap[getKey(m, n)] = res;
        return res;
    }
};


/*
 * We should move (m + n - 2) steps to reach the end. Before reaching down or
 * right side, there are (m + n - 2 - i) kinds of selection for each move. After
 * reaching, there are only one selection. So there are total of ~P_{m + n -
 * 2}^{min(m, n) - 1}~ kinds of unique paths
 */
class Solution3
{
public:
    int uniquePaths(int m, int n)
    {
        // P_{m + n - 2}^{min(m, n) - 1} = (m + n - 2)! / (min(m, n) - 1)!
        int min = std::min(m, n);
        long res = 1;
        for (int i = 1; i != min; ++i) {
            // integer division: divide from 1 to (min - 1) to avoid floor
            // rounding
            res = res * (m + n - 1 - i) / i;
        }
        return res;
    }
};


int main()
{
    Solution().uniquePaths(3, 2);
    Solution3().uniquePaths(5, 5);
    return 0;
}
