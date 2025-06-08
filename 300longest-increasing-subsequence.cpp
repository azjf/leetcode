#include <algorithm>
#include <vector>

class Solution
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        int sz = nums.size();
        int dp[sz];  // dp[i] -> lengthOfLIS for nums[0..i]
        for (int i = 0; i != sz; ++i) {
            int max = 0;
            // dp[i] = 1 + max(dp[j] | nums[j] < nums[i], j < i)
            for (int j = 0; j != i; ++j) {
                if (nums[j] < nums[i] && dp[j] > max) { max = dp[j]; }
            }
            dp[i] = max + 1;
        }
        return *std::max_element(dp, dp + sz);
    }
};


/*
 * to maximize lengthOfLIS, the subsequence should rise as slowly as possible
 */
class Solution2
{
public:
    int lengthOfLIS(std::vector<int> &nums)
    {
        int sz = nums.size();
        std::vector<int> tails(sz, 0);
        int len = 0;  // tails[0..len) is sorted, and len is the max length of
                      // the sorted subsequence
        for (int n : nums) {
            int idx = binarySearch(tails, len, n);
            tails[idx] = n;
            // if idx < len, there is no need to shrink len to idx + 1, because
            // len is the max length.
            //
            // if idxOld + 1 < idx(nums[i + 1]) < len, then idxOld has no impact
            // on nums[i + 1]. idxOld only maters when tails[idxOld + 1, len)
            // are all replaced by new numbers.
            if (idx == len) { ++len; }
        }
        return len;
    }

private:
    /*
     * if num > nums[..], then return loRes = hi = len
     * if num < nums[..], then return lo = 0
     * if nums[i] < num < nums[i + 1] (same as nums[hi - 1] < num < nums[hi] =
     * \infinity), then return i + 1
     */
    int binarySearch(const std::vector<int> &nums, int len, int num)
    {
        int lo = 0, hi = len;  // [lo, hi)
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] > num) {
                hi = mid;
            } else if (nums[mid] < num) {
                lo = mid + 1;
            } else {
                return mid;
            }
        }
        return lo;
    }
};
