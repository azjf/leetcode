#include <vector>

class Solution
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int lo = 0, hi = 0, sum = 0, res = nums.size() + 1;
        for (int lo = 0, hi = 0; hi != nums.size();) {
            sum += nums[hi++];
            if (sum >= target) {  // [lo, hi) >= target
                // shrink [lo, hi)
                while (lo < hi && sum - nums[lo] >= target) {
                    sum -= nums[lo++];
                }
                res = std::min(res, hi - lo);
            }
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};


class Solution2
{
public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int lo = 0, hi = 0, sum = 0, res = nums.size() + 1;
        while (hi != nums.size()) {
            do {
                sum += nums[hi++];
            } while (hi != nums.size() && sum < target);  // [lo, hi) >= target
            if (sum < target) {
                break;
            }
            while (lo < hi && sum - nums[lo] >= target) {
                // shrink [lo, hi) by leftside
                sum -= nums[lo++];
            }
            res = std::min(res, hi - lo);
        }
        return res == nums.size() + 1 ? 0 : res;
    }
};


int main()
{
    std::vector<int> nums{1, 4, 4};
    Solution().minSubArrayLen(4, nums);
    return 0;
}
