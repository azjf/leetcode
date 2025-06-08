#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        int l = 0;  // [0, l) is the result array
        for (int r = l; r < nums.size(); ++r) {
            if (l < 2 || nums[r] != nums[l - 2]) {
                // if nums[r] == nums[l - 2], then nums[r] is ignored
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};
