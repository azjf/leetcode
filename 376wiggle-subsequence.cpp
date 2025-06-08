#include <vector>


class Solution
{
public:
    int wiggleMaxLength(std::vector<int> &nums)
    {
        int up = 1, down = 1;
        for (int i = 1; i != nums.size(); ++i) {
            if (nums[i] > nums[i - 1]) {
                // up = std::max(up, down + 1)
                up = down + 1;  // ?
            } else if (nums[i] < nums[i - 1]) {
                // down = std::max(down, up + 1)
                down = up + 1;  // ?
            }
        }
        return std::max(up, down);
    }
};
