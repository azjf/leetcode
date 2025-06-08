class Solution
{
public:
    int climbStairs(int n)
    {
        // dp[i] = dp[i - 1] + dp[i - 2]
        int pre = 1, ppre = 0;  // dp[-2] = 0, dp[-1] = 1, dp[0] = 1, dp[1] = 2
        for (int i = 0; i != n; ++i) {
            int cur = pre + ppre;
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};
