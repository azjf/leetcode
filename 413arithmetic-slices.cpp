#include <numeric>
#include <vector>


class Solution
{
public:
    int numberOfArithmeticSlices(std::vector<int> &nums)
    {
        // dp[i]: number of arithmetic slices for nums[0..i]
        // dp[i] = dp[i - 1] + count(the arithmetic slices that end with nums[i]
        // of length >= 3, which equals to count of the numbers - 2)
        int res = 0;
        int delta = 0, cnt = 1;
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] - nums[i - 1] != delta) {
                delta = nums[i] - nums[i - 1];
                cnt = 1;
            }
            res += ++cnt - 2;
        }
        return res;
    }
};


class Solution2
{
public:
    int numberOfArithmeticSlices(std::vector<int> &nums)
    {
        int sz = nums.size();
        // dp[i]: number of arithmetic slices that ending with nums[i]
        std::vector<int> dp(sz, 0);
        for (int i = 2; i < nums.size(); ++i) {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                dp[i] = dp[i - 1] + 1;
            }
        }
        return std::accumulate(dp.cbegin(), dp.cend(), 0);
    }
};
