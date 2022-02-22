#pragma once

#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        return recur(nums.cbegin(), nums.cend());
    }

private:
    int recur(const std::vector<int>::const_iterator l,
            const std::vector<int>::const_iterator r)
    {
        if (l + 1 == r) {
            return *l;
        }

        auto mid = l + (r - l) / 2;
        int sum = *mid, msum = sum;
        for (auto it = mid - 1; it >= l; --it) {
            sum += *it;
            msum = std::max(msum, sum);
        }
        sum = msum;
        for (auto it = mid + 1; it < r; ++it) {
            sum += *it;
            msum = std::max(msum, sum);
        }
        int lsum = l == mid ? *l : recur(l, mid);
        int rsum = r == mid + 1 ? *mid : recur(mid + 1, r);
        return std::max({msum, lsum, rsum});
    }
};
