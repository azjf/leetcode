#include <iostream>
#include <ostream>
#include <vector>

class Solution
{
public:
    int removeDuplicates(std::vector<int> &nums)
    {
        decltype(nums.size()) l = 0;
        for (auto r = 1; r < nums.size(); ++r) {
            if (nums[r] != nums[l]) {
                nums[++l] = nums[r];
            }
        }
        return ++l;
    }
};

int main()
{
    Solution s;

    std::vector<int> nums{1, 1, 2};
    std::cout << s.removeDuplicates(nums) << std::endl;

    nums = {0, 0, 1, 1, 2, 2, 3, 3, 4};
    std::cout << s.removeDuplicates(nums) << std::endl;
    return 0;
}
