#pragma once

#include <algorithm>
#include <limits>
#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        return recur(nums, 0, nums.size() - 1);
    }

    int recur(const std::vector<int> &nums, int l, int r)
    {
        if (l > r) {
            return std::numeric_limits<int>::min();
        }
        int mid = l + (r - l) / 2;
        int msum = nums[mid], sum = msum;
        for (int i = mid - 1; i >= l; --i) {
            sum += nums[i];
            msum = std::max(msum, sum);
        }
        sum = msum;
        for (int i = mid + 1; i <= r; ++i) {
            sum += nums[i];
            msum = std::max(msum, sum);
        }
        int lsum = recur(nums, l, mid - 1);
        int rsum = recur(nums, mid + 1, r);
        return std::max({msum, lsum, rsum});
    }
};
