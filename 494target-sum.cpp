#include <numeric>
#include <vector>

class Solution
{
public:
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        // 2 \times sum(P) = target + sum = (sum(P) - sum(N)) + (sum(P) +
        // sum(N))
        int sum = std::accumulate(nums.cbegin(), nums.cend(), 0) + target;
        if (sum < 0 || sum % 2) { return 0; }
        sum /= 2;

        std::vector<int> dp(sum + 1, 0);
        dp[0] = 1;
        for (int n : nums) {
            for (int i = sum; i >= n; --i) {
                // iterating from sum to n so that n will only be consumed once
                dp[i] += dp[i - n];
            }
        }
        return dp[sum];
    }
};


class Solution2
{
public:
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        return recur(nums, target, 0);
    }

private:
    int recur(std::vector<int> &nums, int target, int lo)
    {
        if (lo == nums.size()) { return target == 0; }
        return recur(nums, target + nums[lo], lo + 1) +
               recur(nums, target - nums[lo], lo + 1);
    }
};
