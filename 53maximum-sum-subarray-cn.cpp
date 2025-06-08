#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        return recur(nums.cbegin(), nums.cend());
    }

private:
    int recur(std::vector<int>::const_iterator l,
              std::vector<int>::const_iterator r)
    {
        if (l + 1 == r) {
            return *l;
        }

        auto m = l + (r - l) / 2;
        int msum = *m, sum = msum;
        for (auto p = m - 1; p >= l; --p) {
            sum += *p;
            msum = std::max(sum, msum);
        }
        sum = msum;
        for (auto p = m + 1; p < r; ++p) {
            sum += *p;
            msum = std::max(sum, msum);
        }

        int lsum = l == m ? *l : recur(l, m);
        int rsum = r == m + 1 ? *m : recur(m + 1, r);
        return std::max({msum, lsum, rsum});
    }
};

class Solution2
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        return recur(nums.cbegin(), nums.cend());
    }

private:
    int recur(std::vector<int>::const_iterator l,
              std::vector<int>::const_iterator r)
    {
        if (l >= r) {
            return std::numeric_limits<int>::min();
        }

        auto m = l + (r - l) / 2;
        int msum = *m, sum = msum;
        for (auto p = m - 1; p >= l; --p) {
            sum += *p;
            msum = std::max(sum, msum);
        }
        sum = msum;
        for (auto p = m + 1; p < r; ++p) {
            sum += *p;
            msum = std::max(sum, msum);
        }

        int lsum = recur(l, m);
        int rsum = recur(m + 1, r);
        return std::max({msum, lsum, rsum});
    }
};

class Solution3
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        if (nums.empty()) {
            return -1;
        }
        int sum = 0, minsum = 0, result = nums[0];
        for (int n : nums) {
            sum += n;
            result = std::max(result, sum - minsum);
            minsum = std::min(minsum, sum);
        }
        return result;
    }
};

class Solution4
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        if (nums.empty()) {
            return -1;
        }
        // dp[i] = max(dp[i - 1] + nums[i], nums[i]). dp[i] is the maxSubArray
        // that ends with nums[i] (the global maxSubArray must be one of them)
        // result = max(dp[i])
        int pre = 0, cur = nums[0];
        for (int n : nums) {
            pre = std::max(pre + n, n);
            cur = std::max(cur, pre);
        }
        return cur;
    }
};

int main()
{
    Solution4 s;

    std::vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << s.maxSubArray(nums) << std::endl;

    nums = {1};
    std::cout << s.maxSubArray(nums) << std::endl;

    nums = {5, 4, -1, 7, 8};
    std::cout << s.maxSubArray(nums) << std::endl;
}
