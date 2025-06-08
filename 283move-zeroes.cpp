#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        decltype(nums.size()) l = 0, r = 0;
        for (; r != nums.size(); ++r) {
            if (nums[r]) {
                nums[l++] = nums[r];
            }
        }
        while (l != nums.size()) {
            nums[l++] = 0;
        }
    }
};

class Solution2
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        for (decltype(nums.size()) l = 0, r = 0; r != nums.size(); ++r) {
            auto tmp = nums[r];
            if (tmp) {
                // std::swap(nums[l++], nums[r]);  // 10 ms cost! Does it may be
                // fixed by making std::swap() inlined?
                nums[r] = nums[l];
                nums[l++] = tmp;
            }
        }
    }
};
