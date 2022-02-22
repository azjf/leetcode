#pragma once

#include <vector>
#include <limits>
#include <algorithm>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        if (nums.empty()) {
            return -1;
        }
        int sum = 0, min_sum = 0, result = nums[0];
        for (decltype(nums.size()) i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            result = std::max(result, sum - min_sum);
            min_sum = std::min(min_sum, sum);
        }
        return result;
    }

    int recur(const std::vector<int> &nums, int l, int r) {
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
