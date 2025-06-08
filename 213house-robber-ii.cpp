#include <vector>

class Solution
{
public:
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 1) { return nums[0]; }
        return std::max(rob(nums, 0, nums.size() - 1),
                        rob(nums, 1, nums.size()));
    }

private:
    int rob(const std::vector<int> &nums, int l, int r)  // [l, r)
    {
        int pre = 0, ppre = 0;
        for (int i = l; i != r; ++i) {
            int cur = std::max(nums[i] + ppre, pre);
            ppre = pre;
            pre = cur;
        }
        return pre;
    }
};
