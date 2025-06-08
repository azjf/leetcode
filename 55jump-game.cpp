#include <vector>

class Solution
{
public:
    bool canJump(std::vector<int> &nums)
    {
        for (int farthest = 0, i = 0; i <= farthest; ++i) {
            int cur = i + nums[i];
            if (cur > farthest) {
                farthest = cur;
            }
            if (farthest >= nums.size() - 1) {
                return true;
            }
        }
        return false;
    }
};

int main()
{
    std::vector<int> nums{3, 2, 1, 0, 4};
    Solution().canJump(nums);
    return 0;
}
