#include <algorithm>
#include <numeric>
#include <vector>


class Solution
{
public:
    bool canPartition(std::vector<int> &nums)
    {
        int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum % 2) { return false; }
        sum /= 2;

        // dp[i] -> if exists \sum{nums[k]} == sum
        std::vector<bool> dp(sum + 1, false);
        dp[0] = true;
        for (int n : nums) {
            // iterating from sum to n so that n will only be used once for any
            // dp[i]
            for (int t = sum; t >= n; --t) { dp[t] = dp[t] || dp[t - n]; }
        }
        return dp[sum];
    }
};


class Solution2
{
public:
    bool canPartition(std::vector<int> &nums)
    {
        int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum % 2) { return false; }
        sum /= 2;

        std::vector<std::vector<bool>> dp(nums.size() + 1,
                                          std::vector<bool>(sum + 1, false));
        // dp[..][j] -> if exists \sum{nums[k]} == sum
        for (int i = 0; i != nums.size(); ++i) { dp[i][0] = true; }
        for (int i = 0; i != nums.size(); ++i) {
            for (int j = 0; j != sum + 1; ++j) {
                dp[i + 1][j] =
                    nums[i] <= j ? dp[i][j] || dp[i][j - nums[i]] : dp[i][j];
            }
        }
        return dp[nums.size()][sum];
    }
};


/*
 * timeout
 */
class Solution3
{
public:
    bool canPartition(std::vector<int> &nums)
    {
        int sum = std::accumulate(nums.cbegin(), nums.cend(), 0);
        if (sum % 2) { return false; }
        sum /= 2;
        return recur(nums, 0, sum, sum);
    }

private:
    bool recur(std::vector<int> &nums, int idx, int pickRemain,
               int discardRemain)
    {
        if (!pickRemain || !discardRemain) { return true; }
        if (pickRemain < 0 || discardRemain < 0 || idx >= nums.size()) {
            return false;
        }
        return recur(nums, idx + 1, pickRemain - nums[idx], discardRemain) ||
               recur(nums, idx + 1, pickRemain, discardRemain - nums[idx]);
    }
};
