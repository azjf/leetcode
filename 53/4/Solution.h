#include <vector>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        if (nums.empty()) {
            return -1;
        }
        int max_sum = nums[0], result = max_sum;
        for (decltype(nums.size()) i = 1; i != nums.size(); ++i) {
            max_sum = std::max(max_sum + nums[i], nums[i]);
            result = std::max(result, max_sum);
        }
        return result;
    }
};
