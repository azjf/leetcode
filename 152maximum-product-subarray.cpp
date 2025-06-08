#include <algorithm>
#include <vector>

/*
 * maxProd[i]/minProd[i]: the product of subarray end with nums[i]
 * maxProd[i] = max(nums[i], minProd[i - 1] * nums[i], maxProd[i - 1] * nums[i])
 * minProd[i] = min(nums[i], minProd[i - 1] * nums[i], maxProd[i - 1] * nums[i])
 * res = max(res, maxProd[i])
 */
class Solution
{
public:
    int maxProduct(std::vector<int> &nums)
    {
        int res = nums[0], maxProd = 1, minProd = 1;
        for (int i = 0; i != nums.size(); ++i) {
            int a = maxProd * nums[i], b = minProd * nums[i];
            maxProd = std::max({a, b, nums[i]});
            minProd = std::min({a, b, nums[i]});
            res = std::max(res, maxProd);
        }
        return res;
    }
};


int main()
{
    std::vector<int> nums{2, 3, -2, 4};
    nums = {-2, 0, -1};
    Solution().maxProduct(nums);
    return 0;
}
