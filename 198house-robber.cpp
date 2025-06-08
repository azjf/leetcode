#include <vector>


class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        int sz = nums.size();
        // dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])
        int pre = 0, ppre = 0;
        for (int n : nums) {
            int cur = std::max(n + ppre, pre);
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};


class Solution2
{
public:
    int rob(std::vector<int> &nums)
    {
        int sz = nums.size();
        int dp[sz + 2];
        dp[0] = dp[1] = 0;
        for (int i = 0; i != sz; ++i) {
            dp[i + 2] = std::max(nums[i] + dp[i], dp[i + 1]);
        }
        return dp[sz + 1];
    }
};
