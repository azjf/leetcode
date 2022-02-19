#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        decltype(nums.size()) l = 0;
        for (decltype(nums.size()) r = 1; r < nums.size(); ++r) {
            if (nums[r] != nums[l]) {
                nums[++l] = nums[r];
            }
        }
        return l + 1;
    }
};
